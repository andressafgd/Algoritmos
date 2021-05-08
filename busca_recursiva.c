#include <stdio.h>
#include <stdlib.h>
/** Realiza uma busca recursiva num vetor de 10 itens**/

int buscamaior(int V[],int i,int maior)
{
    if(V[i]>maior)
        maior=V[i];
    if(i==0)
        return maior;
    return buscamaior(V,i-1,maior);
}
void main()
{
    int V[10],num, maior,i;
    printf("Busca recursiva do maior número em um vetor de 10 itens.\n");

    for(i=0;i<10;i++)
    {
        printf("[%d] ",i+1);
        scanf("%d",&V[i]);
    }
    i=9;
    printf("%d",buscamaior(V,i,0));
}
