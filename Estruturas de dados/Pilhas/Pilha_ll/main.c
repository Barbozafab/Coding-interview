#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "pilha_ll.h"

int main(int argc, char const* argv[]) {
    Pilha* pilha = cria_pilha(4);

    assert(empty(pilha));

    for (register int i = 0; i < 4; i++) {
        push(pilha, i);
    }

    for (register int i = 3; i > 1; i--) {
        assert(pop(pilha) == i);
    }

    push(pilha, 10);
    push(pilha, 11);

    imprime_pilha(pilha);

    assert(pop(pilha) == 11);
    assert(pop(pilha) == 10);
    assert(!empty(pilha));
    assert(pop(pilha) == 1);
    assert(pop(pilha) == 0);
    assert(empty(pilha));

    return EXIT_SUCCESS;
}
