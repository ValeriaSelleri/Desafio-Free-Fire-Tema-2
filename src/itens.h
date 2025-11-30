#ifndef ITENS_H
#define ITENS_H

#define MAX_NOME_ITEM 50

typedef struct Item {
    int id;
    char nome[MAX_NOME_ITEM];
    char tipo[20]; // "arma", "kit", "colete", etc.
    int poder; // valor ilustrativo
} Item;

int carregar_itens_exemplo(Item itens[], int max);
Item criar_item(int id, const char *nome, const char *tipo, int poder);

#endif
