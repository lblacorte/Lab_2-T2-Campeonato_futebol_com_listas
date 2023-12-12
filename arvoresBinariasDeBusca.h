#ifndef ARVORESBINARIASDEBUSCA_H
#define ARVORESBINARIASDEBUSCA_H

//Estrutura para representar um carro
typedef struct {
    char placa[9];
    char marca[20];
    int ano;
} Carro;

//Estrutura para representar um nó da árvore binária
typedef struct NoArvore {
    Carro dados;
    struct NoArvore* esquerda;
    struct NoArvore* direita;
} NoArvore;

//Estrutura para representar uma árvore binária
typedef struct {
    NoArvore* raiz;
} ArvoreBinariaCarro;

//Função para criar uma nova árvore
ArvoreBinariaCarro* criarArvoreCarro();

//Função para inserir um novo nó na árvore, ordenado pela placa do carro
void inserirPorPlaca(ArvoreBinariaCarro* arvore, Carro dadosCarro);

//Função para inserir um novo nó na árvore, ordenado pela marca do carro
void inserirPorMarca(ArvoreBinariaCarro* arvore, Carro dadosCarro);

//Função para inserir um novo nó na árvore, ordenado pelo ano do carro
void inserirPorAno(ArvoreBinariaCarro* arvore, Carro dadosCarro);

//Função para buscar um carro na árvore, buscando pela placa 
NoArvore* buscarCarroArvore(ArvoreBinariaCarro* arvore, char placa[]);

//Função para imprimir os dados armazenados na árvore
void imprimirArvoreCarro(ArvoreBinariaCarro* arvore);

//Função para liberar a memória alocada para a árvore
void destruirArvoreCarro(ArvoreBinariaCarro* arvore);

//Função para remover um nó da árvore, buscando pela placa
void removerPorPlaca(ArvoreBinariaCarro* arvore, char placa[]);

#endif /* ARVORESBINARIASDEBUSCA_H */