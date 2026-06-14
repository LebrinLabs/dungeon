#ifndef JOGO_H
#define JOGO_H

#define ALTURA 5
#define LARGURA 9

typedef struct {
    int x;
    int y;
    int hp;
    char simbolo;
} Jogador;

typedef struct {
    int x;
    int y;
    int hp;
    char simbolo;
} Monstro;


void desenhar(char mapa[][LARGURA + 1], Jogador jogador, Monstro *monstros, int num_monstros);
void mover(char mapa[][LARGURA + 1], Jogador *jogador, int tecla);

#endif