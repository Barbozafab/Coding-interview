# Árvores binárias

Implementa, em C, algoritmos para percorrer uma árvore binária.

## Árvore binária

~~~c
typedef struct No {
    int dado;
    struct No* esquerda;
    struct No* direita;
} No;

typedef struct Lista {
    No* no;
    struct Lista* prox;
} Lista;

typedef struct Fila {
    Lista* inicio;
    Lista* fim;
} Fila;
~~~

## Funções

* Cria uma árvore binária contendo o item
~~~c
No* cria_arvore(int num);
~~~

* Destroi a árvore binária
~~~c
void destroi_arvore(No* raiz);
~~~

* Cria uma fila vazia
~~~c
Fila* cria_fila();
~~~

* Cria nó a ser inserido na fila
~~~c
Lista* cria_lista(No* no);
~~~

* Destroi a lista ligada
~~~c
void destroi_lista(Lista* lista);
~~~

* Destroi a fila
~~~c
void destroi_fila(Fila* fila);
~~~

* Insere nó no fim da fila
~~~c
void insere_fila(Fila* fila, No* no);
~~~

* Remove e retorna nó do começo da fila
~~~c
No* remove_fila(Fila* fila);
~~~

* Percorre a árvore em nível (BFS)
~~~c
void nivel(No* raiz);
~~~

* Percorre a árvore em ordem infixa (DFS)
~~~c
void in(No* raiz);
~~~

* Percorre a árvore em ordem pósfixa (DFS)
~~~c
void pos(No* raiz);
~~~

* Percorre a árvore em ordem préfixa (DFS)
~~~c
void pre(No* raiz);
~~~

* Inverte a árvore binária
~~~c
void inverte(No* raiz);
~~~

* Verifica se a memória foi alocada corretamente
~~~c
void verifica_endereco(void* ponteiro);
~~~
