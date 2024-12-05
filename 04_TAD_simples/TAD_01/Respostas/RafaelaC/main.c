#include <stdio.h>

#include "jogo.h"
#include "jogada.h"

int main() {
    do {
        tJogo jogo = CriaJogo();
        ComecaJogo(jogo);
    } while (ContinuaJogo());
    return 0;
}