# Filas

Implementa, em C, uma fila dinâmica utilizando uma lista ligada.

## Fila

~~~c
typedef struct No {
    int dado;
    struct No* prox;
} No;

typedef struct Fila {
    No* inicio;
    No* fim;
} Fila;
~~~

## Funções

* Cria uma fila vazia
~~~c
Fila* cria_fila();
~~~

* Destroi a lista ligada
~~~c
void destroi_lista(No* no);
~~~

* Destroi a fila
~~~c
void destroi_fila(Fila* fila);
~~~

* Imprime a fila
~~~c
void imprime_fila(Fila* fila);
~~~

* Retorna 1 se a fila estiver vazia, 0 caso contrário
~~~c
int empty(Fila* fila);
~~~

* Acrescenta o item ao fim da fila
~~~c
void enqueue(Fila* fila, int num);
~~~

* Remove e retorna o item do começo da fila
~~~c
int dequeue(Fila* fila);
~~~

* Verifica se a memória foi alocada corretamente
~~~c
void verifica_endereco(void* ponteiro);
~~~
