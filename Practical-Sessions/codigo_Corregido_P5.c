#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* data;
    int size;
} Recurso;

Recurso* inicializar_recurso(char* data_input) {
    Recurso* nuevo = (Recurso*)malloc(sizeof(Recurso));

    if(nuevo != NULL){ // Compruebo que nuevo no devuelva null
    int size = 16;
    nuevo->data = (char*)malloc(size*sizeof(char)); // Hay que multiplicar por el tipo de elemento
    if(nuevo->data != NULL){ // Compruebo que data no sea null
    nuevo->size = size;

    strncpy(nuevo->data, data_input, size);

    printf("Recurso inicializado (Tamaño: %d)\n", size);
    }else{
        nuevo->data = NULL;
        nuevo->size = NULL;
        free(nuevo);
        nuevo = NULL;
    }
    }

    return nuevo;
}

void redimensionar_recurso(Recurso* r, int new_size) {
    char* new_data = (char*)realloc(r->data, new_size);
    if(new_data != NULL){
        if(new_size > 128){
    r->data = new_data;
    r->size = new_size;

    printf("Recurso redimensionado (Nuevo tamaño: %d)\n", new_size);
        }else{
            printf("New_size excede el tamaño\n");
        }
    }
}


void liberar_recurso(Recurso* r) {
    free(r->data);
    free(r);
}

int main() {
    char input[128];
    printf("Introduce los datos iniciales (max 127 caracteres): ");

    if (!fgets(input, 128, stdin)) {
        printf("Error al leer la entrada\n");
        return 1;
    }
    input[strcspn(input, "\n")] = 0; // Eliminar salto de línea

    Recurso* r1 = inicializar_recurso(input);
    if (r1 != NULL){

    printf("Datos: %s\n", r1->data);

    redimensionar_recurso(r1, 1024 * 1024 * 1024 * 5);

    printf("Primer byte tras redimensionar: %c\n", r1->data[0]);

    liberar_recurso(r1);
    }

    return 0;
}
