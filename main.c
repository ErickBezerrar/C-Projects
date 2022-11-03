#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct abelha Abelha;

struct abelha{

    char nome[20];
    int cpf[12];
    int idade[20];

};

int menu_principal(void);
Abelha* preencheaelha(void);
void gravaabellha(Abelha*);


int main(void){
    Abelha* abelho;
    int esc;
    printf("Programa de cadastro de abelhas \n");
    esc = menu_principal();
    while (esc !=0){
        switch(esc){
            case 1 : abelho = preencheaelha();
                     gravaabellha(abelho);
                     free(abelho);
                     break;
        }
    }
}

int menu_principal(void){
    int esc;
    printf("1 - Cadastrar abelha \n");
    printf("2 - Pesquisar abelha \n");
    printf("3 - Alterar abelha   \n");
    printf("4 - Excluir abelha   \n");
    printf("5 - Listar abelha    \n");
    printf("5 - Listar abelhas por curso \n");
    printf("0 - Encerrar programa \n");
    scanf("%d", &esc);
    return esc;
}