#include <stdio.h>
#include <stdlib.h>

/**
Descobre a maior média, menor média e maior nota na p1
e informa qual aluno que as tirou.
Utiliza ponteiros e alocação dinâmica.
**/
typedef struct curso{
    int ra;
    char nome[100];
    float p1, p2, p3;
}tCurso;

int main()
{
    tCurso *pcurso;
    int i=0, aux, aux2, aux3;
    float mn=0, maimed=0, menmed=10, media;


    pcurso=(tCurso*)malloc(5*sizeof(tCurso));

    for(i=0; i<5; i++)
    {
        printf("\nDigite o RA do aluno: ");
        scanf("%i", &(pcurso+i)->ra);

        printf("Digite o nome do aluno: ");
        setbuf(stdin, NULL);
        fgets((pcurso+i)->nome, 100, stdin);

        printf("Digite a nota da p1, p2 e p3 respectivamente: ");
        scanf("%f %f %f", &(pcurso+i)->p1, &(pcurso+i)->p2, &(pcurso+i)->p3);

    }

    for (i=0; i<5; i++)
    {
        if (((pcurso+i)->p1)>mn)
            {
            mn=(pcurso+i)->p1;
            aux=i;
            }
    }

    for (i=0; i<5; i++)
    {
        media=(((pcurso+i)->p1)+((pcurso+i)->p2)+((pcurso+i)->p3))/3;
        if (media>maimed){
            maimed=media;
            aux2=i;
        }
        if (media<menmed)
        {
            menmed=media;
            aux3=i;
        }
    }

    printf("\n\nAluno com maior nota da p1: %s", (pcurso+aux)->nome);
    printf("Aluno com maior media: %s", (pcurso+aux2)->nome);
    printf("Aluno com menor media: %s", (pcurso+aux3)->nome);
}
