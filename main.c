#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

int main(void) {
    char mapa[ALTURA][LARGURA + 1] = {
        "#########",
        "#.......#",
        "#.......#",
        "#.......#",
        "#########",
    };

    Jogador jogador = {4, 2, 100, '@'};

    int num_monstros = 2;
    Monstro *monstros = malloc(num_monstros * sizeof(Monstro));
    if (monstros == NULL) {
        printf("Sem memoria!\n");
        return 1;
    }
    monstros[0].x = 2; monstros[0].y = 1; monstros[0].hp = 20; monstros[0].simbolo = 'M';
    monstros[1].x = 6; monstros[1].y = 3; monstros[1].hp = 20; monstros[1].simbolo = 'M';

    int rodando = 1;
    int tecla;

    while (rodando) {
        desenhar(mapa, jogador, monstros, num_monstros);
        printf("HP: %d | Monstros vivos: %d | WASD move, Q sai\n",
               jogador.hp, monstros_vivos(monstros, num_monstros));

        tecla = getchar();

        if (tecla == 'q') {
            rodando = 0;
        } else {
            mover(mapa, &jogador, monstros, num_monstros, tecla);
        }

        if (jogador.hp <= 0) {
            printf("\nVoce morreu! Fim de jogo.\n");
            printf("\nPress F to respect!\n");
            rodando = 0;
        } else if (monstros_vivos(monstros, num_monstros) == 0) {
            printf("\nVoce venceu! Todos os monstros cairam!\n");
            rodando = 0;
        }
    }

    free(monstros);
    monstros = NULL;
    return 0;
}