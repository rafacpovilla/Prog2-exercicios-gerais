#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

struct Vector {
    data_type *data;
    int tam;
    int capacidade;
};

Vector *VectorConstruct(){
    Vector *v = (Vector *)malloc(sizeof(Vector));
    if(!v){
        exit(1);
    }

    v->capacidade = 4;
    v->tam = 0;
    v->data = (data_type *)malloc(v->capacidade * sizeof(data_type));

    if(!v->data){
        free(v);
        exit(1);
    }
    return v;
}

void VectorPushBack(Vector *v, data_type val){
    if(v->tam == v->capacidade){
        v->capacidade *= 2;
        v->data = (data_type *)realloc(v->data, v->capacidade * sizeof(data_type));
        if(!v->data){
            exit(1);
        }
    }
    v->data[v->tam++] = val;
}

data_type VectorGet(Vector *v, int i){
    if (i < 0 || i >= v->tam) {
        printf("Indice invalido!\n");
        exit(1);
    }
    return v->data[i];
}

int VectorSize(Vector *v){
    return v->tam;
}

void VectorDestroy(Vector *v, void (*destroy)(data_type)){
    for (int i = 0; i < v->tam; i++) {
        destroy(v->data[i]);
    }
    free(v->data);
    free(v);
}