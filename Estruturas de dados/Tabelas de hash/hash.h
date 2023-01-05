typedef struct Par {
    int chave;
    int valor;
    struct Par* prox;
} Par;

typedef struct Tabela {
    Par** dados;
    int capacidade;
} Tabela;

// Cria uma tabela de hash vazia
Tabela* cria_tabela(int capacidade);

// Cria um par chave-valor
Par* cria_par(int chave, int valor);

// Destroi a lista ligada
void destroi_lista(Par* par);

// Destroi a tabela de hash
void destroi_tabela(Tabela* tabela);

// Imprime a tabela de hash
void imprime_tabela(Tabela* tabela);

// Determina o índice da tabela de hash correspondente à chave
int hash(int chave, int capacidade);

// Adiciona o par chave-valor à tabela de hash; caso a chave já exista, atualiza o valor
void add(Tabela* tabela, int chave, int valor);

// Retorna 1 caso a tabela de hash tenha uma entrada com a chave, 0 caso contrário
int exists(Tabela* tabela, int chave);

// Retorna o valor correspondente à chave na tabela de hash, caso exista
int get(Tabela* tabela, int chave);

// Remove a entrada da tabela de hash com a chave, caso exista
void remove_pair(Tabela* tabela, int chave);

// Verifica se a memória foi alocada corretamente
void verifica_endereco(void* ponteiro);
