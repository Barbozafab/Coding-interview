#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "fila_v.h"

Fila* cria_fila(int capacidade) {
    Fila* fila = malloc(sizeof(Fila));
    verifica_endereco(fila);

    fila->dados = malloc(capacidade * sizeof(int));
    verifica_endereco(fila->dados);

    fila->capacidade = capacidade;
    fila->tamanho = 0;
    fila->inicio = 0;
    fila->fim = 0;

    return fila;
}

void destroi_fila(Fila* fila) {
    free(fila->dados);
    free(fila);
}

void imprime_fila(Fila* fila) {
    printf("[");

    for (register int i = 0; i < fila->tamanho; i++) {
        printf("%d, ", fila->dados[i]);
    }

    printf("]\n");
}

int empty(Fila* fila) {
    return (fila->tamanho == 0 ? 1 : 0);
}

int full(Fila* fila) {
    return (fila->tamanho == fila->capacidade ? 1 : 0);
}

void enqueue(Fila* fila, int num) {
    if (full(fila)) {
        exit(EXIT_FAILURE);
    }

    fila->dados[fila->fim] = num;
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->tamanho++;
}

int dequeue(Fila* fila) {
    if (empty(fila)) {
        exit(EXIT_FAILURE);
    }

    int num = fila->dados[fila->inicio];
    fila->inicio = (fila->inicio + 1) % fila->capacidade;
    fila->tamanho--;

    return num;
}

void verifica_endereco(void* ponteiro) {
    if (ponteiro == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
}
