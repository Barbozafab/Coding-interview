#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "max_heap.h"

int main(int argc, char const* argv[]) {
    int tamanho = 10;
    int* dados = malloc((tamanho + 1) * sizeof(int));
    verifica_endereco(dados);

    for (register int i = 1; i <= tamanho; i++) {
        dados[i] = 11 - i;
    }

    Heap* heap = build_max_heap(dados, tamanho);
    assert(!is_empty(heap));
    assert(get_size(heap) == tamanho);
    assert(extract_max(heap) == 10);

    insert(heap, 9);
    remove_node(heap, 1);
    remove_node(heap, 4);
    remove_node(heap, 7);

    assert(get_max(heap) == 9);
    max_heapsort(dados, tamanho - 3);

    print_heap(heap);
    destroy_max_heap(heap);

    return EXIT_SUCCESS;
}
