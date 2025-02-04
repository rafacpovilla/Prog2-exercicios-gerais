#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main (){
    int tam;
    scanf("%d\n", &tam);

    int *vetor = CriaVetor(tam);
    LeVetor(vetor, tam);

    printf("%.2f\n", CalculaMedia(vetor, tam));

    LiberaVetor(vetor);

    return 0;
}