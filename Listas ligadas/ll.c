#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ll.h"

ll* cria_ll(int num) {
    ll* lista = malloc(sizeof(ll));
    verifica_endereco(lista);

    lista->dado = num;
    lista->prox = NULL;
    return lista;
}

void destroi_ll(ll* lista) {
    if (lista->prox != NULL) {
        destroi_ll(lista->prox);
    }

    free(lista);
}

void imprimir_ll(ll* lista) {
    for (ll* atual = lista; atual != NULL; atual = atual->prox) {
        printf("[%d] -> ", atual->dado);
    }

    printf("\n");
}

int size(ll* lista) {
    int tamanho = 0;

    for (ll* atual = lista; atual != NULL; atual = atual->prox) {
        tamanho += 1;
    }

    return tamanho;
}

int empty(ll* lista) {
    if (lista == NULL) {
        return 1;
    }

    return 0;
}

int value_at(ll* lista, int indice) {
    ll* atual = lista;

    if (indice < 0) {
        exit(EXIT_FAILURE);
    }

    for (register int i = 0; i < indice; i++) {
        if (atual == NULL) {
            exit(EXIT_FAILURE);
        }

        atual = atual->prox;
    }

    return atual->dado;

    // if (indice == 0) {
    //     return lista->dado;
    // }

    // if (lista->prox == NULL) {
    //     exit(EXIT_FAILURE);
    // }

    // return value_at(lista->prox, indice - 1);
}

void push_front(ll** lista, int num) {
    ll* nova = cria_ll(num);
    nova->prox = *lista;

    *lista = nova;
}

int pop_front(ll** lista) {
    if (*lista == NULL) {
        exit(EXIT_FAILURE);
    }

    int num = (*lista)->dado;
    ll* aux = *lista;
    *lista = (*lista)->prox;

    free(aux);

    return num;
}

void push_back(ll** lista, int num) {
    ll* nova = cria_ll(num);

    if (*lista == NULL) {
        *lista = nova;
        return;
    }

    ll* atual = *lista;

    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    atual->prox = nova;
}

int pop_back(ll** lista) {
    if (*lista == NULL) {
        exit(EXIT_FAILURE);
    }

    ll* atual = *lista;
    ll* anterior = NULL;

    while (atual->prox != NULL) {
        anterior = atual;
        atual = atual->prox;
    }

    int num = atual->dado;

    if (anterior == NULL) {
        *lista = NULL;
    } else {
        anterior->prox = NULL;
    }

    free(atual);

    return num;
}

int front(ll* lista) {
    if (lista == NULL) {
        exit(EXIT_FAILURE);
    }

    return lista->dado;
}

int back(ll* lista) {
    if (lista == NULL) {
        exit(EXIT_FAILURE);
    }

    ll* atual = lista;

    while(atual->prox != NULL) {
        atual = atual->prox;
    }

    return atual->dado;
}

void insert(ll** lista, int indice, int num) {
    if (indice < 0) {
        exit(EXIT_FAILURE);
    }

    ll* nova = cria_ll(num);

    if (*lista == NULL) {
        if (indice == 0) {
            *lista = nova;
        } else {
            exit(EXIT_FAILURE);
        }
    }

    ll* atual = *lista;
    ll* anterior = NULL;

    for (register int i = 0; i < indice; i++) {
        if (atual == NULL) {
            exit(EXIT_FAILURE);
        }

        anterior = atual;
        atual = atual->prox;
    }

    if (anterior == NULL) {
        nova->prox = *lista;
        *lista = nova;
    } else {
        nova->prox = atual;
        anterior->prox = nova;
    }
}

void erase(ll** lista, int indice) {
    if (indice < 0 || *lista == NULL) {
        exit(EXIT_FAILURE);
    }

    ll* atual = *lista;
    ll* anterior = NULL;

    for (register int i = 0; i < indice; i++) {
        if (atual == NULL) {
            exit(EXIT_FAILURE);
        }

        anterior = atual;
        atual = atual->prox;
    }

    if (anterior == NULL) {
        *lista = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
}

int value_from_n(ll* lista, int n) {
    int tamanho = size(lista);

    if (n >= tamanho || n < 0) {
        exit(EXIT_FAILURE);
    }

    return value_at(lista, tamanho - n - 1);
}

void reverse(ll** lista) {
    if (*lista == NULL) {
        exit(EXIT_FAILURE);
    }

    ll* atual = *lista;
    ll* anterior = NULL;
    ll* proximo = NULL;

    while (atual != NULL) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    *lista = anterior;
}

void remove_value(ll** lista, int num) {
    if (*lista == NULL) {
        exit(EXIT_FAILURE);
    }

    ll* atual = *lista;
    ll* anterior = NULL;

    while (atual != NULL) {
        if (atual->dado == num) {
            if (anterior == NULL) {
                *lista = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }

            free(atual);
            return;
        }

        anterior = atual;
        atual = atual->prox;
    }
}

void verifica_endereco(void* ponteiro) {
    if (ponteiro == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
}
