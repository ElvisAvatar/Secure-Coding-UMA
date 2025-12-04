#include <stdio.h>
#include <stdlib.h>

int** crear_matriz(int filas, int columnas){
	if(filas > 0 && columnas > 0){
		int** m = (int**)malloc(sizeof(int*)*filas);
		if(m == NULL){
			free(m);
			m = NULL;
			return NULL;
		}else{
			for(int i = 0; i < filas; i++){
				m[i] = (int*)malloc(sizeof(int)*columnas);
				if(m[i]==NULL){
					free(m);
					return NULL;
				}
			}
			return m;
		}
	}
}

void llenar_matriz(int** matriz, int filas, int columnas){
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < columnas; j++){
			matriz[i][j] = (i*columnas)+j+1;
		}
	}
}

void imprimir_matriz(int** matriz, int filas, int columnas){
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < columnas; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}

void liberar_matriz(int** matriz, int filas){
	for(int i = 0; i < filas; i++){
		free(matriz[i]);
	}
	free(matriz);
}

int main(void){
	int filas, columnas;
	printf("Introduzca número de filas y columnas: ");
		scanf("%d %d", &filas, &columnas);
	int** matriz = crear_matriz(filas, columnas);
	if(matriz != NULL){
		printf("Creación exitosa!\n");
		llenar_matriz(matriz, filas, columnas);
		imprimir_matriz(matriz, filas, columnas);
		liberar_matriz(matriz, filas);
	}else{
		printf("La matriz no se creó correctamente\n");
	}

}
