#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char autor[30];
    char titulo[30];
    char ISBN[13];
    int ano;
    int num_exemplares_total;
    int num_exemplares_disponiveis;
} Livro;

Livro livros[MAX];
int num_livros = 0;

void carregarLivros() {
    FILE *f = fopen("livros.txt", "r");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    while (fscanf(f, "%s %s %s %d %d %d\n", livros[num_livros].autor, livros[num_livros].titulo,
                  livros[num_livros].ISBN, &livros[num_livros].ano, &livros[num_livros].num_exemplares_total,
                  &livros[num_livros].num_exemplares_disponiveis) != EOF) {
        num_livros++;
    }
    
    fclose(f);
}

void salvarLivros() {
    FILE *f = fopen("livros.txt", "w");
    if (f == NULL) {
        printf("Erro ao salvar o arquivo.\n");
        return;
    }
    
    for (int i = 0; i < num_livros; i++) {
        fprintf(f, "%s %s %s %d %d %d\n", livros[i].autor, livros[i].titulo, livros[i].ISBN, livros[i].ano,
                livros[i].num_exemplares_total, livros[i].num_exemplares_disponiveis);
    }
    
    fclose(f);
}

void listarLivros() {
    printf("Lista de Livros:\n");
    for (int i = 0; i < num_livros; i++) {
        printf("%s, %s, %s, %d, Total: %d, Disponiveis: %d\n", livros[i].autor, livros[i].titulo, livros[i].ISBN,
               livros[i].ano, livros[i].num_exemplares_total, livros[i].num_exemplares_disponiveis);
    }
}

void adicionarLivro() {
    if (num_livros >= MAX) {
        printf("Erro: Limite de livros atingido.\n");
        return;
    }

    printf("Digite o autor: ");
    scanf("%s", livros[num_livros].autor);
    printf("Digite o titulo: ");
    scanf("%s", livros[num_livros].titulo);
    printf("Digite o ISBN: ");
    scanf("%s", livros[num_livros].ISBN);
    printf("Digite o ano: ");
    scanf("%d", &livros[num_livros].ano);
    printf("Digite o numero de exemplares total: ");
    scanf("%d", &livros[num_livros].num_exemplares_total);
    
    livros[num_livros].num_exemplares_disponiveis = livros[num_livros].num_exemplares_total;
    num_livros++;
}

void excluirLivro() {
    char titulo[30];
    printf("Digite o titulo do livro a ser excluido: ");
    scanf("%s", titulo);
    
    for (int i = 0; i < num_livros; i++) {
        if (strcmp(livros[i].titulo, titulo) == 0) {
            for (int j = i; j < num_livros - 1; j++) {
                livros[j] = livros[j + 1];
            }
            num_livros--;
            printf("Livro excluido com sucesso.\n");
            return;
        }
    }
    printf("Livro nao encontrado.\n");
}

void atualizarLivro() {
    char titulo[30];
    printf("Digite o titulo do livro a ser atualizado: ");
    scanf("%s", titulo);
    
    for (int i = 0; i < num_livros; i++) {
        if (strcmp(livros[i].titulo, titulo) == 0) {
            printf("Atualize as informacoes:\n");
            printf("Digite o autor: ");
            scanf("%s", livros[i].autor);
            printf("Digite o ISBN: ");
            scanf("%s", livros[i].ISBN);
            printf("Digite o ano: ");
            scanf("%d", &livros[i].ano);
            printf("Digite o numero de exemplares total: ");
            scanf("%d", &livros[i].num_exemplares_total);
            livros[i].num_exemplares_disponiveis = livros[i].num_exemplares_total;
            printf("Informacoes atualizadas com sucesso.\n");
            return;
        }
    }
    printf("Livro nao encontrado.\n");
}

void realizarEmprestimo() {
    char titulo[30];
    printf("Digite o titulo do livro para emprestimo: ");
    scanf("%s", titulo);

    for (int i = 0; i < num_livros; i++) {
        if (strcmp(livros[i].titulo, titulo) == 0) {
            if (livros[i].num_exemplares_disponiveis > 0) {
                livros[i].num_exemplares_disponiveis--;
                printf("Emprestimo realizado com sucesso.\n");
            } else {
                printf("Nenhum exemplar disponivel.\n");
            }
            return;
        }
    }
    printf("Livro nao encontrado.\n");
}

void realizarDevolucao() {
    char titulo[30];
    printf("Digite o titulo do livro para devolucao: ");
    scanf("%s", titulo);

    for (int i = 0; i < num_livros; i++) {
        if (strcmp(livros[i].titulo, titulo) == 0) {
            if (livros[i].num_exemplares_disponiveis < livros[i].num_exemplares_total) {
                livros[i].num_exemplares_disponiveis++;
                printf("Devolucao realizada com sucesso.\n");
            } else {
                printf("Todos os exemplares ja estao disponiveis.\n");
            }
            return;
        }
    }
    printf("Livro nao encontrado.\n");
}

int main() {
    int opcao;
    
    carregarLivros();
    
    do {
        printf("\nMenu:\n");
        printf("1. Listar todos os livros\n");
        printf("2. Adicionar um novo livro\n");
        printf("3. Excluir um livro\n");
        printf("4. Atualizar informacoes de um livro\n");
        printf("5. Realizar emprestimo\n");
        printf("6. Realizar devolucao\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listarLivros();
                break;
            case 2:
                adicionarLivro();
                break;
            case 3:
                excluirLivro();
                break;
            case 4:
                atualizarLivro();
                break;
            case 5:
                realizarEmprestimo();
                break;
            case 6:
                realizarDevolucao();
                break;
            case 0:
                salvarLivros();
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
    
    return 0;
    system("pause");
}

