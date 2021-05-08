#include<stdio.h>
#include<stdlib.h>

void main()
{
    int n, i, resul=1;
    printf("Digite seu numero: ");
    scanf("%i", &n);

    for(i=n; i>1; i--)
    {
        resul=resul*i;
    }
    printf("O fatorial do numero %i e igual a: %i", n, resul);
}
