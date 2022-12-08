#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stddef.h>

const TAM = 10; //tamanho de 10 numeros para escolher
const TENTATIVAS = 3; //numero de tentativas
int num_aleatorio; //variavel global numero aleatorio

void gera_num_aleatorio(void);

void gera_num_aleatorio()
{
    
    int i;
    srand(time(NULL));
    for (i=0; i < TAM; i++)
    {
        num_aleatorio =  rand() % TAM; //escolhe um numero entre 1 a 10
    }
    return num_aleatorio;
}

int main(void)
{
    char nome[50];
    int i, n_escolhido;

    gera_num_aleatorio();

    printf("Ola! qual e o seu nome: ");
    scanf("%s", &nome);

    for(i=0; i<=TENTATIVAS; i++)
    {
        printf("\nEscolha um numero de 0 a 10: ");
        scanf("%d", &n_escolhido);
        if(num_aleatorio != n_escolhido)
        {
            printf("\nErrou! Tente novamente.");
            if(n_escolhido > num_aleatorio)
            {
                printf("\nDica: Escolha um numero MENOR.");
            }
            else
            {
                printf("\nDica: Escolha um numero MAIOR.");
            }
        }
        else
        {
            printf("\nParabens vc acertou!");
            printf("\nO numero era: %d", num_aleatorio);
            break;
        }
    }
    printf("\n\nFim de jogo! Obrigado por jogar!!!\n");
    printf("\nO numero era: %d", num_aleatorio);
}