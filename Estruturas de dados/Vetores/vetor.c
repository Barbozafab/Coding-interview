#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "vetor.h"

const int capacidadeMinima = 16;
const int fatorAumento = 2;
const int fatorReducao = 4;

_vetor* cria_vetor(int capacidade) {
    if (capacidade < 1) {
        exit(EXIT_FAILURE);
    }

    int capacidade_real = capacidadeMinima;
    while (capacidade_real < capacidade) {
        capacidade_real *= fatorAumento;
    }

    _vetor* novo_vetor = malloc(sizeof(_vetor));
    verifica_endereco(novo_vetor);

    novo_vetor->tamanho = 0;
    novo_vetor->capacidade = capacidade_real;
    novo_vetor->dados = malloc(capacidade_real * sizeof(int));
    verifica_endereco(novo_vetor->dados);

    return novo_vetor;
}

void destroi_vetor(_vetor* vetor) {
    free(vetor->dados);
    free(vetor);
}

int tamanho_vetor(_vetor* vetor) {
    return vetor->tamanho;
}

int capacidade_vetor(_vetor* vetor) {
    return vetor->capacidade;
}

int vetor_vazio(_vetor* vetor) {
    if (vetor->tamanho == 0) {
        return 1;
    }

    return 0;
}

void aumenta_vetor(_vetor* vetor) {
    vetor->capacidade *= fatorAumento;
    vetor->dados = realloc(vetor->dados, vetor->capacidade * sizeof(int));
    verifica_endereco(vetor->dados);
}

void diminui_vetor(_vetor* vetor) {
    vetor->capacidade /= fatorAumento;
    vetor->dados = realloc(vetor->dados, vetor->capacidade * sizeof(int));
    verifica_endereco(vetor->dados);
}

void imprime_vetor(_vetor* vetor) {
    printf("Tamanho: %d\nCapacidade: %d\n", vetor->tamanho, vetor->capacidade);

    printf("[");
    for (register int i = 0; i < vetor->tamanho; i++) {
        printf("%d, ", *(vetor->dados + i));
    }
    printf("]\n");
}

int at(_vetor* vetor, int indice) {
    if (indice < 0 || indice >= vetor->tamanho) {
        exit(EXIT_FAILURE);
    }

    return *(vetor->dados + indice);
}

void push(_vetor* vetor, int num) {
    if (vetor->tamanho == vetor->capacidade) {
        aumenta_vetor(vetor);
    }

    *(vetor->dados + vetor->tamanho) = num;
    vetor->tamanho++;
}

void insert(_vetor* vetor, int indice, int num) {
    if (indice < 0 || indice >= vetor->tamanho) {
        exit(EXIT_FAILURE);
    }

    if (vetor->tamanho == vetor->capacidade) {
        aumenta_vetor(vetor);
    }

    memmove(vetor->dados + indice + 1, vetor->dados + indice, (vetor->tamanho - indice) * sizeof(int));

    *(vetor->dados + indice) = num;
    vetor->tamanho++;
}

void prepend(_vetor* vetor, int num) {
    insert(vetor, 0, num);
}

int pop(_vetor* vetor) {
    if (vetor_vazio(vetor)) {
        exit(EXIT_FAILURE);
    }

    int num = *(vetor->dados + vetor->tamanho - 1);
    vetor->tamanho--;

    if (vetor->tamanho <= vetor->capacidade / fatorReducao && vetor->capacidade > capacidadeMinima) {
        diminui_vetor(vetor);
    }

    return num;
}

void delete(_vetor* vetor, int indice) {
    if (indice < 0 || indice >= vetor->tamanho || vetor_vazio(vetor)) {
        exit(EXIT_FAILURE);
    }

    vetor->tamanho--;
    memmove(vetor->dados + indice, vetor->dados + indice + 1, (vetor->tamanho - indice) * sizeof(int));

    if (vetor->tamanho <= vetor->capacidade / fatorReducao && vetor->capacidade > capacidadeMinima) {
        diminui_vetor(vetor);
    }
}

void remove_num(_vetor* vetor, int num) {
    if (vetor_vazio(vetor)) {
        exit(EXIT_FAILURE);
    }

    int indice = find(vetor, num);

    while (indice != -1) {
        delete(vetor, indice);
        indice = find(vetor, num);
    }
}

int find(_vetor* vetor, int num) {
    if (vetor_vazio(vetor)) {
        exit(EXIT_FAILURE);
    }

    int indice = -1;

    for (register int i = 0; i < vetor->tamanho; i++) {
        if (*(vetor->dados + i) == num) {
            indice = i;
            break;
        }
    }

    return indice;
}

void verifica_endereco(void* ponteiro) {
    if (ponteiro == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
}
