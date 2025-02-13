#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "banco.h"

tBanco *CriaBanco(){
    tBanco *b;
    b = (tBanco *)calloc(1, sizeof(tBanco));
    if(b == NULL){
        exit(1);
    }
    b->contas = (tConta **)calloc(5, sizeof(tConta *));
    b->contasAlocadas = 5;
    return b;
}

void DestroiBanco(tBanco *banco){
    for(int i = 0; i < banco->contasAlocadas; i++){
        DestroiConta(banco->contas[i]);
    }
    free(banco->contas);
    free(banco);
}

void AbreContaBanco(tBanco *banco){
    if(banco->qtdContas == banco->contasAlocadas){
        banco->contasAlocadas *= 2;
        banco->contas = (tConta** )realloc(banco->contas, banco->contasAlocadas * sizeof(tConta *));
    }
    banco->contas[banco->qtdContas] = CriaConta();
    LeConta(banco->contas[banco->qtdContas]);
    banco->qtdContas += 1;
}

void SaqueContaBanco(tBanco *banco){
    int conta;
    float valor;
    scanf("%d %f\n", &conta, &valor);
    for(int i = 0; i < banco->qtdContas; i++){
        if(VerificaConta(banco->contas[i], conta) == 1){
            SaqueConta(banco->contas[i], valor); 
        }
    }
}

void DepositoContaBanco(tBanco *banco){
    int conta;
    float valor;
    scanf("%d %f\n", &conta, &valor);
    for(int i = 0; i < banco->qtdContas; i++){
        if(VerificaConta(banco->contas[i], conta) == 1){
            DepositoConta(banco->contas[i], valor); 
        }
    }
}

void TransferenciaContaBanco(tBanco *banco){
    int origem;
    int destino;
    float valor;
    scanf("%d %d %f\n", &destino, &origem, &valor);
    for(int i = 0; i < banco->qtdContas; i++){
        if(VerificaConta(banco->contas[i], destino) == 1){
            for(int j = 0; j < banco->qtdContas; j++){
                if(VerificaConta(banco->contas[j], origem) == 1){
                    TransferenciaConta(banco->contas[i], banco->contas[j], valor);
                }
            }
        }
    }
}

void ImprimeRelatorioBanco(tBanco *banco){
    printf("===| Imprimindo Relatorio |===\n");
    for(int i = 0; i < banco->qtdContas; i++){
        ImprimeConta(banco->contas[i]);
        printf("\n");
    }
}