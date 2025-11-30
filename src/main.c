#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogadores.h"
#include "itens.h"

#define MAX_JOGADORES 8

int main() {
    printf("=== Desafio Free Fire - Tema 2 ===\n");

    int qtd;
    printf("Quantos jogadores? (1-%d): ", MAX_JOGADORES);
    if (scanf("%d", &qtd) != 1 || qtd < 1 || qtd > MAX_JOGADORES) {
        printf("Quantidade inválida.\n");
        return 1;
    }
    getchar(); // limpar newline

    Jogador jogadores[MAX_JOGADORES];
    for (int i = 0; i < qtd; i++) {
        jogadores[i].id = i+1;
        jogadores[i].vida = 100;
        jogadores[i].qtd_itens = 0;
        printf("Nome do jogador %d: ", i+1);
        fgets(jogadores[i].nome, MAX_NOME_JOG, stdin);
        char *nl = strchr(jogadores[i].nome, '\n');
        if (nl) *nl = '\0';
        if (strlen(jogadores[i].nome) == 0) sprintf(jogadores[i].nome, "Jogador%d", i+1);
    }

    Item itensDisponiveis[10];
    int qtdIt = carregar_itens_exemplo(itensDisponiveis, 10);

    // Distribui 1 item a cada jogador em round-robin (exemplo)
    for (int i = 0; i < qtd; i++) {
        adicionar_item_jogador(&jogadores[i], &itensDisponiveis[i % qtdIt]);
    }

    printf("\n--- Estado inicial ---\n");
    listar_jogadores(jogadores, qtd);

    printf("\n--- Itens disponiveis ---\n");
    for (int i = 0; i < qtdIt; i++) {
        printf("%d - %s (tipo: %s, poder: %d)\n", itensDisponiveis[i].id, itensDisponiveis[i].nome, 
            itensDisponiveis[i].tipo, itensDisponiveis[i].poder);
    }

    printf("\nArquivo 'mapa.txt' (opcional) foi carregado se existir na raiz.\n");
    return 0;
}
