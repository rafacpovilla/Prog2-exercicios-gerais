#include <stdio.h>
#include <string.h>
#include "usuario.h"

tUsuario CriaUsuario(char nome[20], char cpf[15]){
    tUsuario usuario;

    //Copias de strings
    strncpy(usuario.nome, nome, sizeof(usuario.nome) - 1);
    usuario.nome[sizeof(usuario.nome) - 1] = '\0'; // Garante o final nulo

    strncpy(usuario.cpf, cpf, sizeof(usuario.cpf) - 1);
    usuario.cpf[sizeof(usuario.cpf) - 1] = '\0'; // Garante o final nulo

    return usuario;
}

void ImprimeUsuario(tUsuario user){
    printf("Nome: %s\n", user.nome);
    printf("CPF: %s\n", user.cpf);
}