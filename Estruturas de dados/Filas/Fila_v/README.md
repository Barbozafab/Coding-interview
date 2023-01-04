# Filas

Implementa, em C, uma fila dinâmica utilizando um vetor de tamanho fixo.

## Fila

~~~c
typedef struct Fila {
    int* dados;
    int capacidade;
    int tamanho;
    int inicio;
    int fim;
} Fila;
~~~

## Funções

* Cria uma fila vazia
~~~c
Fila* cria_fila(int capacidade);
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

* Retorna 1 se a fila estiver cheia, 0 caso contrário
~~~c
int full(Fila* fila);
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
