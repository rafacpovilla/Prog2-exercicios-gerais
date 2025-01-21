#include <stdio.h>
#include <string.h>
#include "aluno.h"

#define MAX_ALUNOS 100

int main() {
    int alunosLidos = 0;
    tAluno alunos[MAX_ALUNOS];
    tAluno aprovados[MAX_ALUNOS];
    int aprovadosCont = 0;

    scanf("%d", &alunosLidos);

    for (int i = 0; i < alunosLidos; i++) {
        alunos[i] = LeAluno();

        if (VerificaAprovacao(alunos[i]) == 1) {
            aprovados[aprovadosCont++] = alunos[i];
        }
    }

    //Ordenação dos aprovados por matrícula
    for (int i = 0; i < aprovadosCont - 1; i++) {
        for (int j = 0; j < aprovadosCont - i - 1; j++) {
            if (ComparaMatricula(aprovados[j], aprovados[j + 1]) > 0) {
                tAluno aux = aprovados[j];
                aprovados[j] = aprovados[j + 1];
                aprovados[j + 1] = aux;
            }
        }
    }

    // Impressão dos alunos aprovados
    for (int i = 0; i < aprovadosCont; i++) {
        ImprimeAluno(aprovados[i]);
    }

    return 0;
}
