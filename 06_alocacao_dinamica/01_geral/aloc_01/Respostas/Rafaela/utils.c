#include <stdio.h>
#include <stdlib.h>

int *CriaVetor(int tamanho){
    int *vetor = (int *)malloc(tamanho * sizeof(int));
    if(vetor == NULL){
        printf("Erro na alocacao de memeoria!\n");
        exit(1);
    }
    return vetor;
}

void LeVetor(int *vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        scanf("%d\n", &vetor[i]);
    }
}

float CalculaMedia(int *vetor, int tamanho){
    int soma = 0;
    for(int i = 0; i < tamanho; i++){
        soma += vetor[i];
    }
    return (float)soma / tamanho;
}

void LiberaVetor(int *vetor){
    free(vetor);
}