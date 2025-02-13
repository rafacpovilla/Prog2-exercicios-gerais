#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

tUsuario *CriaUsuario(){
    tUsuario *u;
    u = (tUsuario *)calloc(1, sizeof(tUsuario));
    if(u == NULL){
        exit(1);
    }
    return u;
}

void DestroiUsuario(tUsuario *user){
    free(user);
}

void LeUsuario(tUsuario *user){
    scanf("%s", user->nome);
    scanf("%s", user->cpf);
}

void ImprimeUsuario(tUsuario *user){
    printf("Nome: %s\n", user->nome);
    printf("CPF: %s\n", user->cpf);
}