#include <stdio.h>
#include "data.h"

tData CriaData(int dia, int mes, int ano){
    tData data;
    data.dia = dia;
    data.mes = mes;
    data.ano = ano;
    return data;
}

int VerificaDataValida(tData data) {
    if (data.mes < 1 || data.mes > 12 || data.dia < 1 || data.ano < 0) {
        return 0;
    }

    if (data.mes == 2) { // Fevereiro
        if (VerificaBissexto(data)) {
            return data.dia <= 29;
        } else {
            return data.dia <= 28;
        }
    }

    if (data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 11) { // Meses com 30 dias
        return data.dia <= 30;
    }

    return data.dia <= 31; // Meses com 31 dias
}


void ImprimeMesExtenso(tData data){
    if(data.mes == 1){
        printf("Janeiro");
    }
    if(data.mes == 2){
        printf("Fevereiro");
    }
    if(data.mes == 3){
        printf("Marco");
    }
    if(data.mes == 4){
        printf("Abril");
    }
    if(data.mes == 5){
        printf("Maio");
    }
    if(data.mes == 6){
        printf("Junho");
    }
    if(data.mes == 7){
        printf("Julho");
    }
    if(data.mes == 8){
        printf("Agosto");
    }
    if(data.mes == 9){
        printf("Setembro");
    }
    if(data.mes == 10){
        printf("Outubro");
    }
    if(data.mes == 11){
        printf("Novembro");
    }
    if(data.mes == 12){
        printf("Dezembro");
    }
}

void ImprimeDataExtenso(tData data){
    printf("%d de ", data.dia);
    ImprimeMesExtenso(data);
    printf(" de %d\n", data.ano);
}

int VerificaBissexto(tData data){
    if ((data.ano % 4 == 0 && data.ano % 100 != 0) || (data.ano % 400 == 0)) {
        return 1;      //é bissexto
    }
    return 0;
}

int NumeroDiasMes(tData data){
    int diasMes = 0;

    if(data.mes == 1 || data.mes == 3 || data.mes == 5 || data.mes == 7 || data.mes == 8 || data.mes == 10 || data.mes == 12){
        diasMes = 31;
    }

    if(data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 11){
        diasMes = 30;
    }

    if(data.mes == 2){ 
        if(VerificaBissexto(data) == 1){
            diasMes = 29;
        }
        else{
            diasMes = 28;
        }
    }

    return diasMes;
}

int ComparaData(tData data1, tData data2){
    if(data1.ano > data2.ano){
        return 1;
    }
    else if(data1.ano < data2.ano){
        return -1;
    }
    else{  //mesmo ano
        if(data1.mes > data2.mes){
            return 1;
        }
        else if(data1.mes < data2.mes){
            return -1;
        }
        else{  //mesmo ano e mesmo mes
            if(data1.dia > data2.dia){
                return 1;
            }
            else if(data1.dia < data2.dia){
                return -1;
            }
            else{  //mesmo ano, mesmo mes e mesmo dia
                return 0;
            }
        }
    }
}


