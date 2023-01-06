#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "abb.h"

int main(int argc, char const* argv[]) {
    No* abb = NULL;

    abb = insert(abb, 4);
    abb = insert(abb, 12);
    abb = insert(abb, 3);
    abb = insert(abb, 11);
    abb = insert(abb, 16);

    imprime_arvore(abb);
    printf("\n");

    assert(get_node_count(abb) == 5);
    assert(is_in_tree(abb, 3));
    assert(is_in_tree(abb, 11));
    assert(is_in_tree(abb, 16));
    assert(!is_in_tree(abb, 0));
    assert(!is_in_tree(abb, -1));
    assert(get_height(abb) == 3);

    abb = insert(abb, 5);

    assert(get_height(abb) == 4);
    assert(get_min(abb) == 3);

    abb = insert(abb, 2);

    assert(get_min(abb) == 2);
    assert(get_max(abb) == 16);

    abb = insert(abb, 32);

    assert(get_max(abb) == 32);
    assert(is_binary_search_tree(abb));

    abb = delete_value(abb, 4);

    assert(!is_in_tree(abb, 4));
    assert(get_node_count(abb) == 7);

    abb = insert(abb, 4);

    assert(get_successor(abb, 3) == 4);
    assert(get_successor(abb, 2) == 3);
    assert(get_successor(abb, 4) == 5);
    assert(get_successor(abb, 5) == 11);

    No* nao_abb = malloc(sizeof(No));
    verifica_endereco(nao_abb);

    nao_abb->dado = 10;
    nao_abb->esquerda = NULL;
    nao_abb->direita = malloc(sizeof(No));
    verifica_endereco(nao_abb->direita);
    nao_abb->direita->dado = 9;
    nao_abb->direita->esquerda = NULL;
    nao_abb->direita->direita = NULL;

    assert(!is_binary_search_tree(nao_abb));

    destroi_arvore(abb);
    destroi_arvore(nao_abb);

    return EXIT_SUCCESS;
}

