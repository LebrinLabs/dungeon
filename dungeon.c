#include <stdio.h>

int main(void){
    int x, y, rodando, tecla;

    x = 5;
    y = 3;
    rodando = 1;

    printf("Bem-vindo ao jogo de Dungeon!\n");
    printf("Use as teclas WASD para se mover e Q para sair\n");
    printf("Posição inicial: (%d, %d)\n", x, y);

    while(rodando){
        tecla = getchar();

        switch(tecla){
            case 'w':
                y = y - 1;
                break;
            case 's':
                y = y + 1;
                break;
            case 'a':
                x = x - 1;
                break;
            case 'd':
                x = x + 1;
                break;
            case 'q':
                rodando = 0;
            break;
        }

        printf("Posição atual: (%d, %d)\n", x, y);
    }

    printf("Obrigado por jogar!\n");

    return 0;
}