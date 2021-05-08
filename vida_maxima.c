#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


/** JOGO DOS QUARTOS DA VIDA **/
/**
Neste jogo cada quarto possui um n�mero de vidas.
O objetivo do programa � calcular qual o m�ximo de vidas poss�veis a se conseguir

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
//BIBLIOTECA PARA ACENTUA��O//////
setlocale(LC_ALL, "Portuguese");
//////////////////////////////////
    int num, i;
    printf("BEM VINDO:\n\nRESTRI��ES DO JOGO:\n1-O n�mero de quartos deve estar entre 1 e 50000.\n2-O n�mero de vidas em cada quarto deve estar entre -100 e 100.\n3- E necess�rio que pelo menos 1 quarto tenha um n�mero positivo de vidas.\nTenha um bom jogo!.\n\n");

    printf("Digite o n�mero de quartos: ");
    scanf("%i", &num);
    if (num<1 || num>50000)
        printf("\nALERTA: N�mero de quartos inv�lidos. Por favor releia as restri��es.\n\n");
    else
    {
        int corredor[num], maior, neg=0;

        for (i=0; i<num; i++)
        {
            printf("Digite o valor de vidas do quarto n�mero %i: ", i+1);
            scanf("%i", &corredor[i]);
            if (corredor[i]<-100 || corredor[i]>100)
            {
                printf("\nALERTA: Valor de vidas inv�lido. Por favor releia as intru��es.\n\n");
                i--;
            }
            if(corredor[i]<=0)
            {
                neg++;
                if(neg==num)
                {
                    printf("\nALETRA: � necess�rio pelo menos 1 quarto com o n�mero de vidas positivo. Por favor releia as instru��es.\n\n");
                    i--;
                }
            }
        }

        maior=calculo(num, corredor);
        printf("\nO n�mero m�ximo de vidas que voc� pode conseguir � de: %i", maior);
    }
}
