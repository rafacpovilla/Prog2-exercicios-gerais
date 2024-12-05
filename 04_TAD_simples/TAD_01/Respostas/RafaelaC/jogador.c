#include <stdio.h>

#include "jogador.h"
#include "jogada.h"

tJogador CriaJogador(int idJogador){
    tJogador jogador;
    jogador.id = idJogador;
    return jogador;
}

tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro){
    tJogada jogada = LeJogada();
    if(FoiJogadaBemSucedida(jogada)){
        if(EstaLivrePosicaoTabuleiro(tabuleiro, jogada.x, jogada.y) == 1){
            if(EhPosicaoValidaTabuleiro(jogada.x, jogada.y) == 1){
                printf("Jogada [%d, %d]!\n", jogada.x, jogada.y);
                tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, jogador.id, jogada.x, jogada.y);
            }
            else{
                printf("Posicao invalida (FORA DO TABULEIRO - [%d, %d] )!\n", jogada.x, jogada.y);
            }
                
        }
        else{
            printf("Posicao invalida (OCUPADA - [%d, %d] )!\n", jogada.x, jogada.y);
        }
        
    }
    return tabuleiro;
}

int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro){
    char peca;
    if(jogador.id = ID_JOGADOR_1){
        peca = 'X';
    }
    else{
        peca = '0';
    }

    for(int i = 0; i < TAM_TABULEIRO; i++){
        if(tabuleiro.posicoes[i][0] == peca && tabuleiro.posicoes[i][1] == peca && tabuleiro.posicoes[i][2] == peca){     //alguma coluna igual
            return 1;
        }
        if(tabuleiro.posicoes[0][i] == peca && tabuleiro.posicoes[1][i] == peca && tabuleiro.posicoes[2][i] == peca){    //alguma linha igual
            return 1;
        }
    }
    if(tabuleiro.posicoes[0][0] == peca && tabuleiro.posicoes[1][1] == peca && tabuleiro.posicoes[2][2] == peca){      // ganhou na diagonal de cima p/ baixo
        return 1;
    }
    if(tabuleiro.posicoes[2][0] == peca && tabuleiro.posicoes[1][1] == peca && tabuleiro.posicoes[0][2] == peca){      //ganhou na diagonal de baixo p/ cima
        return 1;
    }

    return 0; //ninguém venceu
}