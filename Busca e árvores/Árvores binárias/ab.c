#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ab.h"

No* cria_arvore(int num) {
    No* no = malloc(sizeof(No));
    verifica_endereco(no);

    no->dado = num;
    no->esquerda = NULL;
    no->direita = NULL;

    return no;
}

void destroi_arvore(No* raiz) {
    if (raiz == NULL) {
        exit(EXIT_FAILURE);
    }

    if (raiz->esquerda != NULL) {
        destroi_arvore(raiz->esquerda);
    }

    if (raiz->direita != NULL) {
        destroi_arvore(raiz->direita);
    }

    free(raiz);
}

Fila* cria_fila() {
    Fila* fila = malloc(sizeof(Fila));
    verifica_endereco(fila);

    fila->inicio = NULL;
    fila->fim = NULL;

    return fila;
}

Lista* cria_lista(No* no) {
    Lista* lista = malloc(sizeof(Lista));
    verifica_endereco(lista);

    lista->no = no;
    lista->prox = NULL;

    return lista;
}

void destroi_fila(Fila* fila) {
    if (fila == NULL) {
        exit(EXIT_FAILURE);
    }

    free(fila);
}

void insere_fila(Fila* fila, No* no) {
    if (fila == NULL) {
        exit(EXIT_FAILURE);
    }

    Lista* nova = cria_lista(no);

    if (fila->fim != NULL) {
        fila->fim->prox = nova;
    } else {
        fila->inicio = nova;
    }

    fila->fim = nova;
}

No* remove_fila(Fila* fila) {
    if (fila == NULL || fila->inicio == NULL) {
        exit(EXIT_FAILURE);
    }

    Lista* atual = fila->inicio;
    No* no = atual->no;

    if (fila->fim->no == no) {
        fila->fim = NULL;
    }

    fila->inicio = atual->prox;

    free(atual);

    return no;
}

void nivel(No* raiz) {
    Fila* fila = cria_fila();

    insere_fila(fila, raiz);

    while (fila->inicio != NULL) {
        No* no = remove_fila(fila);

        printf("%d ", no->dado);

        if (no->esquerda != NULL) {
            insere_fila(fila, no->esquerda);
        }

        if (no->direita != NULL) {
            insere_fila(fila, no->direita);
        }
    }

    destroi_fila(fila);
}

void in(No* raiz) {
    if (raiz == NULL) {
        exit(EXIT_FAILURE);
    }

    if (raiz->esquerda != NULL) {
        in(raiz->esquerda);
    }

    printf("%d ", raiz->dado);

    if (raiz->direita != NULL) {
        in(raiz->direita);
    }
}

void pos(No* raiz) {
    if (raiz == NULL) {
        exit(EXIT_FAILURE);
    }

    if (raiz->esquerda != NULL) {
        pos(raiz->esquerda);
    }

    if (raiz->direita != NULL) {
        pos(raiz->direita);
    }

    printf("%d ", raiz->dado);
}

void pre(No* raiz) {
    if (raiz == NULL) {
        exit(EXIT_FAILURE);
    }

    printf("%d ", raiz->dado);

    if (raiz->esquerda != NULL) {
        pre(raiz->esquerda);
    }

    if (raiz->direita != NULL) {
        pre(raiz->direita);
    }
}

void inverte(No* raiz) {
    if (raiz == NULL) {
        exit(EXIT_FAILURE);
    }

    if (raiz->esquerda != NULL) {
        inverte(raiz->esquerda);
    }

    if (raiz->direita != NULL) {
        inverte(raiz->direita);
    }

    No* aux = raiz->esquerda;
    raiz->esquerda = raiz->direita;
    raiz->direita = aux;
}

void verifica_endereco(void* ponteiro) {
    if (ponteiro == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
}
