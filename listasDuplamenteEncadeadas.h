#ifndef LISTAS_DUPLAMENTE_ENCADEADAS_H
#define LISTAS_DUPLAMENTE_ENCADEADAS_H

#include <stddef.h>

// Estrutura para representar um nó da lista duplamente encadeada
struct No {
    void* dado;              // Ponteiro para os dados armazenados no nó
    struct No* proximo;      // Ponteiro para o próximo nó na lista
    struct No* anterior;     // Ponteiro para o nó anterior na lista
}; typedef struct No No;

// Estrutura para representar uma lista duplamente encadeada
struct ListaDuplamenteEncadeada {
    struct No* inicio;        // Ponteiro para o início da lista
    size_t tamanhoDado;       // Tamanho do tipo de dado armazenado na lista
}; typedef struct ListaDuplamenteEncadeada ListaDuplamenteEncadeada;

//Função para criar uma nova lista
struct ListaDuplamenteEncadeada criarLista(size_t tamanhoDado);

// Função para criar um novo nó
struct No* criarNo(void* dado, size_t tamanhoDado);

// Função para adicionar um novo nó no final da lista
void adicionarFinal(struct ListaDuplamenteEncadeada* lista, void* dado);

// Função para adicionar um novo nó no início da lista
void adicionarInicio(struct ListaDuplamenteEncadeada* lista, void* dado);

// Função para remover um nó da lista com base na chave fornecida
int removerLista(struct ListaDuplamenteEncadeada* lista, void* chave);

// Função para imprimir os dados armazenados na lista
void imprimirLista(ListaDuplamenteEncadeada* lista, void (*imprimirDado)(void*, int i));

//Função para liberar a memória alocada para a lista
void liberarLista(struct ListaDuplamenteEncadeada* lista);

//Função para inserir na lista, de acordo com o parâmetro tipoDeOrdenacao, que será 1, 2 ou 3, para placa, marca ou ano, respectivamente.
void inserirLista(struct ListaDuplamenteEncadeada* lista, void* dado, int tipoDeOrdenacao);

//Função para buscar um elemento na lista, de acordo com o parâmetro tipoDeChave que será 1, 2 ou 3, para placa, marca ou ano, respectivamente.
No* buscarLista(ListaDuplamenteEncadeada* lista, void* chave, int tipoDeChave);

#endif /* LISTAS_DUPLAMENTE_ENCADEADAS_H */