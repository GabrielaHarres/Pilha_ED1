#ifndef HANOI_GAME_H
#define HANOI_GAME_H

#include <stdbool.h>

#define MAX_DISCOS 20

typedef struct {
    int valores[MAX_DISCOS];
    int topo;
} Torre;

typedef struct {
    Torre bases[3];
    int quantidade;
} JogoHanoi;

void prepararJogo(JogoHanoi* jogo, int n);
bool transferir(JogoHanoi* jogo, int origem, int destino);
void jogarHanoi(JogoHanoi* jogo, int n, int origem, int destino, int apoio);

#endif