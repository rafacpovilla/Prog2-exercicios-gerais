#include <stdio.h>
#include <stdlib.h>
#include "tadgen.h"

struct generic{
    Type tipo;
    int numElem;
    void *data;
};

tGeneric* CriaGenerico(Type type, int numElem) {
    tGeneric *gen = (tGeneric*) malloc(sizeof(tGeneric));
    if (!gen) {
        exit(1);
    }

    gen->tipo = type;
    gen->numElem = numElem;
    gen->data = NULL;  //inicializa p/ evitar comportamentos indevidos

    if (type == INT) {
        gen->data = malloc(numElem * sizeof(int));
    }
    else if (type == FLOAT) {
        gen->data = malloc(numElem * sizeof(float));
    }

    if (!gen->data) {
        free(gen);
        exit(1);
    }
    return gen;
}


void DestroiGenerico(tGeneric* gen) {
    if (gen) {
        if (gen->data) { 
            free(gen->data);
        }
        free(gen);
    }
}


void LeGenerico(tGeneric* gen) {
    printf("\nDigite o vetor:\n");

    if (gen->tipo == INT) {
        int *arr = (int*) gen->data;
        for (int i = 0; i < gen->numElem; i++) {
            scanf("%d", &arr[i]);
        }
    }
    else {
        float *arr = (float*) gen->data;
        for (int i = 0; i < gen->numElem; i++) {
            scanf("%f", &arr[i]);
        }
    }
}


void ImprimeGenerico(tGeneric* gen){
    if (gen->tipo == INT) {
        int *arr = (int*) gen->data;
        for (int i = 0; i < gen->numElem; i++) {
            printf("%d ", arr[i]);
        }
    }
    else {
        float *arr = (float*) gen->data;
        for (int i = 0; i < gen->numElem; i++) {
            printf("%.2f ", arr[i]);
        }
    }
    printf("\n");
}