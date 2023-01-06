# Árvores binárias de busca

Implementa, em C, uma árvore binária de busca.

## Árvore binária de busca

~~~c
typedef struct No {
    int dado;
    struct No* esquerda;
    struct No* direita;
} No;
~~~

## Funções

* Cria uma árvore binária de busca contendo o item
~~~c
No* cria_arvore(int num);
~~~

* Destroi a árvore binária de busca
~~~c
void destroi_arvore(No* raiz);
~~~

* Imprime a árvore binária de busca (infixa)
~~~c
void imprime_arvore(No* raiz);
~~~

* Insere o item na árvore binária de busca
~~~c
No* insert(No* raiz, int num);
~~~

* Retorna a quantidade de nós na árvore binária de busca
~~~c
int get_node_count(No* raiz);
~~~

* Retorna 1 se o item estiver na árvore binária de busca, 0 caso contrário
~~~c
int is_in_tree(No* raiz, int num);
~~~

* Retorna a altura da árvore binária de busca
~~~c
int get_height(No* raiz);
~~~

* Retorna o menor valor armazenado na árvore
~~~c
int get_min(No* raiz);
~~~

* Retorna o maior valor armazenado na árvore
~~~c
int get_max(No* raiz);
~~~

* Retorna 1 se a árvore binária for uma árvore binária de busca, 0 caso contrário
~~~c
int is_binary_search_tree(No* raiz);
~~~

* Remove o item da árvore binária de busca, se existir
~~~c
No* delete_value(No* raiz, int num);
~~~

* Retorna o sucessor do item na árvore binária de busca, se existir, -1 caso contrário
~~~c
int get_successor(No* raiz, int num);
~~~

* Verifica se a memória foi alocada corretamente
~~~c
void verifica_endereco(void* ponteiro);
~~~
