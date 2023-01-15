#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ordenacao.h"

int main(int argc, char const* argv[]) {
    int vetor1[] = {2, 6, 5, 0, 8, 7, 1, 3};
    int vetor2[] = {2, 6, 5, 0, 8, 7, 1, 3};
    int vetor3[] = {2, 6, 5, 0, 8, 7, 1, 3};
    int vetor4[] = {2, 6, 5, 0, 8, 7, 1, 3};
    int vetor5[] = {2, 6, 5, 0, 8, 7, 1, 3};
    int vetor6[] = {2, 6, 5, 0, 8, 7, 1, 3};
    int ordenado[] = {0, 1, 2, 3, 5, 6, 7, 8};
    int tamanho = 8, inicio = 0, fim = 7;

    insertion_sort(vetor1, tamanho);
    selection_sort(vetor2, tamanho);
    bubble_sort(vetor3, tamanho);
    merge_sort(vetor4, tamanho);
    heap_sort(vetor5, tamanho);
    quick_sort(vetor6, inicio, fim);

    for (register int i = 0; i < tamanho; i++) assert(vetor1[i] == ordenado[i]);
    for (register int i = 0; i < tamanho; i++) assert(vetor2[i] == ordenado[i]);
    for (register int i = 0; i < tamanho; i++) assert(vetor3[i] == ordenado[i]);
    for (register int i = 0; i < tamanho; i++) assert(vetor4[i] == ordenado[i]);
    for (register int i = 0; i < tamanho; i++) assert(vetor5[i] == ordenado[i]);
    for (register int i = 0; i < tamanho; i++) assert(vetor6[i] == ordenado[i]);

    for (register int i = 0; i < tamanho; i++) printf("%d ", vetor1[i]); printf("\n");
    for (register int i = 0; i < tamanho; i++) printf("%d ", vetor2[i]); printf("\n");
    for (register int i = 0; i < tamanho; i++) printf("%d ", vetor3[i]); printf("\n");
    for (register int i = 0; i < tamanho; i++) printf("%d ", vetor4[i]); printf("\n");
    for (register int i = 0; i < tamanho; i++) printf("%d ", vetor5[i]); printf("\n");
    for (register int i = 0; i < tamanho; i++) printf("%d ", vetor6[i]); printf("\n");

    return EXIT_SUCCESS;
}

