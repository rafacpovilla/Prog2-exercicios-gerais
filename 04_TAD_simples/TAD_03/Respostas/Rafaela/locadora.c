#include "locadora.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tLocadora criarLocadora() {
    tLocadora locadora;
    locadora.numFilmes = 0;
    locadora.lucro = 0;
    return locadora;
}

int verificarFilmeCadastrado(tLocadora locadora, int codigo) {
    for (int i = 0; i < locadora.numFilmes; i++) {
        if (locadora.filme[i].codigo == codigo) {
            return 1;
        }
    }
    return 0;
}

tLocadora cadastrarFilmeLocadora(tLocadora locadora, tFilme filme) {
    if (filme.codigo == 0 || filme.qtdEstoque == 0 || strlen(filme.nome) == 0) {
        return locadora; // Ignorar filmes inválidos
    }

    if (verificarFilmeCadastrado(locadora, filme.codigo)) {
        printf("Filme ja cadastrado no estoque\n");
        return locadora;
    }

    locadora.filme[locadora.numFilmes++] = filme;
    printf("Filme cadastrado %d - %s\n", filme.codigo, filme.nome);
    return locadora;
}

tLocadora lerCadastroLocadora(tLocadora locadora) {
    char input[100];
    while (1) {
        fgets(input, 100, stdin);
        if (input[0] == '#') break;

        int codigo, valor, quantidade;
        char nome[MAX_CARACTERES];
        if (sscanf(input, "%d,%19[^,],%d,%d", &codigo, nome, &valor, &quantidade) == 4) {
            tFilme filme = criarFilme(nome, codigo, valor, quantidade);
            locadora = cadastrarFilmeLocadora(locadora, filme);
        }
    }
    return locadora;
}

void consultarEstoqueLocadora(tLocadora locadora) {
    printf("\n~ESTOQUE~\n");
    for (int i = 0; i < locadora.numFilmes; i++) {
        printf("%d - %s Fitas em estoque: %d\n",
               locadora.filme[i].codigo,
               locadora.filme[i].nome,
               locadora.filme[i].qtdEstoque);
    }
}
