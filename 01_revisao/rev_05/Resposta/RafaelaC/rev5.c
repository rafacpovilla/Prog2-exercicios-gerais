#include <stdio.h>

#define TAM_MAX 100

int main() {
    int qtdLinhas, qtdColunas;
    int matriz[TAM_MAX][TAM_MAX];
    int visitado[TAM_MAX][TAM_MAX] = {0};
    int xi, yi, xf, yf;
    char prioridade[5];

    scanf("%d %d", &qtdLinhas, &qtdColunas);

    for (int i = 0; i < qtdLinhas; i++) {
        for (int j = 0; j < qtdColunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    scanf("%d %d", &xi, &yi);
    scanf("%d %d", &xf, &yf);
    scanf("%s", prioridade);

    // ajuste para índices de 0-base
    xi--; yi--;
    xf--; yf--;

    int xAtual = xi, yAtual = yi;
    visitado[xAtual][yAtual] = 1;  // marca a posição inicial como visitada
    printf("(%d,%d) ", xAtual + 1, yAtual + 1);

    int movimento = 1; // controla se há movimentos válidos
    while (xAtual != xf || yAtual != yf) {
        movimento = 0; // supõe inicialmente que não há movimentos

        for (int i = 0; i < 4; i++) {  // tenta cada direção na ordem de prioridade
            int novoX = xAtual;
            int novoY = yAtual;

            // define a nova posição de acordo com a prioridade
            if (prioridade[i] == 'B') {
                novoX++;
            } else if (prioridade[i] == 'D') {
                novoY++;
            } else if (prioridade[i] == 'E') {
                novoY--;
            } else if (prioridade[i] == 'C') {
                novoX--;
            }

            // verifica se a nova posição é válida
            if (novoX >= 0 && novoX < qtdLinhas && novoY >= 0 && novoY < qtdColunas &&
                matriz[novoX][novoY] == 0 && visitado[novoX][novoY] == 0) {
                
                // atualiza a posição do jogador
                xAtual = novoX;
                yAtual = novoY;
                visitado[xAtual][yAtual] = 1;
                printf("(%d,%d) ", xAtual + 1, yAtual + 1);
                movimento = 1;  // indica que houve um movimento bem-sucedido
                break;
            }
        }

        if (movimento == 0) {
            break;
        }
    }

    return 0;
}
