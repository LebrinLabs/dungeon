#include <stdio.h>
#include "jogo.h"

void desenhar(char mapa[][LARGURA + 1], int x, int y) {
    for (int linha = 0; linha < ALTURA; linha++) {
        for (int coluna = 0; coluna < LARGURA; coluna++) {
            if (coluna == x && linha == y) {
                printf("@");
            } else {
                printf("%c", mapa[linha][coluna]);
            }
        }
        printf("\n");
    }
    printf("WASD move, Q sai.\n");
}

void mover(char mapa[][LARGURA + 1], int *x, int *y, int tecla) {
    int novo_x = *x;
    int novo_y = *y;

    switch (tecla) {
        case 'w': novo_y = *y - 1; break;
        case 's': novo_y = *y + 1; break;
        case 'a': novo_x = *x - 1; break;
        case 'd': novo_x = *x + 1; break;
    }

    if (mapa[novo_y][novo_x] != '#') {
        *x = novo_x;
        *y = novo_y;
    }
}