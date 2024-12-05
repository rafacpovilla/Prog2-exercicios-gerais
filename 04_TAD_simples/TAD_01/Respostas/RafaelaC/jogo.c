#include <stdio.h>

#include "jogo.h"

tJogo CriaJogo(){
    tJogo jogo;
    jogo.tabuleiro = CriaTabuleiro();
    jogo.jogador1 = CriaJogador(ID_JOGADOR_1);
    jogo.jogador2 = CriaJogador(ID_JOGADOR_2);
    return jogo;
}

void ComecaJogo(tJogo jogo){
    int vez = ID_JOGADOR_1;
    while(!AcabouJogo(jogo)){
        if(vez = ID_JOGADOR_1){
            printf("Jogador 1\n");
            printf("Digite uma posicao (x e y):\n");
            jogo.tabuleiro = JogaJogador(jogo.jogador1, jogo.tabuleiro);
            if(VenceuJogador(jogo.jogador1, jogo.tabuleiro)){
                printf("JOGADOR 1 venceu!\n");
            }
            vez = ID_JOGADOR_2;
        }
        if(vez = ID_JOGADOR_2){
            printf("Jogador 2\n");
            printf("Digite uma posicao (x e y):\n");
            jogo.tabuleiro = JogaJogador(jogo.jogador2, jogo.tabuleiro);
            if(VenceuJogador(jogo.jogador2, jogo.tabuleiro)){
                printf("JOGADOR 2 venceu!\n");
            }
            vez = ID_JOGADOR_1;
        }
    }
    printf("Sem vencedor!\n");
}

int AcabouJogo(tJogo jogo){
    if(TemPosicaoLivreTabuleiro(jogo.tabuleiro) == 1){
        return 0; //nao acabou
    }
    else{
        return 1; //acabou
    }
}

int ContinuaJogo(){
    char resposta;
    printf("Jogar novamente? (s,n)\n");
    if(resposta == 's'){
        return 1; 
    }
    else{
        return 0;
    }
}