#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "hash.h"

int main(int argc, char const* argv[]) {
    Tabela* tabela = cria_tabela(4);

    for (register int i = 0; i < 9; i++) {
        assert(!exists(tabela, i));
        assert(get(tabela, i) == -1);
    }

    for (register int i = 0; i < 9; i++) {
        add(tabela, i, i);
    }

    for (register int i = 0; i < 9; i++) {
        assert(exists(tabela, i));
        assert(get(tabela, i) == i);
    }

    for (register int i = 0; i < 9; i += 2) {
        remove_pair(tabela, i);
    }

    for (register int i = 0; i < 9; i += 2) {
        assert(!exists(tabela, i));
        assert(get(tabela, i) == -1);
    }

    for (register int i = 1; i < 9; i += 2) {
        assert(exists(tabela, i));
        assert(get(tabela, i) == i);
    }

    imprime_tabela(tabela);
    destroi_tabela(tabela);

    return EXIT_SUCCESS;
}

