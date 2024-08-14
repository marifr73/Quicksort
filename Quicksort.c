#include <stdio.h>  
#include <stdlib.h>  

typedef struct produtos {  
    char nome[20];  
    int codigo;  
    float preco;  
} Produtos;  

void cadastro(Produtos *produtos, int *numProdutos) {  
    int opcao;  

    do {  
        printf("Escolha uma opção:\n");  
        printf("1 - Cadastrar produto\n2 - Sair\n");  
        scanf("%d", &opcao);  

        if (opcao == 1) {  
            printf("Informe o nome do produto: ");  
            scanf(" %[^\n]", produtos[*numProdutos].nome);  
            printf("Informe o código do produto: ");  
            scanf("%d", &produtos[*numProdutos].codigo);  
            printf("Informe o preço do produto: ");  
            scanf("%f", &produtos[*numProdutos].preco);  
            (*numProdutos)++;  
        }  
    } while (opcao != 2);  
}  

void imprime(Produtos *produtos, int numProdutos) {  
    int i;
    printf("Produtos Cadastrados: \n");  
    for (i = 0; i < numProdutos; i++) {  
        printf("\nProduto %d:\n", i + 1);  
        printf("Nome: %s\nCódigo: %d\nPreço: %.2f\n", produtos[i].nome, produtos[i].codigo, produtos[i].preco);  
    }  
}  

int main(void) {
    Produtos *produtos = malloc(sizeof(Produtos));
    if(produtos == NULL){
        printf("No memory!");
        exit (1);
    }

    int numProdutos = 0; // Contador de produtos cadastrados  

    cadastro(produtos, &numProdutos);  
    imprime(produtos, numProdutos);  

    free(produtos);
    return 0;  
}  
