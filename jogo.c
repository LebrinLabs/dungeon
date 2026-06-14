#include <stdio.h>
#include "jogo.h"

void desenhar(char mapa[][LARGURA + 1], Jogador jogador, Monstro *monstros, int num_monstros) {
    for (int linha = 0; linha < ALTURA; linha++) {
        for (int coluna = 0; coluna < LARGURA; coluna++) {
            char tile = mapa[linha][coluna];

            // jogador por cima?
            if (coluna == jogador.x && linha == jogador.y) {
                tile = jogador.simbolo;
            } else {
                // tem monstro aqui?
                for (int i = 0; i < num_monstros; i++) {
                    if (monstros[i].x == coluna && monstros[i].y == linha) {
                        tile = monstros[i].simbolo;
                    }
                }
            }

            printf("%c", tile);
        }
        printf("\n");
    }
    printf("WASD move, Q sai.\n");
}

void mover(char mapa[][LARGURA + 1], Jogador *jogador, int tecla) {
    int novo_x = jogador->x;
    int novo_y = jogador->y;

    switch (tecla) {
        case 'w': novo_y = jogador->y - 1; break;
        case 's': novo_y = jogador->y + 1; break;
        case 'a': novo_x = jogador->x - 1; break;
        case 'd': novo_x = jogador->x + 1; break;
    }

    if (mapa[novo_y][novo_x] != '#') {
        jogador->x = novo_x;
        jogador->y = novo_y;
    }
}