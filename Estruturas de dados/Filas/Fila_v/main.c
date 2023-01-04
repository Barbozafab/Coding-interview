#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "fila_v.h"

int main(int argc, char const* argv[]) {
    Fila* fila = cria_fila(4);

    assert(empty(fila));

    for (register int i = 0; i < 4; i++) {
        enqueue(fila, i);
    }

    assert(full(fila));

    for (register int i = 0; i < 2; i++) {
        assert(dequeue(fila) == i);
    }

    enqueue(fila, 10);
    enqueue(fila, 11);

    imprime_fila(fila);

    assert(dequeue(fila) == 2);
    assert(dequeue(fila) == 3);
    assert(!full(fila));
    assert(!empty(fila));
    assert(dequeue(fila) == 10);
    assert(dequeue(fila) == 11);
    assert(!full(fila));
    assert(empty(fila));

    return EXIT_SUCCESS;
}

