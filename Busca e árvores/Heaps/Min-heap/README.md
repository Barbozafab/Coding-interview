# Heaps

Implementa, em C, um min-heap.

## Heap

~~~c
typedef struct Heap {
    int* dados;
    int tamanho;
} Heap;
~~~

## Funções

* Caso já não seja, transforma o heap em um min-heap
~~~c
void min_heapify(Heap* heap, int indice);
~~~

* Cria um min-heap a partir de uma lista desordenada
~~~c
Heap* build_min_heap(int* dados, int tamanho);
~~~

* Destroi o max-heap
~~~c
void destroy_min_heap(Heap* heap);
~~~

* Imprime o min-heap
~~~c
void print_heap(Heap* heap);
~~~

* Ordena o vetor utilizando um min-heap
~~~c
void min_heapsort(int* dados, int tamanho);
~~~

* Insere o elemento no min-heap
~~~c
void insert(Heap* heap, int num);
~~~

* Retorna o valor mínimo armazenado no min-heap
~~~c
int get_min(Heap* heap);
~~~

* Remove e retorna o valor mínimo armazenado no min-heap
~~~c
int extract_min(Heap* heap);
~~~

* Retorna o tamanho do min-heap
~~~c
int get_size(Heap* heap);
~~~

* Remove o elemento no índice indicado do min-heap
~~~c
void remove_node(Heap* heap, int indice);
~~~

* Retorna 1 caso o min-heap seja vazio, 0 caso contrário
~~~c
int is_empty(Heap* heap);
~~~

* Verifica se a memória foi alocada corretamente
~~~c
void verifica_endereco(void* ponteiro);
~~~
