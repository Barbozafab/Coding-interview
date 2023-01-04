#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "pilha_ll.h"

Pilha* cria_pilha() {
    Pilha* pilha = malloc(sizeof(Pilha));
    verifica_endereco(pilha);

    pilha->topo = NULL;

    return pilha;
}

void destroi_lista(No* no) {
    if (no->prox != NULL) {
        destroi_lista(no->prox);
    }

    free(no);
}

void destroi_pilha(Pilha* pilha) {
    if (pilha->topo != NULL) {
        destroi_lista(pilha->topo);
    }

    free(pilha);
}

void imprime_pilha(Pilha* pilha) {
    No* atual = pilha->topo;

    while(atual != NULL) {
        printf("[%d] <- ", atual->dado);
        atual = atual->prox;
    }

    printf("\n");
}

int empty(Pilha* pilha) {
    return (pilha->topo == NULL ? 1 : 0);
}

void push(Pilha* pilha, int num) {
    No* novo = malloc(sizeof(No));
    verifica_endereco(novo);

    novo->dado = num;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

int pop(Pilha* pilha) {
    if (pilha->topo == NULL) {
        exit(EXIT_FAILURE);
    }

    No* topo = pilha->topo;
    int num = topo->dado;

    pilha->topo = topo->prox;
    free(topo);

    return num;
}

void verifica_endereco(void* ponteiro) {
    if (ponteiro == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
}
