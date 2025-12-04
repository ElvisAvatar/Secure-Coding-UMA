#include <stdio.h>
#include <stdlib.h>
#include <time.h>
static void qfoo(int *qbar, int q0) // Con static no se puede ejecutar la funcion fuera del propio archivo
{
    int q1;
    for (q1 = 0; q1 < q0; q1++)
    {
        printf("%d ", qbar[q1]);
    }
    printf("\n");
}
static int *qbaz(int q0)
{
    int q1;
    int *qbar = (int *)malloc(q0 * sizeof(int));
    if(qbar!=NULL){
    	for (q1 = 0; q1 < q0; q1++)
    	{
        	qbar[q1] = rand() % 100;
    	}
    }
    return qbar;
}
int main()
{
    srand(time(NULL));
    int q0;
    printf("Ingrese el tamaño del Array: ");
    if(scanf("%d", &q0)!=1){ // Comprobamos que se introduce el valor correcto
	return 0;
	}
    int *qfobar = qbaz(q0);
    qfoo(qfobar, q0);
    free(qfobar); // Quitamos el free de sobra
    return 0;
}
