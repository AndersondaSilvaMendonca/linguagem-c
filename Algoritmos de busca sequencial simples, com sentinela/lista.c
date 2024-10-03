#include <stdio.h>
#include "lista.h"

// Inicializa a lista
void Definir(Lista *L) {
    L->tamanho = 0;
}

// Verifica se a lista está vazia
int Vazia(Lista *L) {
    return L->tamanho == 0;
}

// Destroi a lista
void Destruir(Lista *L) {
    L->tamanho = 0; // Reseta o tamanho, destruindo os dados
}

// Insere um elemento no início da lista
int Inserir_inicio(Lista *L, tipo_elem v) {
    if (Cheia(L)) {
        return 0; // Falha, lista cheia
    }
    for (int i = L->tamanho; i > 0; i--) {
        L->elementos[i] = L->elementos[i - 1]; // Desloca os elementos para a direita
    }
    L->elementos[0] = v; // Insere no início
    L->tamanho++;
    return 1; // Sucesso
}

// Verifica se a lista está cheia
int Cheia(Lista *L) {
    return L->tamanho == TAM;
}

// Retorna o tamanho atual da lista
int Tamanho(Lista *L) {
    return L->tamanho;
}

// Exibe os elementos da lista
void Exibir(Lista *L) {
    if (Vazia(L)) {
        printf("Lista vazia.\n");
        return;
    }
    for (int i = 0; i < L->tamanho; i++) {
        printf("%d ", L->elementos[i]);
    }
    printf("\n");
}

// Insere um elemento no final da lista
int Inserir_final(Lista *L, tipo_elem v) {
    if (Cheia(L)) {
        return 0; // Falha, lista cheia
    }
    L->elementos[L->tamanho] = v;
    L->tamanho++;
    return 1; // Sucesso
}

