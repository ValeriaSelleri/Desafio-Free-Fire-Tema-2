#include <stdio.h>
#include <string.h>
#include "jogadores.h"
#include "itens.h"

void listar_jogadores(Jogador jogadores[], int qtd) {
    for (int i = 0; i < qtd; i++) {
        printf("ID %d - %s | Vida: %d | Itens: %d\n", jogadores[i].id, jogadores[i].nome, jogadores[i].vida, jogadores[i].qtd_itens);
        for (int k = 0; k < jogadores[i].qtd_itens; k++) {
            Item *it = jogadores[i].itens[k];
            if (it) printf("   - %s (tipo: %s, poder: %d)\n", it->nome, it->tipo, it->poder);
        }
    }
}

int adicionar_item_jogador(Jogador *j, Item *it) {
    if (j->qtd_itens >= MAX_ITENS_JOG) return 0;
    j->itens[j->qtd_itens++] = it;
    return 1;
}
