#include <stdio.h>

int main (){
    int num, soma = 1;
    scanf("%d", &num);

    for(int i = 0; i < num; i++){
        for(int j = 0; j <= i; j++){
            printf("%d ", soma);
            soma++;
        }
        printf("\n");
    }

    return 0;
}