#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void qfoo(int *qbar, int q0)
{
    int q1;
    for (q1 = 0; q1 <= q0; q1++)
    {
        printf("%d ", qbar[q1]);
    }
    printf("\n");
}
int *qbaz(int q0)
{
    int q1;
    int *qbar = (int *)malloc(q0 * sizeof(int));
    for (q1 = 0; q1 < q0; q1++)
    {
        qbar[q1] = rand() % 100;
    }
    return qbar;
}
int main()
{
    srand(time(NULL));
    int q0;
    printf("Ingrese el tamaño del Array: ");
    scanf("%d", &q0);
    int *qfobar = qbaz(q0);
    qfoo(qfobar, q0);
    free(qfobar);
    return 0;
}
