#ifndef PRODUTOS
#define PRODUTOS

typedef struct produtos Produtos;

Produtos* alocaMemoria(int capacidade);

Produtos* realocaMemoria(Produtos *produtos, int novaCapacidade);

void cadastro(Produtos *produtos, int *numProdutos);

int particiona(int esquerda, int direita, Produtos *produtos);

void imprime(Produtos *produtos, int numProdutos);

void QuickSort(int inicio, int final, Produtos *produtos);

#endif
