#include <stdio.h>
#include <string.h>
#include "aluno.h"

tAluno CriaAluno(char *nome, int matricula, int n1, int n2, int n3){
    tAluno aluno; 
    strncpy(aluno.nome, nome, sizeof(aluno.nome) - 1);
    aluno.nome[sizeof(aluno.nome) - 1] = '\0'; // Garante o final nulo

    aluno.matricula = matricula;
    aluno.n1 = n1;
    aluno.n2 = n2;
    aluno.n3 = n3;

    return aluno;
}

tAluno LeAluno(){
    tAluno aluno;
    scanf(" %[^\n]", aluno.nome);
    scanf("%d", &aluno.matricula);
    scanf("%d %d %d", &aluno.n1, &aluno.n2, &aluno.n3);

    return aluno;
}

int ComparaMatricula(tAluno aluno1, tAluno aluno2){
    if (aluno1.matricula > aluno2.matricula){
        return 1;
    }
    else if (aluno1.matricula < aluno2.matricula){
        return -1;
    }
    else {  //iguais
        return 0;
    }
}

int CalculaMediaAluno(tAluno aluno){
    int media;
    media = (aluno.n1 + aluno.n2 + aluno.n3) / 3;

    return media;
}

int VerificaAprovacao(tAluno aluno){
    int media;
    media = CalculaMediaAluno(aluno);
    if (media >= 7){
        return 1;
    }
    else {
        return 0;
    }
}

void ImprimeAluno(tAluno aluno){
    printf("%s\n", aluno.nome);
}
