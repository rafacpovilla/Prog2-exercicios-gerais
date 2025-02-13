#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "banco.h"

int main(){
    char opcao;
    tBanco *b;
    b = CriaBanco();

    while(1){
        scanf("%c\n", &opcao);

        if(opcao == 'F'){
            break;
        }

        if(opcao == 'A'){
            AbreContaBanco(b);
        }

        if(opcao == 'S'){
            SaqueContaBanco(b);
        }

        if(opcao == 'D'){
            DepositoContaBanco(b);
        }

        if(opcao == 'T'){
            TransferenciaContaBanco(b);
        }

        if(opcao == 'R'){
            ImprimeRelatorioBanco(b);
        }
    }

    DestroiBanco(b);

    return 0;
}