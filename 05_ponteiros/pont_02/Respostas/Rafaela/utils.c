#include <stdio.h>
#include "utils.h"

void LeIntervalo(int * m, int * n){
    scanf("%d %d", m, n);
}

int EhPrimo(int n){
    if(n <= 1){
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0){
            return 0;
        }
    }
    return 1;
}

void ObtemMaiorEMenorPrimo(int m, int n, int *menor, int *maior){
    *menor = -1;
    *maior = -1;
    
    for(int i = m; i <= n; i++){
        if(EhPrimo(i) == 1){
            if(*menor == -1){
                *menor = i;
            }
            *maior = i;
        }
    }
}