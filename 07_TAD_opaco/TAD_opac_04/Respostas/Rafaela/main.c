#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

void OrdenaAlunos(tAluno** alunos, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ComparaMatricula(alunos[j], alunos[j + 1]) > 0) {
                tAluno* temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
            }
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    
    tAluno** alunos = (tAluno**) malloc(n * sizeof(tAluno*));
    for (int i = 0; i < n; i++) {
        alunos[i] = CriaAluno();
        LeAluno(alunos[i]);
    }
    
    OrdenaAlunos(alunos, n);
    
    for (int i = 0; i < n; i++) {
        if (VerificaAprovacao(alunos[i])) {
            ImprimeAluno(alunos[i]);
        }
        ApagaAluno(alunos[i]);
    }
    free(alunos);
    
    return 0;
}