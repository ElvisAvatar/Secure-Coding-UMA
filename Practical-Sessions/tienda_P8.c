#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Recurso compartido: Inventario global
unsigned int stock_disponible = 3; 
unsigned int productos_vendidos = 0;

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Inicializamos mutex, que nos servirá para
                                                          // crear una especie de embudo para los hilos

void* comprar_producto(void* arg) {
    pthread_mutex_lock(&mutex); // Dejo que pase sólamente un hilo a la vez
    int id_cliente = *(int*)arg;

    // [CHECK] Paso 1: Comprobar si hay stock
    if (stock_disponible > 0) {
        
        // Simulamos latencia (Procesamiento de pago, DB).
        usleep(100000); // 0.1 segundos

        // [ACT] Paso 2: Decrementar stock (Cambio de estado)
        stock_disponible--; // El problema está en que hay que dejar entrar sólo un hilo a la vez
        productos_vendidos++;
        printf("Cliente %d: ¡Compra realizada! (Stock restante: %d)\n", id_cliente, stock_disponible);
        // Ventana de carrera entre líneas 18 y 23
    } else {
        printf("Cliente %d: Fallo. Sin stock.\n", id_cliente);
    }
    pthread_mutex_unlock(&mutex); // Desbloqueo al siguiente hilo que estuviera esperando más arriba
    return NULL;
}

int main() {
    pthread_t clientes[10];
    int ids[10];
    
    unsigned int stock_inicial = stock_disponible;

    printf("--- TIENDA ABIERTA (Stock inicial: %d) ---\n", stock_inicial);

    // Lanzamos 10 flujos concurrentes
    for (int i = 0; i < 10; i++) {
        ids[i] = i;
        if (pthread_create(&clientes[i], NULL, comprar_producto, &ids[i]) != 0) {
            perror("Error creando hilo");
        }
    }

    for (int i = 0; i < 10; i++) {
        pthread_join(clientes[i], NULL);
    }

    printf("\n--- AUDITORÍA FINAL ---\n");
    printf("Stock final: %d\n", stock_disponible);
    printf("Ventas totales: %d\n", productos_vendidos);

    if (productos_vendidos > stock_inicial) {
        printf("[!] CRITICAL: Race Condition Explotada. Inconsistencia financiera.\n");
    }

    return 0;
}
