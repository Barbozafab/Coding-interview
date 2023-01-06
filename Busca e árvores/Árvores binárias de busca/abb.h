typedef struct No {
    int dado;
    struct No* esquerda;
    struct No* direita;
} No;

// Cria uma árvore binária de busca contendo o item
No* cria_arvore(int num);

// Destroi a árvore binária de busca
void destroi_arvore(No* raiz);

// Imprime a árvore binária de busca (infixa)
void imprime_arvore(No* raiz);

// Insere o item na árvore binária de busca
No* insert(No* raiz, int num);

// Retorna a quantidade de nós na árvore binária de busca
int get_node_count(No* raiz);

// Retorna 1 se o item estiver na árvore binária de busca, 0 caso contrário
int is_in_tree(No* raiz, int num);

// Retorna a altura da árvore binária de busca
int get_height(No* raiz);

// Retorna o menor valor armazenado na árvore
int get_min(No* raiz);

// Retorna o maior valor armazenado na árvore
int get_max(No* raiz);

// Retorna 1 se a árvore binária for uma árvore binária de busca, 0 caso contrário
int is_binary_search_tree(No* raiz);

// Remove o item da árvore binária de busca, se existir
No* delete_value(No* raiz, int num);

// Retorna o sucessor do item na árvore binária de busca, se existir, -1 caso contrário
int get_successor(No* raiz, int num);

// Verifica se a memória foi alocada corretamente
void verifica_endereco(void* ponteiro);
