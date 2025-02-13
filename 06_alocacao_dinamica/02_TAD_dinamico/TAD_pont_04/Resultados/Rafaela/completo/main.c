#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"


int main() {
    int qtdAlunos;
    scanf("%d", &qtdAlunos);
    
    tAluno** alunos = (tAluno**)malloc(qtdAlunos * sizeof(tAluno*));
    if (alunos == NULL) {
        printf("Erro na alocacao de memoria para vetor de alunos!\n");
        return 1;
    }
    
    for (int i = 0; i < qtdAlunos; i++) {
        alunos[i] = CriaAluno();
        LeAluno(alunos[i]);
    }
    
    // Ordenação por matrícula (Bubble Sort simples)
    for (int i = 0; i < qtdAlunos - 1; i++) {
        for (int j = 0; j < qtdAlunos - i - 1; j++) {
            if (alunos[j]->matricula > alunos[j + 1]->matricula) {
                tAluno* temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
            }
        }
    }
    
    // Impressão apenas dos aprovados
    for (int i = 0; i < qtdAlunos; i++) {
        if (VerificaAprovacao(alunos[i])) {
            ImprimeAluno(alunos[i]);
        }
        ApagaAluno(alunos[i]);
    }
    
    free(alunos);

    return 0;
}

