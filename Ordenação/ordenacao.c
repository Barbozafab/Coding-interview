#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ordenacao.h"

void insertion_sort(int* vetor, int tamanho) {
    for (register int i = 1; i < tamanho; i++) {
        int j = i;

        while (j > 0 && vetor[j - 1] > vetor[j]) {
            int aux = vetor[j];
            vetor[j] = vetor[j - 1];
            vetor[j - 1] = aux;
            j--;
        }
    }
}

void selection_sort(int* vetor, int tamanho) {
    for (register int i = 0; i < tamanho - 1; i++) {
        int menor = i;

        for (register int j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[menor]) menor = j;
        }

        if (menor != i) {
            int aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
        }
    }
}

void bubble_sort(int* vetor, int tamanho) {
    for (register int i = 0; i < tamanho; i++) {
        for (register int j = 0; j < tamanho - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

void merge(int* destino, int* vetor_a, int tamanho_a, int* vetor_b, int tamanho_b) {
    int i = 0, j = 0, k = 0;

    while (i < tamanho_a && j < tamanho_b) {
        if (vetor_a[i] < vetor_b[j]) {
            destino[k] = vetor_a[i];
            i++;
        }
        else {
            destino[k] = vetor_b[j];
            j++;
        }

        k++;
    }

    while (i < tamanho_a) {
        destino[k] = vetor_a[i];
        i++;
        k++;
    }

    while (j < tamanho_b) {
        destino[k] = vetor_b[j];
        j++;
        k++;
    }
}

void merge_sort(int* vetor, int tamanho) {
    if (tamanho > 1) {
        int meio = tamanho / 2;
        int vetor_a[meio];
        int vetor_b[tamanho - meio];

        for (register int i = 0; i < meio; i++) {
            vetor_a[i] = vetor[i];
        }

        for (register int j = meio; j < tamanho; j++) {
            vetor_b[j - meio] = vetor[j];
        }

        merge_sort(vetor_a, meio);
        merge_sort(vetor_b, tamanho - meio);

        merge(vetor, vetor_a, meio, vetor_b, tamanho - meio);
    }
}

void heapify(int* vetor, int tamanho, int indice) {
    int maior = indice;
    int esquerda = 2 * indice + 1;
    int direita = 2 * indice + 2;

    if (esquerda < tamanho && vetor[esquerda] > vetor[maior]) maior = esquerda;
    if (direita < tamanho && vetor[direita] > vetor[maior]) maior = direita;
    if (maior != indice) {
        int aux = vetor[indice];
        vetor[indice] = vetor[maior];
        vetor[maior] = aux;
        heapify(vetor, tamanho, maior);
    }
}

void build_max_heap(int* vetor, int tamanho) {
    for (register int i = tamanho / 2 - 1; i >= 0; i--) heapify(vetor, tamanho, i);
}

void heap_sort(int* vetor, int tamanho) {
    build_max_heap(vetor, tamanho);

    for (register int i = tamanho - 1; i >= 0; i--) {
        int aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;
        heapify(vetor, i, 0);
    }
}

void quick_sort(int* vetor, int inicio, int fim) {
    int esquerda = inicio;
    int direita = fim;
    int pivo = vetor[(inicio + fim) / 2];

    while (esquerda <= direita) {
        while (vetor[esquerda] < pivo && esquerda < fim) esquerda++;
        while (vetor[direita] > pivo && direita > inicio) direita--;

        if (esquerda <= direita) {
            int aux = vetor[esquerda];
            vetor[esquerda] = vetor[direita];
            vetor[direita] = aux;
            esquerda++;
            direita--;
        }
    }

    if (direita > inicio) quick_sort(vetor, inicio, direita);
    if (esquerda < fim) quick_sort(vetor, esquerda, fim);
}
