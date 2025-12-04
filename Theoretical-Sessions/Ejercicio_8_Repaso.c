#include <stdio.h>
#include <stdbool.h>

void leer_numero(int* n){
    printf("Introduzca un número entero positivo: ");
        scanf(" %d", n);
}

bool is_prime(int n){
    bool primo = (n > 1);
    int div = 2;

    while((div <= n/2) && primo){
        if(n%div!=0)
        {
            primo = true;
        }else
            {
                primo = false;
            }
        div++;
    }
    return primo;
}

int main(){
    int n;
    leer_numero(&n);

    bool primo = is_prime(n);

    if(primo)
    {
        printf("El número %d es primo\n", n);
    }else
        {
            printf("El número %d no es primo\n", n);
        }
}
