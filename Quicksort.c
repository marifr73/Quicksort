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
    char opcao;  

    do {  
        printf("\nEscolha uma opção:\n");  
        printf("1 - Cadastrar produto\n2 - Sair\n");  
        scanf(" %c", &opcao);  
        getchar();
        if (opcao == '1') {  
            // Verifica se a contagem de produtos excede o limite  
            if (*numProdutos >= 150) {  
                printf("Limite de produtos atingido!\n");   
            }  

            printf("\nInforme o nome do produto: ");  
            scanf(" %[^\n]", produtos[*numProdutos].nome);  
            printf("Informe o código do produto: ");  
            scanf("%d", &produtos[*numProdutos].codigo);  
            printf("Informe o preço do produto: ");  
            scanf("%f", &produtos[*numProdutos].preco);  
            (*numProdutos)++;  
        }  

        else if(opcao < '1' || opcao > '2') {
            printf("Opção não cadastrada, por favor selecione outro número!\n");
        }

    } while (opcao != '2');  
}

int divisao(int esquerda, int direita, Produtos *produtos){
    Produtos pivo = produtos[direita];
    int b = esquerda - 1;
    int a;
    for(a = esquerda; a < direita; a++){
        if(strcmp(produtos[a].nome, pivo.nome) < 0){
            b++;
            Produtos temp = produtos[b];
            produtos[b] = produtos[a];   
            produtos[a] = temp;
        }
    }

    Produtos temp = produtos[b + 1];
    produtos[b + 1] = produtos[direita];
    produtos[direita] = temp;
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
        int pivo = divisao(inicio, final, produtos);
        QuickSort(inicio, pivo - 1, produtos);
        QuickSort(pivo + 1, final, produtos);
    }
}

void cria_arquivo(Produtos *produtos, int numProdutos) { 
    int i;

    FILE *fp = fopen("PRODUTOS.txt", "w");  
    if(fp == NULL) {  
        printf("O arquivo não foi criado!\n");  
        exit(1);   
    } else {  
        printf("O arquivo foi criado!\n");  
    }  

    for (i = 0; i < numProdutos; i++) { 
        fprintf(fp, "Produto %d: \n", i + 1); 
        fprintf(fp, "Nome: %s\nCódigo: %d\nPreço: %.2f\n\n", produtos[i].nome, produtos[i].codigo, produtos[i].preco);  
    }  

    fclose(fp); // Fecha o arquivo  
}