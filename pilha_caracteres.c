#include <stdio.h>
#include "pilha_caracteres.h"

void iniciarPilha(PilhaLetra* pilha) {
    pilha->indice = -1;
}

bool inserirLetra(PilhaLetra* pilha, char letra) {
    if (pilha->indice == 49) return false;
    pilha->itens[++(pilha->indice)] = letra;
    return true;
}

char removerLetra(PilhaLetra* pilha) {
    if (estaVazia(pilha)) {
        printf("A pilha esta vazia. Nada para remover.\n");
        return '\0';
    }
    return pilha->itens[(pilha->indice)--];
}

char letraNoTopo(PilhaLetra* pilha) {
    if (estaVazia(pilha)) return '\0';
    return pilha->itens[pilha->indice];
}

bool estaVazia(PilhaLetra* pilha) {
    return pilha->indice < 0;
}

void imprimirPilha(PilhaLetra* pilha) {
    if (estaVazia(pilha)) {
        printf("Pilha sem elementos.\n");
        return;
    }
    printf("Conteudo da pilha:\n");
    for (int i = 0; i <= pilha->indice; i++) {
        printf("Posicao %d: %c\n", i, pilha->itens[i]);
    }
}