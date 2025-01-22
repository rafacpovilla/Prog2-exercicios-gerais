#include <stdio.h>
#include <string.h>
#include "conta.h"

#define MAX_CONTAS 50

int main() {
    tConta contas[MAX_CONTAS];
    int numContas = 0; 

    int contasLidas;
    scanf("%d", &contasLidas);

    if (contasLidas > MAX_CONTAS) {
        contasLidas = MAX_CONTAS;
    }

    int operacao;
    do {
        scanf("%d", &operacao);

        if (operacao == 3) { // Cadastro
            if (numContas < contasLidas) {
                char nome[50], cpf[15];
                int numeroConta;

                scanf("%s %s %d", nome, cpf, &numeroConta);

                // Criar o usuário e a conta
                tUsuario novoUsuario = CriaUsuario(nome, cpf);
                contas[numContas] = CriaConta(numeroConta, novoUsuario);
                contas[numContas].saldo = 0.0; 
                numContas++;
            }
        } 
        
        else if (operacao == 1) { // Saque
            int numeroConta;
            float valor;

            scanf("%d %f", &numeroConta, &valor);

            for (int i = 0; i < numContas; i++) {
                if (VerificaConta(contas[i], numeroConta)) {
                    if (valor <= contas[i].saldo) {
                        contas[i] = SaqueConta(contas[i], valor);
                    }
                    break;
                }
            }
        } 
        
        else if (operacao == 2) { // Depósito
            int numeroConta;
            float valor;

            scanf("%d %f", &numeroConta, &valor);

            for (int i = 0; i < numContas; i++) {
                if (VerificaConta(contas[i], numeroConta)) {
                    contas[i] = DepositoConta(contas[i], valor);
                    break;
                }
            }
        } 
        
        else if (operacao == 4) { // Relatório
            printf("===| Imprimindo Relatorio |===\n");
            for (int i = 0; i < numContas; i++) {
                printf("Conta: %d\n", contas[i].numero);
                printf("Saldo: R$ %.2f\n", contas[i].saldo);
                printf("Nome: %s\n", contas[i].user.nome);
                printf("CPF: %s\n\n", contas[i].user.cpf);
            }
        }
    } while (operacao != 0);

    return 0;
}
