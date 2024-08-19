#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <time.h> 
#include "Quicksort.h" 

int main(void) {
    int capacidade = 150; // Capacidade de produtos
    int numProdutos = 0; //Contador de Produtos cadastrados

    Produtos *produtos = alocaMemoria(capacidade);

    cadastro(produtos, &numProdutos); 

    if (numProdutos > capacidade) {
        capacidade = numProdutos;
        produtos = realocaMemoria(produtos, capacidade); 
    }

    // Calcular o tempo de execução do QuickSort
    clock_t inicio = clock();

    QuickSort(0, numProdutos - 1, produtos);

    clock_t fim = clock();
    double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;

    imprime(produtos, numProdutos);  
    cria_arquivo(produtos, numProdutos);
    printf("Tempo de execução do QuickSort: %.3f segundos\n", tempo_execucao);

    free(produtos);
    return 0;  
}