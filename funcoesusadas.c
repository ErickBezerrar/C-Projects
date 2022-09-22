#include <stdio.h>

/*implementacao de uma funcao fatorial - Calcula fatorial de um valor int */

int fat(int n)

{
    int i,f;

    f =1;

    for(i = 1; i<= n; i++)
    f *=i;

    return f;

}


/*Implementacao de uma funcao arranjo - calcula o arranjo de n valores tomados k a k */
int arr(int n, int k)
{
    return(fat(n)/ fat(n-k));
}


/*Implementacao de uma funcao combinacao - calcula a combinacao de n valores tomados ka k*/
int comb(int n, int k)
{
    return (fat(n)/ ((fat(k)* fat(n-k))));
}
