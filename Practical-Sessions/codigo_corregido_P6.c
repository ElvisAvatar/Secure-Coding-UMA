#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define PRECIO_POR_TOKEN 100000
#define VOLUMEN_POR_TOKEN 3
#define LIMITE_VOLUMEN_MAX 20000

// Saldo del usuario (Simulamos una BBDD)
int saldo_usuario = 100; 

void realizar_compra(int cantidad) {
    printf("\n--- Iniciando Transaccion ---\n");
    printf("Saldo actual: %d creditos\n", saldo_usuario);
    printf("Intentando comprar %d tokens...\n", cantidad);

    // 1. Validación básica
    if (cantidad <= 0) {
        printf("[ERROR] La cantidad debe ser positiva.\n");
        return;
    }

    // 2. Control de Seguridad: Verificación de Volumen
    long volumen_transaccion = cantidad * VOLUMEN_POR_TOKEN; //Cambio el tipo a long

    printf("[AUDITORIA] Volumen calculado (int): %d unidades\n", volumen_transaccion);

    if (volumen_transaccion > LIMITE_VOLUMEN_MAX) {
        printf("[ALERTA] Transaccion bloqueada por superar el limite de volumen.\n");
        return;
    }

    // 3. Cálculo del Coste
    long coste_total = cantidad * PRECIO_POR_TOKEN; // cambio tipo a long

    if(coste_total < 0){ // Compruebo que no se ha superado el límite de long
        printf("[ERROR] Se ha superado el límite permitido.\n");
        return;
    }

    printf("[CAJA] Coste total calculado (int): %d creditos\n", coste_total);

    // 4. Verificación de fondos
    if (saldo_usuario >= coste_total) {
        saldo_usuario = saldo_usuario - coste_total;
        printf("\n[EXITO] Compra realizada.\n");
        printf("[INFO] Nuevo saldo: %d creditos.\n", saldo_usuario);
        
        if (saldo_usuario > 100) {
            printf("[!!!] HACK DETECTADO: Has aumentado tu saldo comprando.\n");
        }   
    } else {
        printf("[ERROR] Fondos insuficientes. Te faltan %d creditos.\n", (coste_total - saldo_usuario));
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <cantidad_tokens>\n", argv[0]);
        return 1;
    }

    int tokens = atoi(argv[1]);
    realizar_compra(tokens);

    return 0;
}