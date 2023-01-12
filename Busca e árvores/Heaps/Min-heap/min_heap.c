#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "min_heap.h"

void min_heapify(Heap* heap, int indice) {
    int esquerda = 2 * indice;
    int direita = 2 * indice + 1;
    int menor = indice;

    if (esquerda <= heap->tamanho && heap->dados[esquerda] < heap->dados[indice]) {
        menor = esquerda;
    }

    if (direita <= heap->tamanho && heap->dados[direita] < heap->dados[menor]) {
        menor = direita;
    }

    if (menor != indice) {
        int aux = heap->dados[indice];
        heap->dados[indice] = heap->dados[menor];
        heap->dados[menor] = aux;
        min_heapify(heap, menor);
    }
}

Heap* build_min_heap(int* dados, int tamanho) {
    Heap* heap = malloc(sizeof(Heap));
    verifica_endereco(heap);

    heap->dados = dados;
    heap->tamanho = tamanho;

    for (register int i = tamanho / 2; i >= 1; i--) {
        min_heapify(heap, i);
    }

    return heap;
}

void destroy_min_heap(Heap* heap) {
    free(heap->dados);
    free(heap);
}

void print_heap(Heap* heap) {
    printf("[");

    for (register int i = 1; i <= heap->tamanho; i++) {
        printf("%d, ", heap->dados[i]);
    }

    printf("]\n");
}

void min_heapsort(int* dados, int tamanho) {
    Heap* heap = build_min_heap(dados, tamanho);

    for (register int i = tamanho; i >= 1; i--) {
        int aux = heap->dados[i];
        heap->dados[i] = heap->dados[1];
        heap->dados[1] = aux;
        heap->tamanho--;
        min_heapify(heap, 1);
    }

    int* novo = malloc((tamanho + 1) * sizeof(int));

    for (register int i = tamanho; i >= 1; i--) {
        novo[i] = heap->dados[tamanho - i + 1];
    }

    for (register int i = 1; i <= tamanho; i++) {
        heap->dados[i] = novo[i];
    }

    free(heap);
}

void insert(Heap* heap, int num) {
    heap->dados = realloc(heap->dados, (heap->tamanho + 2) * sizeof(int));
    verifica_endereco(heap->dados);
    memmove(&heap->dados[2], &heap->dados[1], heap->tamanho * sizeof(int));
    heap->dados[1] = num;
    heap->tamanho++;
    min_heapify(heap, 1);
}

int get_min(Heap* heap) {
    return heap->dados[1];
}

int extract_min(Heap* heap) {
    int maior = heap->dados[1];

    remove_node(heap, 1);

    return maior;
}

int get_size(Heap* heap) {
    return heap->tamanho;
}

void remove_node(Heap* heap, int indice) {
    heap->dados[indice] = heap->dados[heap->tamanho];
    heap->tamanho--;
    heap->dados = realloc(heap->dados, (heap->tamanho + 1) * sizeof(int));
    verifica_endereco(heap->dados);
    min_heapify(heap, indice);
}

int is_empty(Heap* heap) {
    return heap->tamanho == 0 ? 1 : 0;
}

void verifica_endereco(void* ponteiro) {
    if (ponteiro == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
}
