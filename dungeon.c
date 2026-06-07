#include <stdio.h>

#define ALTURA 5
#define LARGURA 9

int main(void){

    char mapa[ALTURA][LARGURA+1] = {
        "#########",
        "#.......#",
        "#.......#",
        "#.......#",
        "#########",
    };

    int x, y, rodando, tecla;

    x = 4;
    y = 2;
    rodando = 1;

    printf("Bem-vindo ao jogo de Dungeon!\n");
    printf("Use as teclas WASD para se mover e Q para sair\n");
    printf("Posição inicial: (%d, %d)\n", x, y);

    while(rodando){
        for(int linha = 0; linha < ALTURA; linha++){
            for(int coluna = 0; coluna < LARGURA; coluna++){
                if (coluna == x && linha == y ){
                    printf("@");
                } else {
                    printf("%c", mapa[linha][coluna]);
                }
            }
            printf("\n");
        }

        printf("MOVA: ");

        tecla = getchar();

        int novo_x, novo_y;

        novo_x = x;
        novo_y = y;

        switch(tecla){
            case 'w': novo_y = y-1; break;
            case 's': novo_y = y+1; break;
            case 'a': novo_x = x-1; break;
            case 'd': novo_x = x+1; break;
            case 'q': rodando = 0; break;
        }

        if(mapa[novo_y][novo_x] != '#'){
            x = novo_x;
            y = novo_y;
        }

    }
    printf("Valeu pelo jogo!\n");
    return 0;
}