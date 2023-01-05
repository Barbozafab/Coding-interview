#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "hash.h"

Tabela* cria_tabela(int capacidade) {
    Tabela* tabela = malloc(sizeof(Tabela));
    verifica_endereco(tabela);

    tabela->capacidade = capacidade;
    tabela->dados = malloc(capacidade * sizeof(Par*));
    verifica_endereco(tabela->dados);

    return tabela;
}

Par* cria_par(int chave, int valor) {
    Par* par = malloc(sizeof(Par));
    verifica_endereco(par);

    par->chave = chave;
    par->valor = valor;
    par->prox = NULL;

    return par;
}

void destroi_lista(Par* par) {
    if (par->prox != NULL) {
        destroi_lista(par->prox);
    }

    free(par);
}

void destroi_tabela(Tabela* tabela) {
    for (register int i = 0; i < tabela->capacidade; i++) {
        if (tabela->dados[i] != NULL) {
            destroi_lista(tabela->dados[i]);
        }
    }

    free(tabela->dados);
    free(tabela);
}

void imprime_tabela(Tabela* tabela) {
    printf("{\n");

    for (register int i = 0; i < tabela->capacidade; i++) {
        Par* atual = tabela->dados[i];

        while (atual != NULL) {
            printf(" %d : %d\n", atual->chave, atual->valor);
            atual = atual->prox;
        }
    }

    printf("}\n");
}

int hash(int chave, int capacidade) {
    return chave % capacidade;
}

void add(Tabela* tabela, int chave, int valor) {
    int indice = hash(chave, tabela->capacidade);
    Par* par = cria_par(chave, valor);

    par->prox = tabela->dados[indice];
    tabela->dados[indice] = par;
}

int exists(Tabela* tabela, int chave) {
    int indice = hash(chave, tabela->capacidade);
    Par* atual = tabela->dados[indice];

    while (atual != NULL) {
        if (atual->chave == chave) {
            return 1;
        }

        atual = atual->prox;
    }

    return 0;
}

int get(Tabela* tabela, int chave) {
    int indice = hash(chave, tabela->capacidade);
    Par* atual = tabela->dados[indice];

    while (atual != NULL) {
        if (atual->chave == chave) {
            return atual->valor;
        }

        atual = atual->prox;
    }

    return -1;
}

void remove_pair(Tabela* tabela, int chave) {
    int indice = hash(chave, tabela->capacidade);
    Par* atual = tabela->dados[indice];
    Par* anterior = NULL;

    while (atual != NULL) {
        if (atual->chave == chave) {
            if (anterior == NULL) {
                tabela->dados[indice] = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }

            free(atual);
            return;
        }

        atual = atual->prox;
    }
}

void verifica_endereco(void* ponteiro) {
    if (ponteiro == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
}
