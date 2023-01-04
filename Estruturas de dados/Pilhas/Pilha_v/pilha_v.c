#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "pilha_v.h"

Pilha* cria_pilha(int capacidade) {
    Pilha* pilha = malloc(sizeof(Pilha));
    verifica_endereco(pilha);

    pilha->dados = malloc(capacidade * sizeof(int));
    verifica_endereco(pilha);

    pilha->capacidade = capacidade;
    pilha->topo = 0;

    return pilha;
}

void destroi_pilha(Pilha* pilha) {
    free(pilha->dados);
    free(pilha);
}

void imprime_pilha(Pilha* pilha) {
    printf("[");
    for (register int i = 0; i < pilha->topo; i++) {
        printf("%d, ", pilha->dados[i]);
    }
    printf("]\n");
}

int empty(Pilha* pilha) {
    return (pilha->topo == 0 ? 1 : 0);
}

int full(Pilha* pilha) {
    return (pilha->topo == pilha->capacidade ? 1 : 0);
}

void push(Pilha* pilha, int num) {
    if (full(pilha)) {
        exit(EXIT_FAILURE);
    }

    pilha->dados[pilha->topo] = num;
    pilha->topo++;
}

int pop(Pilha* pilha) {
    if (empty(pilha)) {
        exit(EXIT_FAILURE);
    }

    pilha->topo--;
    return pilha->dados[pilha->topo];
}

void verifica_endereco(void* ponteiro) {
    if (ponteiro == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
}
