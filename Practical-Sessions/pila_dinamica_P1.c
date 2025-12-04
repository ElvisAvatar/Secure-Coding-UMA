// pila_dinamica.c
// NO MODIFICAR LA FUNCION main()

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

// --- Definicion de la estructura ---
typedef struct {
    float *elementos;
    int tamano;       // Numero actual de elementos en la pila
    int capacidad;
} PilaFloat;

// --- Prototipos de las funciones a implementar ---

PilaFloat* crear_pila(int capacidad);
void liberar_pila(PilaFloat *p);
void apilar(PilaFloat *p, float elemento); // Equivalente a "push"
float desapilar(PilaFloat *p);             // Equivalente a "pop"

// --- ZONA DE IMPLEMENTACION DEL ALUMNO ---

PilaFloat* crear_pila(int capacidad){

	PilaFloat *p = (PilaFloat*)malloc(sizeof(PilaFloat));
	if(p != NULL){
		if(capacidad > 0){
			p->capacidad = capacidad;
			p->tamano = 0;
			p->elementos = (float*)malloc(p->capacidad*sizeof(float));
			if(p->elementos == NULL){
				free(p);
				p->elementos = NULL;
				return NULL;
			}
		}else{
			return NULL;
		}
	}
	return p;
}

void liberar_pila(PilaFloat *p){
	if(p != NULL){
		if(p->elementos != NULL){
			free(p->elementos);
			p->elementos = NULL;
		}
		free(p);
		p = NULL;
	}
}

void apilar(PilaFloat *p, float elemento){
	if(p != NULL && (p->tamano < p->capacidad)){
		p->elementos[p->tamano] = elemento;
		p->tamano+=1;
	}
}

float desapilar(PilaFloat *p){
	float elem = 0;
	if(p != NULL && p->tamano > 0){
		elem = p->elementos[p->tamano-1]; 
		p->elementos[p->tamano-1] = 0;
		p->tamano-=1;
	}	
	return elem;
}

// --- TEST SUITE - NO MODIFICAR ESTA FUNCION! ---

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    printf("--- Iniciando Tests de Pila Dinamica ---\n");

    // Test 1: Creacion de la pila
    PilaFloat *pila = crear_pila(5);
    if (pila == NULL || pila->tamano != 0 || pila->capacidad != 5) {
        printf("TEST 1 FALLIDO: La pila no se creo correctamente.\n"); return 1;
    }
    printf("TEST 1 SUPERADO: Pila creada correctamente.\n");

    // Test 2: Apilar elementos y comprobar tamano
    apilar(pila, 10.0f);
    apilar(pila, 20.0f);
    apilar(pila, 30.0f);
    if (pila->tamano != 3) {
        printf("TEST 2 FALLIDO: El tamano de la pila es incorrecto despues de apilar.\n"); return 1;
    }
    printf("TEST 2 SUPERADO: Elementos apilados y tamano correcto.\n");
    
    // Test 3: Desapilar en orden LIFO correcto
    float v1 = desapilar(pila); // Deberia ser 30.0
    float v2 = desapilar(pila); // Deberia ser 20.0
    float v3 = desapilar(pila); // Deberia ser 10.0
    if (fabs(v1 - 30.0f) > 0.001 || fabs(v2 - 20.0f) > 0.001 || fabs(v3 - 10.0f) > 0.001) {
        printf("TEST 3 FALLIDO: El orden LIFO al desapilar es incorrecto.\n"); return 1;
    }
    printf("TEST 3 SUPERADO: El orden LIFO es correcto.\n");
    
    // Test 4: Tamano de la pila tras vaciarla
    if (pila->tamano != 0) {
        printf("TEST 4 FALLIDO: El tamano de la pila deberia ser 0 despues de vaciarla.\n"); return 1;
    }
    printf("TEST 4 SUPERADO: El tamano de la pila vacia es correcto.\n");

    liberar_pila(pila);

    printf("\n--- Iniciando Tests de Robustez ---\n");

    // Test 5: Desapilar de una pila vacia
    PilaFloat *pila_vacia = crear_pila(3);
    float valor_vacio = desapilar(pila_vacia);
    if (fabs(valor_vacio - 0.0f) > 0.001 || pila_vacia->tamano != 0) {
         printf("TEST 5 FALLIDO: Desapilar de una pila vacia no devolvio 0.0 o modifico el tamano.\n"); return 1;
    }
    printf("TEST 5 SUPERADO: Desapilar de pila vacia se maneja correctamente.\n");
    liberar_pila(pila_vacia);
    
    // Test 6: Apilar en una pila llena
    PilaFloat *pila_llena = crear_pila(2);
    apilar(pila_llena, 1.0f);
    apilar(pila_llena, 2.0f);
    apilar(pila_llena, 3.0f); // Este no deberia entrar
    if (pila_llena->tamano != 2) {
        printf("TEST 6 FALLIDO: Apilar en una pila llena modifico el tamano incorrectamente.\n"); return 1;
    }
    printf("TEST 6 SUPERADO: Apilar en pila llena se maneja correctamente.\n");
    liberar_pila(pila_llena);

    // Test 7: Operaciones con puntero NULL
    liberar_pila(NULL);
    apilar(NULL, 1.0f);
    if (fabs(desapilar(NULL) - 0.0f) > 0.001) {
         printf("TEST 7 FALLIDO: desapilar(NULL) no devolvio 0.0.\n"); return 1;
    }
    printf("TEST 7 SUPERADO: Las funciones manejan punteros NULL sin fallar.\n");

    printf("\nTODOS LOS TESTS HAN SIDO SUPERADOS!\n");
    return 0;
}
