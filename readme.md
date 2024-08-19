# Quicksort 

Olá!
Somos discentes da disciplina Algoritmos e Estrutura de Dados I ministrada pela docente Dra. Rosana Cibely, nesse projeto da segunda unidade da disciplina o objetivo é utilizar o algoritmo de ordenação QuickSort para realizar uma ordenação de produtos.

## Índice
- O que é Quicksort?

- Finalidade de criação

- Estudos e Conhecimentos

- Como executar

- Explicação do Código

- Análise de Complexidade de Tempo

- Resultado do Código

- Exemplificação do QuickSort

## O que é Quicksort?

O Quicksort é um algoritmo de ordenação baseado em comparação que aplica a técnica "Dividir para Conquistar" para ordenar os elementos de um conjunto. Essa técnica consiste em dividir o problema original em subproblemas menores, que são resolvidos recursivamente. A chave para a eficiência do Quicksort é a escolha de um elemento chamado de "pivô", que serve para dividir os dados em subconjuntos menores. Após essa divisão, os resultados são combinados para produzir a solução final.

## Finalidade de criação

O sistema foi desenvolvido para armazenar produtos ordenados em um arquivo .txt, garantindo que os dados sejam salvos de acordo com os nomes fornecidos pelo usuário. Para isso, foi utilizado o algoritmo de ordenação QuickSort, implementado na linguagem C.

## Estudos e Conhecimentos

Há alguns estudos e conhecimentos que se torna necessário ter uma base antes de se estudar o código do QuickSort em C, algumas delas são:
- O conhecimento da Programação em C;
- Manipulação de Vetores e Ponteiros;
- Compreensão de Algoritmos de Ordenação;
- Análise de Complexidade de Algoritmos;
- Pivôs e Partições.

## Como executar

Para executar o programa, deve ser feito os seguintes passos:
- Abra o terminal na pasta do projeto.
- Compile os arquivos main.c e Quicksort.c com o comando:

``` bash
gcc -c main.c
gcc -c Quicksort.c
gcc -o main.exe Quicksort.c main.c
```  

- Execute o programa com o comando `./main.`
- Siga as instruções exibidas no terminal para cadastrar os Produtos. Você será solicitado a inserir o nome, código e preço do produto.
- Após o cadastro, os dados dos Produtos serão ordenados e armazenados no arquivo "PRODUTOS.txt".

## Explicação do Código

### Bibliotecas

O projeto consiste na implementação do algoritmo Quicksort para ordenar produtos com base em seus nomes. Após a ordenação, os dados dos produtos são armazenados em um arquivo .txt para manter os registros constantemente atualizados. Cinco bibliotecas são essenciais para o funcionamento do código:

1. `stdlib.h`: Contém funções básicas para manipulação de memória dinâmica, como alocação e realocação de memória, além de outras funções utilitárias.

2. `stdio.h`: Oferece funções para entrada e saída de dados, permitindo a leitura e escrita em arquivos e no console.

3. `Quicksort.h`: Uma biblioteca criada especificamente para o projeto, que implementa o algoritmo QuickSort e gerencia dados em arquivos de texto.

4. `time.h`: Biblioteca padrão do C que inclui funções para manipulação de datas e horas.

5. `string.h`: Biblioteca que contém funções e macros para manipulação de strings e caracteres.

### Quicksort.c

`struct produtos`: Temos as variáveis que constituem os dados do produto, os quais são: nome, código e preço.

`alocaMemoria`: Esta função aloca memória para um vetor de produtos com a capacidade de 150 produtos.

`realocaMemoria`: Esta função realoca a memória do vetor de produtos para uma nova capacidade, quando o seu limite de produtos atingir a capacidade inicial.

`cadastro`: Função que cadastra os dados dos novos produtos, incluindo nome, código e preço.

`divisao`: Função principal do Quicksort. Ela divide o vetor em duas partes em torno de um pivô. Todos os elementos menores que o pivô são movidos para a esquerda e os maiores para a direita.

`imprime`: Essa função exibe na tela todos os dados dos produtos cadastrados.

`Quicksort`: A função implementa o algoritmo recursivo Quicksort. Ela divide o vetor em duas partes, utilizando a função divisao, e chama a si mesma recursivamente para ordenar ambas as partes.

`cria_arquivo`: Função que cria o arquivo "PRODUTOS.txt", e imprime os dados cadastrados em ordem alfabética.

### Quicksort.h

Esse é nosso arquivo cabeçalho, é uma forma de organizar e modularizar nosso código, separando as declarações e definições do restante da implementação. Isso torna o código mais legível e facilita a manutenção.

### main.c

O arquivo `main.c` é o arquivo principal do programa e contém a função `main()`. Ele é responsável por gerenciar o menu principal e as operações do programa.

## Análise de Complexidade de Tempo

### Quicksort.c

`alocaMemoria`:
```
T(n) = c1 + c2 + c3 + c4
T(n) = b
T(n) = O(n) 
```
`realocaMemoria`:
```
T(n) = c1 + c2 + c3 + c4
T(n) = b
T(n) = O(n)
```
`cadastro`:
```
T(n) = n * (c1 + c2 + c3 + c4)
T(n) = O(n)
```

`divisao`:
```
T(n) = c1 + c2 + n * (c3 + c4 + c5 + c6 + c7) + c8 + c9 + c10 + c11
T(n) = O(n)
```

`imprime`:
```
T(n) = n * (c1 + c2 + c3)
T(n) = O(n)
```
`QuickSort`:
```
T(n) = n * log(n) 
T(n) = O(n log n) 
```
`cria_arquivo`:
```
T(n) = c1 + c2 + n * (c3 + c4 + c5) + c6
T(n) = O(n) 
```
`Análise Total`:
```
T(n) = O(n) + O(n) + O(n) + O(n) + O(n) + O(n log n) + O(n)
T(n) = O(n log n)
```
### main.c

```
int capacidade = 150; // c1
int numProdutos = 0; // c2
Produtos *produtos = alocaMemoria(capacidade); // c3
cadastro(produtos, &numProdutos); // c4

T(n) =  n * (c1 + c2 + c3 + c4) 
T(n) = O(n)
```

```
capacidade = numProdutos; // c5
produtos = realocaMemoria(produtos, capacidade); // c6

T(n) = O(n)
```
```
clock_t inicio = clock(); // c7
QuickSort(0, numProdutos - 1, produtos); // c8
clock_t fim = clock(); // c9
double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC; // c10

T(n) = T(k) + T(n-k-1) + O(n)
T(n) = 2T(n/2) + O(n)
T(n) = O(n log n)

```
```
imprime(produtos, numProdutos);  // c11

T(n) = O(n)
```
```
cria_arquivo(produtos, numProdutos); // c12

T(n) = O(n)
```
```
Analise Total:

T(n) = c1 + c2 + c3 + n(c4 + c11 + c12) + O(n log n)
T(n) = O(n log n)
A complexidade dominante é O(n log n) devido ao QuickSort.
```

## Resultado do código

 Teremos como resultado do código a ordenação dos produtos pelos nomes fornecidos.

## Exemplificação do QuickSort

[![Quicksoart](https://miro.medium.com/v2/resize:fit:828/format:webp/1*5ipNWgngvSU9jnUf_SsRag.png)](https://miro.medium.com/v2/resize:fit:828/format:webp/1*5ipNWgngvSU9jnUf_SsRag.png)


1. Temos uma lista completamente desordenada;

2. Nesse segundo passo foi selecionado o número 13 como pivô e foi separado em duas sublistas os números menores ou iguais ao pivô à esquerda e os maiores à direita;

3. Logo após é dividido em mais sublistas e pivôs foram selecionados até que só reste um elemento por sublista e assim forme uma lista ordenada.
