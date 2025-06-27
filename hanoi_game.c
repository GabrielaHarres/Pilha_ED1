#include <stdio.h>
#include "hanoi_game.h"

void resetarTorre(Torre* t) {
    t->topo = -1;
}

bool colocarDisco(Torre* t, int disco) {
    if (t->topo >= MAX_DISCOS - 1) return false;
    t->valores[++(t->topo)] = disco;
    return true;
}

int tirarDisco(Torre* t) {
    if (t->topo < 0) return -1;
    return t->valores[(t->topo)--];
}

int verTopo(Torre* t) {
    if (t->topo < 0) return -1;
    return t->valores[t->topo];
}

void prepararJogo(JogoHanoi* jogo, int n) {
    jogo->quantidade = n;
    for (int i = 0; i < 3; i++) {
        resetarTorre(&jogo->bases[i]);
    }
    for (int i = n; i >= 1; i--) {
        colocarDisco(&jogo->bases[0], i);
    }
}

bool transferir(JogoHanoi* jogo, int origem, int destino) {
    Torre* o = &jogo->bases[origem];
    Torre* d = &jogo->bases[destino];

    if (o->topo < 0) return false;

    int disco = verTopo(o);
    if (d->topo >= 0 && disco > verTopo(d)) return false;

    tirarDisco(o);
    colocarDisco(d, disco);

    printf("Disco %d movido da torre %c para torre %c\n", disco, 'A' + origem, 'A' + destino);
    return true;
}

void jogarHanoi(JogoHanoi* jogo, int n, int origem, int destino, int apoio) {
    if (n == 0) return;

    jogarHanoi(jogo, n - 1, origem, apoio, destino);
    transferir(jogo, origem, destino);
    jogarHanoi(jogo, n - 1, apoio, destino, origem);
}