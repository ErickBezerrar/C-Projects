#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int buscar(int vetor[], int n, int e );



    int vetor[6] = {5,4,7,8,3,1};

    printf("%d \n", buscar(vetor,6,7));

    return 0;


int buscar(int vetor[], int n, int e ){
    for(int i=0; i<n; i++){
        if (vetor[i] == e)
            return i;
    }
    return -2;

}