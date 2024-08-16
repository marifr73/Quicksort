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

int particiona(int estquerda, int dierita, Produtos *produtos){
    Produtos pivo = produtos[dierita];
    int b = -1;
    int a;
    for(a = estquerda; a < dierita; a++){
        if(produtos[a].nome <= pivo.nome){
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

int main(void) {
    int capacidade = 150;
    int numProdutos = 0; // Contador de produtos cadastrados 
    
    Produtos *produtos = malloc(capacidade * sizeof(Produtos));
    if(produtos == NULL){
        printf("No memory!");
        exit (1);
    }
    
    cadastro(produtos, &numProdutos);
    
    if (numProdutos > capacidade) {
        capacidade = numProdutos;
        produtos = realloc(produtos, capacidade * sizeof(Produtos));
        if (produtos == NULL) {
            printf("Sem memória disponível!\n");
            exit(1);
        }
    }
    
    QuickSort(0, numProdutos - 1, produtos);
    
    imprime(produtos, numProdutos);  

    free(produtos);
    return 0;  
}
