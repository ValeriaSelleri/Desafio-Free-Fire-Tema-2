#include <stdio.h>
#include <string.h>
#include "itens.h"

Item criar_item(int id, const char *nome, const char *tipo, int poder) {
    Item it;
    it.id = id;
    strncpy(it.nome, nome, MAX_NOME_ITEM-1); it.nome[MAX_NOME_ITEM-1] = '\0';
    strncpy(it.tipo, tipo, 19); it.tipo[19] = '\0';
    it.poder = poder;
    return it;
}

int carregar_itens_exemplo(Item itens[], int max) {
    // Exemplo simples de itens
    if (max < 5) return 0;
    itens[0] = criar_item(1, "Rifle M4", "arma", 35);
    itens[1] = criar_item(2, "Shotgun", "arma", 40);
    itens[2] = criar_item(3, "Kit Medico", "kit", 0);
    itens[3] = criar_item(4, "Colete Nivel 2", "colete", 0);
    itens[4] = criar_item(5, "Sniper", "arma", 50);
    return 5; // quantidade carregada
}
