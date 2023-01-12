# Heaps

Implementa, em C, um max-heap.

## Heap

~~~c
typedef struct Heap {
    int* dados;
    int tamanho;
} Heap;
~~~

## Funções

* Caso já não seja, transforma o heap em um max-heap
~~~c
void max_heapify(Heap* heap, int indice);
~~~

* Cria um max-heap a partir de uma lista desordenada
~~~c
Heap* build_max_heap(int* dados, int tamanho);
~~~

* Destroi o max-heap
~~~c
void destroy_max_heap(Heap* heap);
~~~

* Imprime o max-heap
~~~c
void print_heap(Heap* heap);
~~~

* Ordena o vetor utilizando um max-heap
~~~c
void max_heapsort(int* dados, int tamanho);
~~~

* Insere o elemento no max-heap
~~~c
void insert(Heap* heap, int num);
~~~

* Retorna o valor máximo armazenado no max-heap
~~~c
int get_max(Heap* heap);
~~~

* Remove e retorna o valor máximo armazenado no max-heap
~~~c
int extract_max(Heap* heap);
~~~

* Retorna o tamanho do max-heap
~~~c
int get_size(Heap* heap);
~~~

* Remove o elemento no índice indicado do max-heap
~~~c
void remove_node(Heap* heap, int indice);
~~~

* Retorna 1 caso o max-heap seja vazio, 0 caso contrário
~~~c
int is_empty(Heap* heap);
~~~

* Verifica se a memória foi alocada corretamente
~~~c
void verifica_endereco(void* ponteiro);
~~~
