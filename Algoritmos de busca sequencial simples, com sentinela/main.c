#include <stdio.h>
#include "lista.h"

int main() {
    Lista minhaLista;
    tipo_elem valor;
    int opcao;

    // Inicializa a lista
    Definir(&minhaLista);

    do {
        printf("\n--- Menu ---\n");
        printf("1. Inserir no inicio\n");
        printf("2. Inserir no final\n");
        printf("3. Exibir lista\n");
        printf("4. Verificar se esta cheia\n");
        printf("5. Verificar se esta vazia\n");
        printf("6. Tamanho da lista\n");
        printf("7. Destruir lista\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor para inserir no inicio: ");
                scanf("%d", &valor);
                if (Inserir_inicio(&minhaLista, valor)) {
                    printf("Valor inserido com sucesso no início.\n");
                } else {
                    printf("Falha ao inserir. Lista cheia.\n");
                }
                break;

            case 2:
                printf("Digite o valor para inserir no final: ");
                scanf("%d", &valor);
                if (Inserir_final(&minhaLista, valor)) {
                    printf("Valor inserido com sucesso no final.\n");
                } else {
                    printf("Falha ao inserir. Lista cheia.\n");
                }
                break;

            case 3:
                printf("Elementos da lista: ");
                Exibir(&minhaLista);
                break;

            case 4:
                if (Cheia(&minhaLista)) {
                    printf("A lista esta cheia.\n");
                } else {
                    printf("A lista nao esta cheia.\n");
                }
                break;

            case 5:
                if (Vazia(&minhaLista)) {
                    printf("A lista esta vazia.\n");
                } else {
                    printf("A lista nao esta vazia.\n");
                }
                break;

            case 6:
                printf("Tamanho da lista: %d\n", Tamanho(&minhaLista));
                break;

            case 7:
                Destruir(&minhaLista);
                printf("Lista destruída.\n");
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}

