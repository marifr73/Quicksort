#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>
#include "Quicksort.h"

struct produtos {  
    char nome[20];  
    int codigo;  
    float preco;  
};  

Produtos* alocaMemoria(int capacidade) {
    Produtos *produtos = malloc(capacidade * sizeof(Produtos));
    if (produtos == NULL) {
        printf("No memory!\n");
        exit(1);
    }
    return produtos;
}

Produtos* realocaMemoria(Produtos *produtos, int novaCapacidade) {
    produtos = realloc(produtos, novaCapacidade * sizeof(Produtos));
    if (produtos == NULL) {
        printf("No memory!\n");
        exit(1);
    }
    return produtos;
}

void cadastro(Produtos *produtos, int *numProdutos) {  
    int opcao;  

    do {  
        printf("\nEscolha uma opção:\n");  
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

int particiona(int estquerda, int dierita, Produtos *produtos){
    Produtos pivo = produtos[dierita];
    int b = estquerda - 1;
    int a;
    for(a = estquerda; a < dierita; a++){
        if(strcmp(produtos[a].nome, pivo.nome) <= 0){
            b++;
            Produtos temp = produtos[b];
            produtos[b] = produtos[a];
            produtos[a] = temp;
        }
    }

    Produtos temp = produtos[b + 1];
    produtos[b + 1] = produtos[dierita];
    produtos[dierita] = temp;
    return b + 1;
}

void imprime(Produtos *produtos, int numProdutos) {  
    int i;
    printf("Produtos Cadastrados: \n");  
    for (i = 0; i < numProdutos; i++) {  
        printf("\nProduto %d:\n", i + 1);  
        printf("Nome: %s\nCódigo: %d\nPreço: %.2f\n", produtos[i].nome, produtos[i].codigo, produtos[i].preco);  
    }  
}  

void QuickSort(int inicio, int final, Produtos *produtos){
    if(inicio < final){
        int pivo = particiona(inicio, final, produtos);
        QuickSort(inicio, pivo - 1, produtos);
        QuickSort(pivo + 1, final, produtos);
    }
}
