#ifndef LISTA_H
#define LISTA_H

#define TAM 100 // Tamanho máximo da lista
typedef int tipo_elem;

typedef struct {
    tipo_elem elementos[TAM];
    int tamanho;
} Lista;

// Funções
void Definir(Lista *L);
int Vazia(Lista *L);
void Destruir(Lista *L);
int Inserir_inicio(Lista *L, tipo_elem v);
int Cheia(Lista *L);
int Tamanho(Lista *L);
void Exibir(Lista *L);
int Inserir_final(Lista *L, tipo_elem v);

#endif

