# Pilhas

Implementa, em C, uma pilha dinâmica utilizando uma lista ligada.

## Pilha

~~~c
typedef struct No {
    int dado;
    struct No* prox;
} No;

typedef struct Pilha {
    No* topo;
} Pilha;
~~~

## Funções

* Cria uma pilha vazia
~~~c
Pilha* cria_pilha();
~~~

* Destroi a lista ligada
~~~c
void destroi_lista(No* no);
~~~

* Destroi a pilha
~~~c
void destroi_pilha(Pilha* pilha);
~~~

* Imprime os itens na pilha
~~~c
void imprime_pilha(Pilha* pilha);
~~~

* Retorna 1 se a pilha estiver vazia, 0 caso contrário
~~~c
int empty(Pilha* pilha);
~~~

* Acrescenta o item ao topo da pilha
~~~c
void push(Pilha* pilha, int num);
~~~

* Remove o item no topo da pilha
~~~c
int pop(Pilha* pilha);
~~~

* Verifica se a memória foi alocada corretamente
~~~c
void verifica_endereco(void* ponteiro);
~~~
