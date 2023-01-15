// Implementa o algoritmo `insertion sort`
void insertion_sort(int* vetor, int tamanho);

// Implementa o algoritmo `selection sort`
void selection_sort(int* vetor, int tamanho);

// Implementa o algoritmo `bubble sort`
void bubble_sort(int* vetor, int tamanho);

// Mescla dois vetores, inserindo os elementos na ordem correta
void merge(int* destino, int* vetor_a, int tamanho_a, int* vetor_b, int tamanho_b);

// Implementa o algoritmo `merge sort`
void merge_sort(int* vetor, int tamanho);

// Transforma o vetor em um `max heap`
void heapify(int* vetor, int tamanho, int i);

// Constroi um `max heap` a partir de um vetor
void build_max_heap(int* vetor, int tamanho);

// Implementa o algoritmo `heap sort`
void heap_sort(int* vetor, int tamanho);

// Implementa o algoritmo `quick sort`
void quick_sort(int* vetor, int inicio, int fim);
