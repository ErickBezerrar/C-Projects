#include <stdio.h>
#include <stdlib.h>



    char name[5] [50],endereco[5] [50],cidade [5] [50], estado [5] [50];
    char cpf[5] [50];
    int i=1;
    int quant;
    
    printf("how much do you people want to store ? \n");
    scanf("%d", & quant);
    
    for(i=0;i<quant;i++){
        printf("Digite nome:\n");
        fflush(stdin);
        scanf("",  name);
        printf("Digite endereco:\n");
        fflush(stdin);
        scanf("",  endereco);
        printf("Digite cidade:\n");
        fflush(stdin);
        scanf("%s", cidade);
        printf("Digite estado:\n");
        fflush(stdin);
        scanf("%s",  estado);
        printf("Digite CPF/CNPJ:\n");
        fflush(stdin);
        scanf("%s",  cpf);

    }
    printf("\n-------------------------------------------------------------------------------\n");
    printf("show the people storage\n");
        for(i=0;i<quant;i++){
            printf(" \n NOME:  %s\n ", name);
            printf("ENDERECO:  %s\n ", endereco);
            printf("CIDADE:  %s\n ", cidade);
            printf("ESTADO:  %s\n ", estado);
            printf("CPF/CNPJ:  %s\n ", cpf);
        }
        
    system("pause");
