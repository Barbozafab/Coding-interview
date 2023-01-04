typedef struct Pilha {
    int* dados;
    int topo;
    int capacidade;
} Pilha;

// Cria uma pilha vazia
Pilha* cria_pilha(int capacidade);

// Destroi a pilha
void destroi_pilha(Pilha* pilha);

// Imprime os itens na pilha
void imprime_pilha(Pilha* pilha);

// Retorna 1 se a pilha estiver vazia, 0 caso contrário
int empty(Pilha* pilha);

// Retorna 1 se a pilha estiver cheia, 0 caso contrário
int full(Pilha* pilha);

// Acrescenta o item ao topo da pilha
void push(Pilha* pilha, int num);

// Remove e retorna o item no topo da pilha
int pop(Pilha* pilha);

// Verifica se a memória foi alocada corretamente
void verifica_endereco(void* ponteiro);