#include "arvoresBinariasDeBusca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

NoArvore* criarNoCarro(Carro dadosCarro) {
    NoArvore* novoNo = (NoArvore*)malloc(sizeof(NoArvore));
    if (novoNo == NULL) {
        fprintf(stderr, "Erro ao alocar memoria para o no\n");
        exit(EXIT_FAILURE);
    }
    novoNo->dados = dadosCarro;
    novoNo->esquerda = novoNo->direita = NULL;
    return novoNo;
}

ArvoreBinariaCarro* criarArvoreCarro() {
    ArvoreBinariaCarro* novaArvore = (ArvoreBinariaCarro*)malloc(sizeof(ArvoreBinariaCarro));
    if (novaArvore == NULL) {
        fprintf(stderr, "Erro ao alocar memoria para a arvore\n");
        exit(EXIT_FAILURE);
    }
    novaArvore->raiz = NULL;
    return novaArvore;
}

void inserirPorPlacaRecursivo(NoArvore** raiz, Carro dadosCarro) {
    if (*raiz == NULL) {
        *raiz = criarNoCarro(dadosCarro);
    } else {
        if (strcmp(dadosCarro.placa, (*raiz)->dados.placa) < 0) {
            inserirPorPlacaRecursivo(&(*raiz)->esquerda, dadosCarro);
        } else if (strcmp(dadosCarro.placa, (*raiz)->dados.placa) > 0) {
            inserirPorPlacaRecursivo(&(*raiz)->direita, dadosCarro);
        }
    }
}

void inserirPorPlaca(ArvoreBinariaCarro* arvore, Carro dadosCarro) {
    if (arvore == NULL) {
        fprintf(stderr, "Arvore invalida\n");
        exit(EXIT_FAILURE);
    }
    inserirPorPlacaRecursivo(&(arvore->raiz), dadosCarro);
}

void inserirPorMarcaRecursivo(NoArvore** raiz, Carro dadosCarro) {
    if (*raiz == NULL) {
        *raiz = criarNoCarro(dadosCarro);
    } else {
        int comparacaoMarcas = strcmp(dadosCarro.marca, (*raiz)->dados.marca);
        if (comparacaoMarcas < 0 || (comparacaoMarcas == 0 && strcmp(dadosCarro.placa, (*raiz)->dados.placa) < 0)) {
            inserirPorMarcaRecursivo(&(*raiz)->esquerda, dadosCarro);
        } else {
            inserirPorMarcaRecursivo(&(*raiz)->direita, dadosCarro);
        }
    }
}

void inserirPorMarca(ArvoreBinariaCarro* arvore, Carro dadosCarro) {
    if (arvore == NULL) {
        fprintf(stderr, "Arvore invalida\n");
        exit(EXIT_FAILURE);
    }
    inserirPorMarcaRecursivo(&(arvore->raiz), dadosCarro);
}

void inserirPorAnoRecursivo(NoArvore** raiz, Carro dadosCarro) {
    if (*raiz == NULL) {
        *raiz = criarNoCarro(dadosCarro);
    } else {
        if (dadosCarro.ano < (*raiz)->dados.ano || (dadosCarro.ano == (*raiz)->dados.ano && strcmp(dadosCarro.placa, (*raiz)->dados.placa) < 0)) {
            inserirPorAnoRecursivo(&(*raiz)->esquerda, dadosCarro);
        } else {
            inserirPorAnoRecursivo(&(*raiz)->direita, dadosCarro);
        }
    }
}

void inserirPorAno(ArvoreBinariaCarro* arvore, Carro dadosCarro) {
    if (arvore == NULL) {
        fprintf(stderr, "Arvore invalida\n");
        exit(EXIT_FAILURE);
    }
    inserirPorAnoRecursivo(&(arvore->raiz), dadosCarro);
}

NoArvore* encontrarMenorNo(NoArvore* raiz) {
    while (raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }
    return raiz;
}

NoArvore* removerPorPlacaRecursivo(NoArvore* raiz, char placa[]) {
    if (raiz == NULL) {
        return raiz;
    }

    if (strcmp(placa, raiz->dados.placa) < 0) {
        raiz->esquerda = removerPorPlacaRecursivo(raiz->esquerda, placa);
    } else if (strcmp(placa, raiz->dados.placa) > 0) {
        raiz->direita = removerPorPlacaRecursivo(raiz->direita, placa);
    } else {
        if (raiz->esquerda == NULL) {
            NoArvore* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            NoArvore* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        NoArvore* temp = encontrarMenorNo(raiz->direita);
        raiz->dados = temp->dados;
        raiz->direita = removerPorPlacaRecursivo(raiz->direita, temp->dados.placa);
    }
    return raiz;
}

void removerPorPlaca(ArvoreBinariaCarro* arvore, char placa[]) {
    if (arvore == NULL) {
        fprintf(stderr, "Arvore invalida\n");
        exit(EXIT_FAILURE);
    }
    arvore->raiz = removerPorPlacaRecursivo(arvore->raiz, placa);
}

NoArvore* buscarCarroRecursivo(NoArvore* raiz, char placa[]) {
    if (raiz == NULL || strcmp(placa, raiz->dados.placa) == 0) {
        return raiz;
    }
    if (strcmp(placa, raiz->dados.placa) < 0) {
        return buscarCarroRecursivo(raiz->esquerda, placa);
    }
    return buscarCarroRecursivo(raiz->direita, placa);
}

NoArvore* buscarCarroArvore(ArvoreBinariaCarro* arvore, char placa[]) {
    if (arvore == NULL) {
        fprintf(stderr, "Arvore invalida\n");
        exit(EXIT_FAILURE);
    }
    return buscarCarroRecursivo(arvore->raiz, placa);
}

void imprimirArvoreCarroRecursivo(NoArvore* raiz, int* id) {
    if (raiz != NULL) {
        imprimirArvoreCarroRecursivo(raiz->esquerda, id);
        printf("%d  | Placa: %s | Marca: %s | Ano: %d\n", (*id)++, raiz->dados.placa, raiz->dados.marca, raiz->dados.ano);
        imprimirArvoreCarroRecursivo(raiz->direita, id);
    }
}

void imprimirArvoreCarro(ArvoreBinariaCarro* arvore) {
    if (arvore == NULL) {
        fprintf(stderr, "Arvore invalida\n");
        exit(EXIT_FAILURE);
    }
    int id = 1;
    imprimirArvoreCarroRecursivo(arvore->raiz, &id);
}

void destruirArvoreCarroRecursivo(NoArvore* raiz) {
    if (raiz != NULL) {
        destruirArvoreCarroRecursivo(raiz->esquerda);
        destruirArvoreCarroRecursivo(raiz->direita);
        free(raiz);
    }
}

void destruirArvoreCarro(ArvoreBinariaCarro* arvore) {
    if (arvore != NULL) {
        destruirArvoreCarroRecursivo(arvore->raiz);
        free(arvore);
    }
}