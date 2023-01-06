#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ab.h"

int main(int argc, char const* argv[]) {
    No* a = cria_arvore(0);
    No* b = cria_arvore(1);
    No* c = cria_arvore(2);
    No* d = cria_arvore(3);
    No* e = cria_arvore(4);
    No* f = cria_arvore(5);
    No* g = cria_arvore(6);
    No* h = cria_arvore(7);
    No* i = cria_arvore(8);

    f->esquerda = b;
    f->direita = g;
    b->esquerda = a;
    b->direita = d;
    d->esquerda = c;
    d->direita = e;
    g->direita = i;
    i->esquerda = h;

    printf("Nível: ");
    nivel(f);
    printf("\n");
    printf("Infixa: ");
    in(f);
    printf("\n");
    printf("Pósfixa: ");
    pos(f);
    printf("\n");
    printf("Préfixa: ");
    pre(f);
    printf("\n");

    inverte(f);
    printf("Nível (invertida): ");
    nivel(f);
    printf("\n");
    printf("Infixa (invertida): ");
    in(f);
    printf("\n");
    printf("Pósfixa (invertida): ");
    pos(f);
    printf("\n");
    printf("Préfixa (invertida): ");
    pre(f);
    printf("\n");

    destroi_arvore(f);

    return EXIT_SUCCESS;
}

