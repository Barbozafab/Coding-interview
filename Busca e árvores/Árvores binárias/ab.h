typedef struct No {
    int dado;
    struct No* esquerda;
    struct No* direita;
} No;

typedef struct Lista {
    No* no;
    struct Lista* prox;
} Lista;

typedef struct Fila {
    Lista* inicio;
    Lista* fim;
} Fila;

// Cria uma árvore binária contendo o item
No* cria_arvore(int num);

// Destroi a árvore binária
void destroi_arvore(No* raiz);

// Cria uma fila vazia
Fila* cria_fila();

// Cria nó a ser inserido na fila
Lista* cria_lista(No* no);

// Destroi a lista ligada
void destroi_lista(Lista* lista);

// Destroi a fila
void destroi_fila(Fila* fila);

// Insere nó no fim da fila
void insere_fila(Fila* fila, No* no);

// Remove e retorna nó do começo da fila
No* remove_fila(Fila* fila);

// Percorre a árvore em nível (BFS)
void nivel(No* raiz);

// Percorre a árvore em ordem infixa (DFS)
void in(No* raiz);

// Percorre a árvore em ordem pósfixa (DFS)
void pos(No* raiz);

// Percorre a árvore em ordem préfixa (DFS)
void pre(No* raiz);

// Inverte a árvore binária
void inverte(No* raiz);

// Verifica se a memória foi alocada corretamente
void verifica_endereco(void* ponteiro);
