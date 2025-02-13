#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conta.h"

tConta *CriaConta(){
    tConta *c;
    c = (tConta *)calloc(1, sizeof(tConta));
    if(c == NULL){
        exit(1);
    }
    c->user = CriaUsuario();
    return c;
}

void DestroiConta(tConta *conta){
    if(conta){
        if(conta->user){
            DestroiUsuario(conta->user);
        }
        free(conta);
    }
}

void LeConta(tConta *conta){
    LeUsuario(conta->user);
}

void ImprimeConta(tConta *conta){
    printf("Conta: %d\n", conta->numero);
    printf("Saldo: R$ %.2f\n", conta->saldo);
    ImprimeUsuario(conta->user);
}

int VerificaConta(tConta *conta, int numero){
    if(conta->numero == numero){
        return 1;
    }
    return 0;
}

void SaqueConta(tConta *conta, float valor){
    if(valor <= conta->saldo){
        conta->saldo -= valor;
    }
}

void DepositoConta(tConta *conta, float valor){
    conta->saldo += valor;
}

void TransferenciaConta(tConta *destino, tConta *origem, float valor){
    if(valor <= origem->saldo){
        origem->saldo -= valor;
        destino->saldo += valor;
    }
}