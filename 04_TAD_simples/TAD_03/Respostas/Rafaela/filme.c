#include "filme.h"
#include <stdio.h>
#include <string.h>

tFilme criarFilme(char *nome, int codigo, int valor, int quantidade) {
    tFilme filme;
    filme.codigo = codigo;
    strncpy(filme.nome, nome, MAX_CARACTERES - 1);
    filme.nome[MAX_CARACTERES - 1] = '\0';
    filme.valor = valor;
    filme.qtdEstoque = quantidade;
    filme.qtdAlugada = 0;
    return filme;
}

tFilme leFilme(int codigo) {
    tFilme filme;
    filme.codigo = codigo;
    return filme;
}

int obterCodigoFilme(tFilme filme) {
    return filme.codigo;
}

void imprimirNomeFilme(tFilme filme) {
    printf("%s", filme.nome);
}

int obterValorFilme(tFilme filme) {
    return filme.valor;
}

int obterQtdEstoqueFilme(tFilme filme) {
    return filme.qtdEstoque;
}

int obterQtdAlugadaFilme(tFilme filme) {
    return filme.qtdAlugada;
}

int ehMesmoCodigoFilme(tFilme filme, int codigo) {
    return filme.codigo == codigo;
}

tFilme alugarFilme(tFilme filme) {
    if (filme.qtdEstoque > 0) {
        filme.qtdEstoque--;
        filme.qtdAlugada++;
    }
    return filme;
}

tFilme devolverFilme(tFilme filme) {
    if (filme.qtdAlugada > 0) {
        filme.qtdEstoque++;
        filme.qtdAlugada--;
    }
    return filme;
}

int compararNomesFilmes(tFilme filme1, tFilme filme2) {
    return strcmp(filme1.nome, filme2.nome);
}
