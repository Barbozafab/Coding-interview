# Listas

Implementa, em C, um vetor dinâmico.

## Vetor

~~~c
typedef struct _vetor {
    int* dados;
    int tamanho, capacidade;
} _vetor;
~~~

## Funções

* Cria um vetor
~~~c
_vetor* cria_vetor(int capacidade);
~~~

* Destroi o vetor
~~~c
void destroi_vetor(_vetor* vetor);
~~~

* Retorna o tamanho do vetor
~~~c
int tamanho_vetor(_vetor* vetor);
~~~

* Retorna a capacidade do vetor
~~~c
int capacidade_vetor(_vetor* vetor);
~~~

* Retorna 1 caso o vetor esteja vazio, 0 caso contrário
~~~c
int vetor_vazio(_vetor* vetor);
~~~

* Aumenta a capacidade do vetor
~~~c
void aumenta_vetor(_vetor* vetor);
~~~

* Diminui a capacidade do vetor
~~~c
void diminui_vetor(_vetor* vetor);
~~~

* Imprime os elementos e dados do vetor
~~~c
void imprime_vetor(_vetor* vetor);
~~~

* Retorna o elemento do vetor na posição indicada, caso exista
~~~c
int at(_vetor* vetor, int indice);
~~~

* Insere o elemento no final do vetor
~~~c
void push(_vetor* vetor, int num);
~~~

* Insere o elemento na posição indicada do vetor
~~~c
void insert(_vetor* vetor, int indice, int num);
~~~

* Insere o elemento no início do vetor
~~~c
void prepend(_vetor* vetor, int num);
~~~

* Remove e retorna o último elemento do vetor, se existir
~~~c
int pop(_vetor* vetor);
~~~

* Remove o elemento na posição indicada do vetor, se existir
~~~c
void delete(_vetor* vetor, int indice);
~~~

* Remove todas as ocorrências do elemento no vetor
~~~c
void remove_num(_vetor* vetor, int num);
~~~

* Retorna a primeira posição em que o elemento aparece no vetor, -1 caso não apareça
~~~c
int find(_vetor* vetor, int num);
~~~

* Verifica se a memória foi alocada corretamente
~~~c
void verifica_endereco(void* ponteiro);
~~~
