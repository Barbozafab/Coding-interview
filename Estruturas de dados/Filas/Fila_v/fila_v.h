typedef struct Fila {
    int* dados;
    int capacidade;
    int tamanho;
    int inicio;
    int fim;
} Fila;

// Cria uma fila vazia
Fila* cria_fila(int capacidade);

// Destroi a fila
void destroi_fila(Fila* fila);

// Imprime a fila
void imprime_fila(Fila* fila);

// Retorna 1 se a fila estiver vazia, 0 caso contrário
int empty(Fila* fila);

// Retorna 1 se a fila estiver cheia, 0 caso contrário
int full(Fila* fila);

// Acrescenta o item ao fim da fila
void enqueue(Fila* fila, int num);

// Remove e retorna o item do começo da fila
int dequeue(Fila* fila);

// Verifica se a memória foi alocada corretamente
void verifica_endereco(void* ponteiro);
