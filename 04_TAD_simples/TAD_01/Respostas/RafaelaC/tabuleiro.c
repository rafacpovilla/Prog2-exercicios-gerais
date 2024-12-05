#include <stdio.h>

#include "tabuleiro.h"

tTabuleiro CriaTabuleiro(){
    tTabuleiro tabuleiro;
    for(int i = 0; i < TAM_TABULEIRO; i++){
        for(int j = 0; j < TAM_TABULEIRO; j++){
            tabuleiro.posicoes[i][j] = '-';
        }
    }
    tabuleiro.peca1 = 'X';
    tabuleiro.peca2 = '0';
    tabuleiro.pecaVazio = '-';

    return tabuleiro;
}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y){
    if(EstaLivrePosicaoTabuleiro(tabuleiro, x, y) && EhPosicaoValidaTabuleiro(x, y)){
        if(peca == PECA_1){
            tabuleiro.posicoes[x][y] = tabuleiro.peca1;
        }
        else{
            tabuleiro.posicoes[x][y] = tabuleiro.peca2;
        }
    }
    return tabuleiro;
}

int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro){
    for(int i = 0; i < TAM_TABULEIRO; i++){
        for(int j = 0; j < TAM_TABULEIRO; j++){
            if(tabuleiro.posicoes[i][j] == tabuleiro.pecaVazio){
                return 1;
            }
            else{
                return 0;
            }
        }
    }
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca){
    if(peca == PECA_1 && tabuleiro.posicoes[x][y] == tabuleiro.peca1 ||
       peca == PECA_2 && tabuleiro.posicoes[x][y] == tabuleiro.peca2){
        return 1;
    }
    else{
        return 0;
    }
}

int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y){
    for(int i = 0; i < TAM_TABULEIRO; i++){
        for (int j = 0; j < TAM_TABULEIRO; j++){
            if(tabuleiro.posicoes[x][y] == tabuleiro.pecaVazio){
                return 1;
            }
            else{
                return 0;
            }
        }
    }
}

int EhPosicaoValidaTabuleiro(int x, int y){
    if((x < 0 || x > 2) || (y < 0 || y > 2)){
        return 0;   //inválida
    }
    else{
        return 1;   //válida
    }
}

void ImprimeTabuleiro(tTabuleiro tabuleiro){
    for(int i = 0; i < TAM_TABULEIRO; i++){
        for(int j = 0; j < TAM_TABULEIRO; j++){
            printf("%c ", tabuleiro.posicoes[i][j]);
        }
        printf("\n");
    }
}