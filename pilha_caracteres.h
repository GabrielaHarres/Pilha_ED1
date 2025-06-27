#ifndef PILHA_CARACTERES_H
#define PILHA_CARACTERES_H

#include <stdbool.h>

typedef struct {
    char itens[50];
    int indice;
} PilhaLetra;

void iniciarPilha(PilhaLetra* pilha);
bool inserirLetra(PilhaLetra* pilha, char letra);
char removerLetra(PilhaLetra* pilha);
char letraNoTopo(PilhaLetra* pilha);
bool estaVazia(PilhaLetra* pilha);
void imprimirPilha(PilhaLetra* pilha);

#endif