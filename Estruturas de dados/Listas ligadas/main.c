#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ll.h"

int main(int argc, char const* argv[]) {
    ll* lista = cria_ll(1);

    assert(!empty(lista));
    assert(size(lista) == 1);
    assert(value_at(lista, 0) == 1);

    push_front(&lista, 0);
    push_back(&lista, 3);
    insert(&lista, 2, 2);
    
    assert(front(lista) == 0);
    assert(back(lista) == 3);
    assert(value_from_n(lista, 1) == 2);
    assert(pop_front(&lista) == 0);
    assert(pop_back(&lista) == 3);

    reverse(&lista);
    erase(&lista, 1);
    remove_value(&lista, 10);
    remove_value(&lista, 2);

    assert(empty(lista));
    assert(size(lista) == 0);

    for (int i = 0; i < 5; i++) {
        push_back(&lista, 5 + i);
        push_front(&lista, 5 - i);
    }

    remove_value(&lista, 5);
    reverse(&lista);

    assert(size(lista) == 9);

    imprimir_ll(lista);
    destroi_ll(lista);

    return EXIT_SUCCESS;
}
