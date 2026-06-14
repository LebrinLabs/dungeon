#include <stdio.h>
#include "jogo.h"

int main(void) {
    char mapa[ALTURA][LARGURA + 1] = {
        "#########",
        "#.......#",
        "#.......#",
        "#.......#",
        "#########",
    };

    int x = 4;
    int y = 2;
    int rodando = 1;
    int tecla;

    while (rodando) {
        desenhar(mapa, x, y);

        tecla = getchar();

        if (tecla == 'q') {
            rodando = 0;
        } else {
            mover(mapa, &x, &y, tecla);
        }
    }

    printf("Valeu pelo jogo!\n");
    return 0;
}