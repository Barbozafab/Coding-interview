typedef struct ll {
    int dado;
    struct ll* prox;
} ll;

// Cria uma lista ligada contendo o elemento recebido
ll* cria_ll(int num);

// Destroi a lista ligada
void destroi_ll(ll* lista);

// Imprime a lista ligada
void imprimir_ll(ll* lista);

// Retorna o número de elementos na lista ligada
int size(ll* lista);

// Retorna 1 caso a lista ligada seja vazia, 0 caso contrário
int empty(ll* lista);

// Retorna o valor do dado na posição indicada
int value_at(ll* lista, int indice);

// Adiciona o elemento no início da lista ligada
void push_front(ll** lista, int num);

// Remove e retorna o primeiro item da lista
int pop_front(ll** lista);

// Adiciona o elemento no fim da lista ligada
void push_back(ll** lista, int num);

// Remove e retorna o último item da lista ligada
int pop_back(ll** lista);

// Retorna o valor do primeiro item da lista
int front(ll* lista);

// Retorna o valor do último item da lista
int back(ll* lista);

// Insere o elemento na posição indicada da lista ligada
void insert(ll** lista, int indice, int num);

// Remove o item na posição indicada da lista ligada
void erase(ll** lsita, int indice);

// Retorna o valor do item a n posições do final da lista ligada
int value_from_n(ll* lista, int n);

// Inverte a lista ligada
void reverse(ll** lista);

// Remove a primeira ocorrência do elemento na lista ligada, se existir
void remove_value(ll** lista, int num);

// Verifica se a memória foi alocada corretamente
void verifica_endereco(void* ponteiro);
