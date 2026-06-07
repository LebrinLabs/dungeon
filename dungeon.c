#include <stdio.h>

#define ALTURA 5
#define LARGURA 9

// recebe o mapa e os ENDERECOS de x e y, pra poder atualizar a posicao
void mover(char mapa[][LARGURA + 1], int *x, int *y, int tecla) {
    int novo_x = *x;
    int novo_y = *y;

    switch (tecla) {
        case 'w': novo_y = *y - 1; break;
        case 's': novo_y = *y + 1; break;
        case 'a': novo_x = *x - 1; break;
        case 'd': novo_x = *x + 1; break;
    }

    // so move se o destino nao for parede
    if (mapa[novo_y][novo_x] != '#') {
        *x = novo_x;
        *y = novo_y;
    }
}

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
        // desenha o mapa com o jogador
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

        tecla = getchar();

        if (tecla == 'q') {
            rodando = 0;
        } else {
            mover(mapa, &x, &y, tecla);   // passa os ENDERECOS de x e y
        }
    }

    printf("Valeu pelo jogo!\n");
    return 0;
}