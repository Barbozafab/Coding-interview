# Pilhas

Implementa, em C, uma pilha dinâmica utilizando um vetor de tamanho fixo.

## Pilha

~~~c
typedef struct Pilha {
    int* dados;
    int topo;
    int capacidade;
} Pilha;
~~~

## Funções

* Cria uma pilha vazia
~~~c
Pilha* cria_pilha(int capacidade);
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

* Retorna 1 se a pilha estiver cheia, 0 caso contrário
~~~c
int full(Pilha* pilha);
~~~

* Acrescenta o item ao topo da pilha
~~~c
void push(Pilha* pilha, int num);
~~~

* Remove e retorna o item no topo da pilha
~~~c
int pop(Pilha* pilha);
~~~

* Verifica se a memória foi alocada corretamente
~~~c
void verifica_endereco(void* ponteiro);
~~~
