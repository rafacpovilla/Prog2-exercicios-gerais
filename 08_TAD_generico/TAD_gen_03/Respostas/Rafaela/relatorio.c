#include <stdio.h>
#include <stdlib.h>
#include "relatorio.h"
#include "aluno.h"
#include "vector.h"

void ImprimeRelatorio(Vector *alunos) {
    int total = VectorSize(alunos);
    int aprovados = 0, masc = 0, fem = 0, outros = 0;
    float somaNotas = 0.0;
    
    for (int i = 0; i < total; i++) {
        tAluno *aluno = (tAluno *)VectorGet(alunos, i);
        somaNotas += GetNotaAluno(aluno);
        if (GetNotaAluno(aluno) >= 6.0) aprovados++;
        if (GetGeneroAluno(aluno) == 'M') masc++;
        else if (GetGeneroAluno(aluno) == 'F') fem++;
        else outros++;
    }
    
    float media = somaNotas / total;
    printf("Media das notas: %.2f\n", media);
    printf("Porcentagem de alunos aprovados: %.2f%%\n", (aprovados * 100.0) / total);
    printf("Porcentagem de cada genero:\n");
    printf("Masculino: %.2f%%\n", (masc * 100.0) / total);
    printf("Feminino: %.2f%%\n", (fem * 100.0) / total);
    printf("Outro: %.2f%%\n", (outros * 100.0) / total);
}
