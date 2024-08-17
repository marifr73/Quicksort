#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>
#include "Quicksort.h"

int main(void) {
    int capacidade = 150;

    Produtos *produtos = alocaMemoria(capacidade);

    int numProdutos = 0; // Contador de produtos cadastrados  

    cadastro(produtos, &numProdutos); 

    if (numProdutos > capacidade) {
        capacidade = numProdutos;
        produtos = realocaMemoria(produtos, capacidade);
    }

    QuickSort(0, numProdutos - 1, produtos);

    imprime(produtos, numProdutos);  

    free(produtos);
    return 0;  
}