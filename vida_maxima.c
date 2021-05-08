#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


/** JOGO DOS QUARTOS DA VIDA **/
/**
Neste jogo cada quarto possui um número de vidas.
O objetivo do programa é calcular qual o máximo de vidas possíveis a se conseguir

**/

int calculo(int num, int *corredor)
{
    int i, maior=0, soma=0, cont;

    for (cont=0; cont<num; cont++)
    {
        i=cont;
        do{
            soma=soma+corredor[i];
            if (soma>maior)
                maior=soma;
            i++;
        }while(i<num);
        soma=0;
    }
    return maior;
}

int main()
{
//BIBLIOTECA PARA ACENTUAÇÃO//////
setlocale(LC_ALL, "Portuguese");
//////////////////////////////////
    int num, i;
    printf("BEM VINDO:\n\nRESTRIÇÕES DO JOGO:\n1-O número de quartos deve estar entre 1 e 50000.\n2-O número de vidas em cada quarto deve estar entre -100 e 100.\n3- E necessário que pelo menos 1 quarto tenha um número positivo de vidas.\nTenha um bom jogo!.\n\n");

    printf("Digite o número de quartos: ");
    scanf("%i", &num);
    if (num<1 || num>50000)
        printf("\nALERTA: Número de quartos inválidos. Por favor releia as restrições.\n\n");
    else
    {
        int corredor[num], maior, neg=0;

        for (i=0; i<num; i++)
        {
            printf("Digite o valor de vidas do quarto número %i: ", i+1);
            scanf("%i", &corredor[i]);
            if (corredor[i]<-100 || corredor[i]>100)
            {
                printf("\nALERTA: Valor de vidas inválido. Por favor releia as intruções.\n\n");
                i--;
            }
            if(corredor[i]<=0)
            {
                neg++;
                if(neg==num)
                {
                    printf("\nALETRA: É necessário pelo menos 1 quarto com o número de vidas positivo. Por favor releia as instruções.\n\n");
                    i--;
                }
            }
        }

        maior=calculo(num, corredor);
        printf("\nO número máximo de vidas que você pode conseguir é de: %i", maior);
    }
}
