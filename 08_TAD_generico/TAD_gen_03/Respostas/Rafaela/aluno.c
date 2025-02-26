#include "aluno.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Aluno {
    char nome[51];
    char genero;
    float nota;
};

tAluno *CriaAluno() {
    tAluno *aluno = (tAluno *)malloc(sizeof(tAluno));
    if (!aluno) {
        exit(1);
    }
    return aluno;
}

void DestroiAluno(data_type aluno) {
    free((tAluno *)aluno);
}

void LeAluno(tAluno *aluno) {
    scanf("%50[^;];%c;%f", aluno->nome, &aluno->genero, &aluno->nota);
}

char GetGeneroAluno(tAluno *aluno) {
    return aluno->genero;
}

float GetNotaAluno(tAluno *aluno) {
    return aluno->nota;
}
