#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "fila_ll.h"

int main(int argc, char const* argv[]) {
    Fila* fila = cria_fila();

    assert(empty(fila));

    for (register int i = 0; i < 4; i++) {
        enqueue(fila, i);
    }

    for (register int i = 0; i < 2; i++) {
        assert(dequeue(fila) == i);
    }

    enqueue(fila, 10);
    enqueue(fila, 11);

    imprime_fila(fila);

    assert(dequeue(fila) == 2);
    assert(dequeue(fila) == 3);
    assert(!empty(fila));
    assert(dequeue(fila) == 10);
    assert(dequeue(fila) == 11);
    assert(empty(fila));

    return EXIT_SUCCESS;
}


