#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/**JOGO DA SENHA**/
/** O objetivo do jogo é descobrir qual é a senha secreta
há tres modos: TESTE, FACIL, DIFICIL
O modo teste serve para você testar o programa, já que a senha é mostrada no inicio
O modo fácil lhe da uma senha de 3 caracteres
O modo díficil lhe da uma senha de 4 caracteres
se divirta tentando descobrir quais são os números e quais posições são as corretas! :)
**/


////////////////////////////////////SORTEIO//////////////////////////////////////
// aqui ocorre o sorteio da senha de uma forma totalmente randomica

void sorteia_valores(int *m, int nivel){
    int i;
    srand(time(NULL));
    if (nivel==0 || nivel==2){
        do{
            for (i=0; i<4; i++){
                m[i] = 1+(rand() % 8);
            }
        }while(m[1]==m[2] || m[1]==m[3] || m[1]==m[0] || m[2]==m[3] || m[2]==m[0] || m[3]==m[0]);
    }
    else if (nivel==1){
        do{
            for (i=0; i<3; i++){
                m[i] = 1+(rand() % 8);
            }
        }while(m[0]==m[1] || m[0]==m[2] || m[1]==m[2]);
    }
}

///////////////////////////COMPARA SENHA////////////////////////////////

void compara_senha(int *m, int *senhau, int nivel)
{
    int i, j, contp, contpf, conte, cont, tent, tentf;
    //contpf e tentf são auxiliares
    //tent = número de tentativas máximas
    //i e j contadores
    // contp = numeros certos em posições corretas
    // conte = numeros certos em posições erradas
    // cont = numero de tentativas
    cont=0;

    if (nivel==0 || nivel==2){
        printf("\nQuantas tentativas deseja ter? ");
        scanf("%i", &tent);
        do{
            contp=0;
            conte=0;

            printf("\nVoce tem %i tentativas.\n", tent);
            printf("\nDigite sua senha de 4 digitos diferentes: \n");

            for (i=0; i<4; i++){
                printf("Digito %i da senha (de 1 a 9): ", i+1);
                scanf("%i", &senhau[i]);
            };
            for(i=0; i<4; i++){
                if (*(m+i)==*(senhau+i)){
                    contp=contp+1;
                }
                for (j=0; j<4; j++){
                    if (*(m+i)==*(senhau+j) && *(m+i)!=*(senhau+i))
                    conte=(conte+1);
                }
            }
            printf("\nNumeros certos em posicoes corretas: %i \nNumeros certos em posicoes erradas: %i\n", contp, conte);
            tent=tent-1;
            cont++;

            if (tent==0){
                contpf=4;
                tentf=0;
            }
            if (contp==4){
                tentf=0;
                contpf=4;
            }
        }while(contpf=!4 || tentf!=0);
    }

    if (nivel==1){
        printf("\nQuantas tentativas deseja ter? ");
        scanf("%i", &tent);
        do{
            contp=0;
            conte=0;
            printf("\nVoce tem %i tentativas.\n", tent);
            printf("\nDigite sua senha de 3 digitos diferentes: \n");

            for (i=0; i<3; i++){
                printf("Digito %i da senha (de 1 a 9): ", i+1);
                scanf("%i", &senhau[i]);
            };
            for(i=0; i<3; i++){
                if (*(m+i)==*(senhau+i)){
                    contp=contp+1;
                }
                for (j=0; j<3; j++){
                    if (*(m+i)==*(senhau+j) && *(m+i)!=*(senhau+i))
                    conte=(conte+1);
                }
            }
            printf("\nNumeros certos em posicoes corretas: %i \nNumeros certos em posicoes erradas: %i\n", contp, conte);
            tent=tent-1;
            cont++;
            if (tent==0){
                contpf=3;
                tentf=0;
            }
            if (contp==3){
                tentf=0;
                contpf=3;
            }
        }while(contpf=!3 || tentf!=0);
    }

        if (tent==0 && contp!=4)
            printf("\nVoce excedeu seu numero de tentativas.\n");
        else
            printf("\nVoce ganhou! Em um total de %i tentativas.", cont);
}

////////////////////////////////NIVEL DE DIFICULDADE//////////////////////////////

void dificuldade (int nivel, int *sorteio, int *senhau)
{
	int i, j;
	if (nivel==0){
		printf("Voce escolheu o modo TESTE.\n");
		printf("A senha e: ");
        for (j=0; j<4; j++)
            printf("%i", sorteio[j]);
	}
	if (nivel==1){
		printf("Voce escolheu o modo FACIL.\n");
	}
	if (nivel==2){
		printf("Voce escolheu o modo DIFICIL.\n");
    };
}

////////////////////////////MAIN///////////////////////////

int main()
{
	int senha, nivel, *m, *n;
	srand(time(NULL));
    m=(int *)malloc(4*sizeof(int));
    n=(int *)malloc(4*sizeof(int));

	printf("Bem vindo ao jogo, abaixo escolha seu nivel de dificuldade: ");
	printf("Escolha: \n0-Teste \n1-Facil \n2-Dificil\n");
	scanf("%i", &nivel);

    sorteia_valores(m, nivel);
	dificuldade(nivel, m, n);
	compara_senha(m, n, nivel);

    free(m);
    free(n);
}
