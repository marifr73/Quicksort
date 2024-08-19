#ifndef PRODUTOS  
#define PRODUTOS  

/* Definição da struct Produtos que representa um produto com nome, código e preço */
typedef struct produtos Produtos;  

/* Função que aloca memória para um vetor de produtos com a capacidade de 150 produtos.  
    Retorna um ponteiro para o vetor de Produtos alocado.  */
Produtos* alocaMemoria(int capacidade);

/* Função que realoca a memória de um vetor de produtos existente para uma nova capacidade.  
    Retorna um ponteiro para o vetor de Produtos realocado. */ 
Produtos* realocaMemoria(Produtos *produtos, int novaCapacidade);  

/* Função que permite o cadastro de produtos. Solicita ao usuário as informações necessárias  
    para o cadastro dos produtos e atualiza o contador de produtos cadastrados. */ 
void cadastro(Produtos *produtos, int *numProdutos);  

/* Função que divide o vetor de produtos com base no critério de ordenação (nomes dos produtos).  
    Utiliza o último elemento como pivô e organiza os produtos no vetor.
    Retorna o índice do pivô após a divisão. */
int divisao(int esquerda, int direita, Produtos *produtos);  

/* Função que imprime a lista de produtos cadastrados, mostrando nome, código e preço de cada um.  
    Recebe o vetor de produtos e o número total de produtos. */ 
void imprime(Produtos *produtos, int numProdutos);  

/* Função que realiza o algoritmo de ordenação QuickSort.  
    Ordena o vetor de produtos entre os índices 'inicio' e 'final' usando recursão. */ 
void QuickSort(int inicio, int final, Produtos *produtos);  

/* Função que cria um arquivo com as informações dos produtos cadastrados.  
   Recebe um vetor de produtos e o número total de produtos. */ 
void cria_arquivo(Produtos *produtos, int numProdutos);

#endif /* PRODUTOS */