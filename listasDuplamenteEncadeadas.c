#include "listasDuplamenteEncadeadas.h"
#include "arvoresBinariasDeBusca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ListaDuplamenteEncadeada criarLista(size_t tamanhoDado) {
    ListaDuplamenteEncadeada lista;
    lista.inicio = NULL;
    lista.tamanhoDado = tamanhoDado;
    return lista;
}

No* criarNo(void* dado, size_t tamanhoDado) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memoria para o novo no.\n");
        exit(1);
    }
    novoNo->dado = malloc(tamanhoDado);
    if (novoNo->dado == NULL) {
        printf("Erro ao alocar memoria para os dados do novo no.\n");
        exit(1);
    }
    memcpy(novoNo->dado, dado, tamanhoDado);
    novoNo->proximo = NULL;
    novoNo->anterior = NULL;
    return novoNo;
}

void adicionarFinal(ListaDuplamenteEncadeada* lista, void* dado) {
    No* novoNo = criarNo(dado, lista->tamanhoDado);
    if (lista->inicio == NULL) {
        lista->inicio = novoNo;
    } else {
        No* atual = lista->inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoNo;
        novoNo->anterior = atual;
    }
}

void adicionarInicio(ListaDuplamenteEncadeada* lista, void* dado) {
    No* novoNo = criarNo(dado, lista->tamanhoDado);
    novoNo->proximo = lista->inicio;
    if (lista->inicio != NULL) {
        lista->inicio->anterior = novoNo;
    }
    lista->inicio = novoNo;
}

//Função para inserir na lista, de acordo com o parâmetro tipoDeOrdenacao, que será 1, 2 ou 3, para placa, marca ou ano, respectivamente.
void inserirLista(ListaDuplamenteEncadeada* lista, void* dado, int tipoDeOrdenacao) {
    if (tipoDeOrdenacao == 1) { //Ordenação por placa
        if (lista->inicio == NULL) {
            adicionarInicio(lista, dado);
        } else {
            No* atual = lista->inicio;
            while (atual != NULL) {
                if (strcmp(((Carro*)dado)->placa, ((Carro*)atual->dado)->placa) < 0) {
                    if (atual->anterior != NULL) {
                        No* novoNo = criarNo(dado, lista->tamanhoDado);
                        novoNo->proximo = atual;
                        novoNo->anterior = atual->anterior;
                        atual->anterior->proximo = novoNo;
                        atual->anterior = novoNo;
                    } else {
                        adicionarInicio(lista, dado);
                    }
                    return;
                }
                atual = atual->proximo;
            }
            adicionarFinal(lista, dado);
        }
    } else if (tipoDeOrdenacao == 2) { //Ordenação por marca
        if (lista->inicio == NULL) {
            adicionarInicio(lista, dado);
        } else {
            No* atual = lista->inicio;
            while (atual != NULL) {
                if (strcmp(((Carro*)dado)->marca, ((Carro*)atual->dado)->marca) < 0) {
                    if (atual->anterior != NULL) {
                        No* novoNo = criarNo(dado, lista->tamanhoDado);
                        novoNo->proximo = atual;
                        novoNo->anterior = atual->anterior;
                        atual->anterior->proximo = novoNo;
                        atual->anterior = novoNo;
                    } else {
                        adicionarInicio(lista, dado);
                    }
                    return;
                }
                atual = atual->proximo;
            }
            adicionarFinal(lista, dado);
        }
    } else if (tipoDeOrdenacao == 3) { //Ordenação por ano
        if (lista->inicio == NULL) {
            adicionarInicio(lista, dado);
        } else {
            No* atual = lista->inicio;
            while (atual != NULL) {
                if (((Carro*)dado)->ano < ((Carro*)atual->dado)->ano) {
                    if (atual->anterior != NULL) {
                        No* novoNo = criarNo(dado, lista->tamanhoDado);
                        novoNo->proximo = atual;
                        novoNo->anterior = atual->anterior;
                        atual->anterior->proximo = novoNo;
                        atual->anterior = novoNo;
                    } else {
                        adicionarInicio(lista, dado);
                    }
                    return;
                }
                atual = atual->proximo;
            }
            adicionarFinal(lista, dado);
        }
    }
}

//Função para buscar um elemento na lista, de acordo com o parâmetro tipoDeChave que será 1, 2 ou 3, para placa, marca ou ano, respectivamente.
No* buscarLista(ListaDuplamenteEncadeada* lista, void* chave, int tipoDeChave) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        if (tipoDeChave == 1) { //Busca por placa
            if (strcmp(((Carro*)atual->dado)->placa, (char*)chave) == 0) {
                return atual;
            }
        } else if (tipoDeChave == 2) { //Busca por marca
            if (strcmp(((Carro*)atual->dado)->marca, (char*)chave) == 0) {
                return atual;
            }
        } else if (tipoDeChave == 3) { //Busca por ano
            if (((Carro*)atual->dado)->ano == *(int*)chave) {
                return atual;
            }
        }
        atual = atual->proximo;
    }
    return NULL;
}

int removerLista(ListaDuplamenteEncadeada* lista, void* chave) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        if (memcmp(atual->dado, chave, lista->tamanhoDado) == 0) {
            if (atual->anterior != NULL) {
                atual->anterior->proximo = atual->proximo;
            } else {
                lista->inicio = atual->proximo;
            }
            if (atual->proximo != NULL) {
                atual->proximo->anterior = atual->anterior;
            }
            free(atual->dado);
            free(atual);
            return 1; // Indica que o nó foi encontrado e removido.
        }
        atual = atual->proximo;
    }
    return 0; // Indica que o nó com a chave especificada não foi encontrado.
}

void imprimirLista(ListaDuplamenteEncadeada* lista, void (*imprimirDado)(void*, int i)) {
    No* atual = lista->inicio;
    int i = 1;
    while (atual != NULL) {
        imprimirDado(atual->dado, i);
        i++;
        atual = atual->proximo;
    }
}

void liberarLista(ListaDuplamenteEncadeada* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual->dado);
        free(atual);
        atual = proximo;
    }
    lista->inicio = NULL;
}