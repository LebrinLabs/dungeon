#ifndef JOGO_H
#define JOGO_H

#define ALTURA 5
#define LARGURA 9

void desenhar (char mapa[][LARGURA + 1], int x, int y);
void mover(char mapa[][LARGURA + 1], int *x, int *y, int tecla);

#endif