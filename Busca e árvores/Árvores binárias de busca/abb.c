#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "abb.h"

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

void imprime_arvore(No* raiz) {
    if (raiz == NULL) {
        exit(EXIT_FAILURE);
    }

    if (raiz->esquerda != NULL) {
        imprime_arvore(raiz->esquerda);
    }

    printf("%d ", raiz->dado);

    if (raiz->direita != NULL) {
        imprime_arvore(raiz->direita);
    }
}

No* insert(No* raiz, int num) {
    if (raiz == NULL) {
        No* novo = cria_arvore(num);
        raiz = novo;

        return raiz;
    }

    if (raiz->dado > num) {
        raiz->esquerda = insert(raiz->esquerda, num);
    } else {
        raiz->direita = insert(raiz->direita, num);
    }

    return raiz;
}

int get_node_count(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }

    return 1 + get_node_count(raiz->esquerda) + get_node_count(raiz->direita);
}

int is_in_tree(No* raiz, int num) {
    if (raiz == NULL) {
        return 0;
    }

    if (raiz->dado == num) {
        return 1;
    } else if (raiz->dado > num) {
        return is_in_tree(raiz->esquerda, num);
    } else {
        return is_in_tree(raiz->direita, num);
    }
}

int get_height(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }

    int esquerda = get_height(raiz->esquerda);
    int direita = get_height(raiz->direita);

    return 1 + (esquerda > direita ? esquerda : direita);
}

int get_min(No* raiz) {
    if (raiz == NULL) {
        exit(EXIT_FAILURE);
    }

    if (raiz->esquerda == NULL) {
        return raiz->dado;
    }

    return get_min(raiz->esquerda);
}

int get_max(No* raiz) {
    if (raiz == NULL) {
        exit(EXIT_FAILURE);
    }

    if (raiz->direita == NULL) {
        return raiz->dado;
    }

    return get_max(raiz->direita);
}

int is_binary_search_tree(No* raiz) {
    if (raiz == NULL) {
        return 1;
    }

    int esquerda = is_binary_search_tree(raiz->esquerda);
    int direita = is_binary_search_tree(raiz->direita);
    int meio = (raiz->esquerda == NULL || raiz->esquerda->dado <= raiz->dado) && (raiz->direita == NULL || raiz->dado <= raiz->direita->dado);

    return esquerda && direita && meio;
}

No* delete_value(No* raiz, int num) {
    if (raiz == NULL) {
        return raiz;
    }

    if (raiz->dado == num) {
        if (raiz->esquerda == NULL && raiz->direita == NULL) {
            free(raiz);
            raiz = NULL;
        } else if (raiz->esquerda == NULL) {
            No* aux = raiz;
            raiz = raiz->direita;
            free(aux);
        } else if (raiz->direita == NULL) {
            No* aux = raiz;
            raiz = raiz->esquerda;
            free(aux);
        } else {
            raiz->dado = get_min(raiz->direita);
            raiz->direita = delete_value(raiz->direita, raiz->dado);
        }
    } else if (raiz->dado > num) {
        raiz->esquerda = delete_value(raiz->esquerda, num);
    } else {
        raiz->direita = delete_value(raiz->direita, num);
    }

    return raiz;
}

int get_successor(No* raiz, int num) {
    if (raiz == NULL) {
        return -1;
    }

    No* atual = raiz;

    while (atual->dado != num) {
        if (atual == NULL) {
            return -1;
        }

        if (atual->dado > num) {
            atual = atual->esquerda;
        } else {
            atual = atual->direita;
        }
    }

    if (atual->direita == NULL) {
        No* proximo = raiz;
        No* anterior = NULL;

        while (proximo != NULL) {
            if (proximo->dado > num) {
                anterior = proximo;
                proximo = proximo->esquerda;
            } else {
                proximo = proximo->direita;
            }
        }

        return anterior->dado;
    } else {
        return get_min(atual->direita);
    }
}

void verifica_endereco(void* ponteiro) {
    if (ponteiro == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
}
