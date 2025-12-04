#include <stdio.h>
#include <string.h>

void funcion_secreta() {
    printf("¡ACCESO CONCEDIDO! Has ejecutado la función secreta.\n");
}

void funcion_vulnerable() {
    int var1=1234;
    char buffer[64];
    char var2[10] = "mensaje";
    float var3=1.5f;

    printf("var1 (entero): %d\nvar2 (cadena): %s\nvar3 (flotante): %.2f\n", var1, var2, var3);
    printf("\nIngrese su nombre: ");
    
    gets(buffer);
    
    printf("Hola, %s\n", buffer);
}

int main() {
    funcion_vulnerable();
    printf("Programa terminado normalmente.\n");
    return 0;
}