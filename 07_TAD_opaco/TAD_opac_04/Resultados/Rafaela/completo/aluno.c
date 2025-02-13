#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct Aluno {
    char* nome;
    int matricula;
    int n1, n2, n3;
};

tAluno* CriaAluno(){
    tAluno *aluno;
    aluno = (tAluno *)malloc(sizeof(tAluno));
    if(!aluno){
        return NULL;
    }
    aluno->nome = NULL;
    aluno->matricula = -1;
    aluno->n1 = -1;
    aluno->n2 = -1;
    aluno->n3 = -1;
    return aluno;
}

void ApagaAluno(tAluno *aluno){
    free(aluno->nome);
    free(aluno);
}

void LeAluno(tAluno *aluno){
    char buffer[100];
    scanf(" %[^\n]", buffer);
    aluno->nome = strdup(buffer);
    scanf("%d", &aluno->matricula);
    scanf("%d %d %d", &aluno->n1, &aluno->n2, &aluno->n3);
}

int ComparaMatricula(tAluno* aluno1, tAluno* aluno2){
    if (aluno1->matricula > aluno2->matricula){
        return 1;
    }
    else if (aluno1->matricula < aluno2->matricula){
        return -1;
    }
    else {  //iguais
        return 0;
    }
}

int CalculaMediaAluno(tAluno* aluno){
    int media;
    media = (aluno->n1 + aluno->n2 + aluno->n3) / 3;

    return media;
}

int VerificaAprovacao(tAluno* aluno){
    int media;
    media = CalculaMediaAluno(aluno);
    if (media >= 7){
        return 1;
    }
    else {
        return 0;
    }
}

void ImprimeAluno(tAluno* aluno){
    printf("%s\n", aluno->nome);
}