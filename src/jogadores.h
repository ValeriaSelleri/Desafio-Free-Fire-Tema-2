#ifndef JOGADORES_H
#define JOGADORES_H

#define MAX_NOME_JOG 50
#define MAX_ITENS_JOG 10

typedef struct {
    int id;
    char nome[MAX_NOME_JOG];
    int vida;
    struct Item *itens[MAX_ITENS_JOG];
    int qtd_itens;
} Jogador;

void listar_jogadores(Jogador jogadores[], int qtd);
int adicionar_item_jogador(Jogador *j, struct Item *it);

#endif
