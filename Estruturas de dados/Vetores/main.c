#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "vetor.h"

int main(int argc, char const* argv[]) {
    _vetor* vetor = cria_vetor(16);

    assert(vetor_vazio(vetor));

    push(vetor, 12);
    push(vetor, 13);
    push(vetor, 15);
    insert(vetor, 2, 14);

    assert(tamanho_vetor(vetor) == 4);
    assert(capacidade_vetor(vetor) == 16);

    for (register int i = 11; i >= 0; i--) {
        prepend(vetor, i);
    }

    push(vetor, 16);

    assert(tamanho_vetor(vetor) == 17);
    assert(capacidade_vetor(vetor) == 32);

    for (register int i = 0; i < 8; i++) {
        delete(vetor, 5);
    }

    assert(capacidade_vetor(vetor) == 32);

    int num = pop(vetor);

    assert(num == 16);
    assert(tamanho_vetor(vetor) == 8);
    assert(capacidade_vetor(vetor) == 16);

    int indice = find(vetor, 3);

    assert(indice == 3);

    indice = find(vetor, 5);

    assert(indice == -1);

    remove_num(vetor, 13);
    remove_num(vetor, 15);
    push(vetor, 14);
    prepend(vetor, 14);
    remove_num(vetor, 14);
    remove_num(vetor, 4);

    assert(tamanho_vetor(vetor) == 4);
    assert(capacidade_vetor(vetor) == 16);

    imprime_vetor(vetor);
    destroi_vetor(vetor);

    return EXIT_SUCCESS;
}
