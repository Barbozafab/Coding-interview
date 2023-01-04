#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "fila_ll.h"

Fila* cria_fila() {
    Fila* fila = malloc(sizeof(Fila));
    verifica_endereco(fila);

    fila->inicio = NULL;
    fila->fim = NULL;

    return fila;
}

void destroi_lista(No* no) {
    if (no->prox != NULL) {
        destroi_lista(no->prox);
    }

    free(no);
}

void destroi_fila(Fila* fila) {
    if (fila->inicio != NULL) {
        destroi_lista(fila->inicio);
    }

    free(fila);
}

void imprime_fila(Fila* fila) {
    No* atual = fila->inicio;

    while (atual != NULL) {
        printf("[%d] <- ", atual->dado);
        atual = atual->prox;
    }

    printf("\n");
}

int empty(Fila* fila) {
    return (fila->inicio == NULL ? 1 : 0);
}

void enqueue(Fila* fila, int num) {
    No* novo = malloc(sizeof(No));
    verifica_endereco(novo);

    novo->dado = num;
    novo->prox = NULL;

    if (empty(fila)) {
        fila->inicio = novo;
    } else {
        fila->fim->prox = novo;
    }
    fila->fim = novo;
}

int dequeue(Fila* fila) {
    if (empty(fila)) {
        exit(EXIT_FAILURE);
    }

    No* atual = fila->inicio;
    int num = atual->dado;

    fila->inicio = atual->prox;
    free(atual);

    if (empty(fila)) {
        fila->fim = NULL;
    }

    return num;
}

void verifica_endereco(void* ponteiro) {
    if (ponteiro == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
}
