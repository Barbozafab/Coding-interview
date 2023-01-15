# Ordenação

Implementa, em C, algoritmos de ordenação de vetores.

## Funções

* Implementa o algoritmo `insertion sort`
~~~c
void insertion_sort(int* vetor, int tamanho);
~~~

* Implementa o algoritmo `selection sort`
~~~c
void selection_sort(int* vetor, int tamanho);
~~~

* Implementa o algoritmo `bubble sort`
~~~c
void bubble_sort(int* vetor, int tamanho);
~~~

* Mescla dois vetores, inserindo os elementos na ordem correta
~~~c
void merge(int* destino, int* vetor_a, int tamanho_a, int* vetor_b, int tamanho_b);
~~~

* Implementa o algoritmo `merge sort`
~~~c
void merge_sort(int* vetor, int tamanho);
~~~

* Transforma o vetor em um `max heap`
~~~c
void heapify(int* vetor, int tamanho, int i);
~~~

* Constroi um `max heap` a partir de um vetor
~~~c
void build_max_heap(int* vetor, int tamanho);
~~~

* Implementa o algoritmo `heap sort`
~~~c
void heap_sort(int* vetor, int tamanho);
~~~

* Implementa o algoritmo `quick sort`
~~~c
void quick_sort(int* vetor, int inicio, int fim);
~~~
