#include <stdio.h>

#define MAX_LIVROS 10000

int main (){
    int qtd;
    int livros[MAX_LIVROS];
    int contagem[MAX_LIVROS + 1] = {0}; // Array para contar cópias de 0 a MAX_LIVROS
    int livroUnico = 0;

    scanf("%d", &qtd);

    for(int i = 0; i < qtd; i++){
        scanf("%d", &livros[i]);
        contagem[livros[i]]++;    //incrementa a posião correspondente ao identificador array 
                                  //contagem.Assim, cada vez que um identificado aparece, o 
                                  //contador dele é incrementado.
    }

    for(int j = 0; j < qtd; j++){
        if(contagem[livros[j]] == 1){
            printf("%d ", livros[j]);
            livroUnico = 1;
        }
    }

    if (livroUnico == 0) {
        printf("NENHUM");
    }
    printf("\n");

    return 0;
}