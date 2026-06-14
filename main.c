#include <stdio.h>
#include <stdlib.h>   // pra malloc e free
#include "jogo.h"

int main(void) {
    char mapa[ALTURA][LARGURA + 1] = {
        "#########",
        "#.......#",
        "#.......#",
        "#.......#",
        "#########",
    };

    // o jogador agora e uma struct (na stack)
    Jogador jogador = {4, 2, 100, '@'};

    // imagine que esse numero veio em tempo de execucao
    int num_monstros = 2;

    // aloca um array de monstros na HEAP
    Monstro *monstros = malloc(num_monstros * sizeof(Monstro));
    if (monstros == NULL) {            // sempre cheque o malloc!
        printf("Sem memoria!\n");
        return 1;
    }

    monstros[0].x = 2; monstros[0].y = 1; monstros[0].hp = 20; monstros[0].simbolo = 'M';
    monstros[1].x = 6; monstros[1].y = 3; monstros[1].hp = 20; monstros[1].simbolo = 'M';

    int rodando = 1;
    int tecla;

    while (rodando) {
        desenhar(mapa, jogador, monstros, num_monstros);

        tecla = getchar();

        if (tecla == 'q') {
            rodando = 0;
        } else {
            mover(mapa, &jogador, tecla);   // passa o ENDERECO do jogador
        }
    }

    free(monstros);     // devolve a memoria — sem isso, vazamento!
    monstros = NULL;    // bom habito: evita usar ponteiro "pendurado"

    printf("Valeu pelo jogo!\n");
    return 0;
}