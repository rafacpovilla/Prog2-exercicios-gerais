#include "locadora.h"
#include "filme.h"
#include <stdio.h>
#include <string.h>

int main() {
    tLocadora locadora = criarLocadora();
    char comando[50];

    while (scanf("%s", comando) != EOF) {
        if (strcmp(comando, "Cadastrar") == 0) {
            locadora = lerCadastroLocadora(locadora);
        } else if (strcmp(comando, "Estoque") == 0) {
            consultarEstoqueLocadora(locadora);
        }
    }
    return 0;
}
