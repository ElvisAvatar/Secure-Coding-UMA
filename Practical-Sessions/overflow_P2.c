/* vuln_pin.c
 * Ejercicio: encontrar y explicar un buffer overflow en pila usando GDB (comando 'x').
 * NO introducir otras vulnerabilidades (p. ej. format strings, punteros a funciones, etc.).
 *
 * Compilar con: make debug
 */

#include <stdio.h>
#include <string.h>

int is_pin_valid(const char *input)
{
    char qfoo[4];
    char q0[4];
    int qbar = 0;
    char qbaz;

    while ((qbaz = *input++) != '\0') {
        qfoo[qbar++] = qbaz;
    }
    qfoo[qbar] = '\0';

    strcpy(q0, qfoo);

    if (strcmp(q0, "1234") == 0)
        return 1;
    return 0;
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <PIN>\n", argv[0]);
        return 1;
    }

    puts("Validando PIN...");
    if (is_pin_valid(argv[1])) {
        puts("PIN CORRECTO - Acceso permitido");
        return 0;
    } else {
        puts("PIN INCORRECTO - Acceso denegado");
        return 2;
    }
}