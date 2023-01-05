#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bb.h"

int main(int argc, char const* argv[]) {
    int lista[] = {1, 2, 3, 4, 6, 7, 8, 9};
    int indices[] = {-1, 0, 1, 2, 3, -1, 4, 5, 6, 7, -1};

    for (register int i = 0; i < 10; i++) {
        assert(bb_iterativa(lista, i, 8) == indices[i]);
        assert(bb_recursiva(lista, i, 0, 7) == indices[i]);
    }

    return EXIT_SUCCESS;
}

