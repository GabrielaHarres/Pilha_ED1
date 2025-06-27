#include <stdio.h>
#include "pilha_caracteres.h"
#include "hanoi_game.h"

void testarPilhaLetras() {
    PilhaLetra minhaPilha;
    iniciarPilha(&minhaPilha);

    char letras[] = {'A', 'B', 'C', 'D'};

    printf("Adicionando letras: A, B, C, D...\n");
    for (int i = 0; i < 4; i++) {
        if (inserirLetra(&minhaPilha, letras[i])) {
            printf("Letra %c adicionada.\n", letras[i]);
        } else {
            printf("Erro ao adicionar %c.\n", letras[i]);
        }
    }

    imprimirPilha(&minhaPilha);

    printf("\nRemovendo letras:\n");
    while (!estaVazia(&minhaPilha)) {
        printf("Removida: %c\n", removerLetra(&minhaPilha));
    }
}

void simularHanoi() {
    JogoHanoi jogo;
    int discos;

    printf("\nInforme o numero de discos (1 a 10): ");
    scanf("%d", &discos);

    if (discos < 1 || discos > 10) {
        printf("Valor invalido para numero de discos.\n");
        return;
    }

    prepararJogo(&jogo, discos);
    printf("Solucao da Torre de Hanoi com %d discos:\n", discos);
    jogarHanoi(&jogo, discos, 0, 2, 1);
}

int main() {
    int escolha;

    do {
        printf("\n==== MENU PRINCIPAL ====\n");
        printf("1. Testar Pilha de Letras\n");
        printf("2. Resolver Torre de Hanoi\n");
        printf("0. Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                testarPilhaLetras();
                break;
            case 2:
                simularHanoi();
                break;
            case 0:
                printf("Finalizando execucao.\n");
                break;
            default:
                printf("Opção invalida!\n");
        }
    } while (escolha != 0);

    return 0;
}