#include <stdio.h>
#include "jogo.h"

int monstro_em(Monstro *monstros, int num_monstros, int x, int y) {
    for (int i = 0; i < num_monstros; i++) {
        if (monstros[i].hp > 0 && monstros[i].x == x && monstros[i].y == y) {
            return i;
        }
    }
    return -1;
}

void combater(Jogador *jogador, Monstro *monstro) {
    monstro->hp -= 10; 
    printf("Nice Shot! Acertou o monstro! (HP do monstro: %d)\n", monstro->hp);
    if (monstro->hp > 0) {
        jogador->hp -= 5;  
        printf("O monstro revida! (seu HP: %d)\n", jogador->hp);
    } else {
        printf("Monstro derrotado!\n");
    }
}

void desenhar(char mapa[][LARGURA + 1], Jogador jogador, Monstro *monstros, int num_monstros) {
    for (int linha = 0; linha < ALTURA; linha++) {
        for (int coluna = 0; coluna < LARGURA; coluna++) {
            char tile = mapa[linha][coluna];

            if (coluna == jogador.x && linha == jogador.y) {
                tile = jogador.simbolo;
            } else {
                for (int i = 0; i < num_monstros; i++) {
                    if (monstros[i].hp > 0 && monstros[i].x == coluna && monstros[i].y == linha) {
                        tile = monstros[i].simbolo;
                    }
                }
            }

            printf("%c", tile);
        }
        printf("\n");
    }
}

void mover(char mapa[][LARGURA + 1], Jogador *jogador, Monstro *monstros, int num_monstros, int tecla) {
    int novo_x = jogador->x;
    int novo_y = jogador->y;

    switch (tecla) {
        case 'w': novo_y = jogador->y - 1; break;
        case 's': novo_y = jogador->y + 1; break;
        case 'a': novo_x = jogador->x - 1; break;
        case 'd': novo_x = jogador->x + 1; break;
    }

    if (mapa[novo_y][novo_x] == '#') {
        return;
    }

    int idx = monstro_em(monstros, num_monstros, novo_x, novo_y);
    if (idx != -1) {
        combater(jogador, &monstros[idx]);
        return;
    }

    jogador->x = novo_x;
    jogador->y = novo_y;
}

int monstros_vivos(Monstro *monstros, int num_monstros) {
    int vivos = 0;
    for (int i = 0; i < num_monstros; i++) {
        if (monstros[i].hp > 0) {
            vivos++;
        }
    }
    return vivos;
}