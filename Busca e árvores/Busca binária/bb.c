#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bb.h"

int bb_iterativa(int* vetor, int num, int tamanho) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (vetor[meio] == num) {
            return meio;
        } else if (vetor[meio] > num) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }

    return -1;
}

int bb_recursiva(int* vetor, int num, int inicio, int fim) {
    if (inicio > fim) {
        return -1;
    }

    int meio = (inicio + fim) / 2;

    if (vetor[meio] == num) {
        return meio;
    } else if (vetor[meio] > num) {
        return bb_recursiva(vetor, num, inicio, meio - 1);
    } else {
        return bb_recursiva(vetor, num, meio + 1, fim);
    }
}
