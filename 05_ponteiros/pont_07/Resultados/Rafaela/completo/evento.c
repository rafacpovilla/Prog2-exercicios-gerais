#include <stdio.h> 
#include "evento.h" 

void cadastrarEvento(Evento* eventos, int* numEventos){
    scanf("%s", eventos[*numEventos].nome);
    scanf("%d %d %d", &eventos[*numEventos].dia, &eventos[*numEventos].mes, &eventos[*numEventos].ano);
    printf("Evento cadastrado com sucesso!\n");
    (*numEventos)++;
}

void exibirEventos(Evento* eventos, int* numEventos){
    printf("Eventos cadastrados:\n");
    for(int i = 0; i < *numEventos; i++){
        printf("%d - %s - %d/%d/%d\n", i, eventos[i].nome, eventos[i].dia, eventos[i].mes, eventos[i].ano);
    }
}

void trocarDataEvento(Evento* eventos, int* numEventos){
    int qualEvento;
    scanf("%d", &qualEvento);

    if(qualEvento < (*numEventos)){
        scanf("%d %d %d", &eventos[qualEvento].dia, &eventos[qualEvento].mes, &eventos[qualEvento].ano);
        printf("Data modificada com sucesso!\n");
    }
    else {
        printf("Indice invalido!\n");
    }
}

void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos){
    if((*indiceA) < (*numEventos) && (*indiceB) < (*numEventos)){
        Evento aux;
        aux = eventos[*indiceA];
        eventos[*indiceA] = eventos[*indiceB];
        eventos[*indiceB] = aux;
    }
    else {
        printf("Indices invalidos!\n");
    }
}
