# Tabelas de hash

Implementa, em C, uma tabela de hash dinâmica utilizando um vetor de listas ligadas.

## Tabela de hash

~~~c
typedef struct Par {
    int chave;
    int valor;
    struct Par* prox;
} Par;

typedef struct Tabela {
    Par** dados;
    int capacidade;
} Tabela;
~~~

## Funções

* Cria uma tabela de hash vazia
~~~c
Tabela* cria_tabela(int capacidade);
~~~

* Cria um par chave-valor
~~~c
Par* cria_par(int chave, int valor);
~~~

* Destroi a lista ligada
~~~c
void destroi_lista(Par* par);
~~~

* Destroi a tabela de hash
~~~c
void destroi_tabela(Tabela* tabela);
~~~

* Imprime a tabela de hash
~~~c
void imprime_tabela(Tabela* tabela);
~~~

* Determina o índice da tabela de hash correspondente à chave
~~~c
int hash(int chave, int capacidade);
~~~

* Adiciona o par chave-valor à tabela de hash; caso a chave já exista, atualiza o valor
~~~c
void add(Tabela* tabela, int chave, int valor);
~~~

* Retorna 1 caso a tabela de hash tenha uma entrada com a chave, 0 caso contrário
~~~c
int exists(Tabela* tabela, int chave);
~~~

* Retorna o valor correspondente à chave na tabela de hash, caso exista
~~~c
int get(Tabela* tabela, int chave);
~~~

* Remove a entrada da tabela de hash com a chave, caso exista
~~~c
void remove_key(Tabela* tabela, int chave);
~~~

* Verifica se a memória foi alocada corretamente
~~~c
void verifica_endereco(void* ponteiro);
~~~
