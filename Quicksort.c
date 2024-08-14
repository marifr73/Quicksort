#include <stdio.h>
#include <stdlib.h>

typedef struct produtos{
    char nome[20];
    int codigo;
    float preco;
}Produtos;

void cadastro (Produtos * produto){
    int opcao;
    do{
    printf("1 - Nome\n2 - Código\n3 - Preço\n4 - Sair\n");
    scanf("%d", &opcao);
        switch (opcao){
        case 1:
            printf("Informe o nome do produto: ");
            scanf(" %[^\n]", produto->nome);
            getchar();
            break;
        case 2:
            printf("Informe o código do produto: ");
            scanf("%d", &produto->codigo);
            break;
        case 3:
            printf("Informe o preço do produto: ");
            scanf("%f", &produto->preco);
            break;;
        default:
            printf("Código não encontrado, informe outro!\n");
            break;
        }
    }while(opcao != 4); 
}

int main(void){
    Produtos produtos;
    cadastro(&produtos);
    return 0;
}
