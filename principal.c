#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "listasDuplamenteEncadeadas.h"
#include "arvoresBinariasDeBusca.h"

void limparBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void inserirCarro(ListaDuplamenteEncadeada* lista, ArvoreBinariaCarro* arvorePlaca, ArvoreBinariaCarro* arvoreMarca, ArvoreBinariaCarro* arvoreAno) {
    Carro carro;
    printf("INSERIR CARRO:\n");
    printf("--------------------------------------\n");
    printf("Digite a placa do carro: ");
    limparBuffer();
    scanf("%s", carro.placa);
    printf("Digite a marca do carro: ");
    limparBuffer();
    scanf("%s", carro.marca);
    printf("Digite o ano do carro: ");
    limparBuffer();
    scanf("%d", &carro.ano);
    printf("--------------------------------------\n");
    if (buscarCarroArvore(arvorePlaca, carro.placa) != NULL) {
        printf("\n######################################\n");
        printf("ERRO: Ja existe um carro com essa placa!\n");
        printf("######################################\n\n");
    } else {
        inserirLista(lista, &carro, 1);
        inserirPorPlaca(arvorePlaca, carro);
        inserirPorMarca(arvoreMarca, carro);
        inserirPorAno(arvoreAno, carro);
        printf("\n######################################\n");
        printf("Carro inserido com sucesso!\n");
        printf("######################################\n\n");
    }
}

void removerCarro(ListaDuplamenteEncadeada* lista, ArvoreBinariaCarro* arvorePlaca, ArvoreBinariaCarro* arvoreMarca, ArvoreBinariaCarro* arvoreAno) {
    char placa[9];
    printf("REMOVER CARRO:\n");
    printf("--------------------------------------\n");
    printf("Digite a placa do carro: ");
    limparBuffer();
    scanf("%s", placa);
    printf("--------------------------------------\n");
    Carro carroBuscado = buscarCarroArvore(arvorePlaca, placa)->dados;
    if (buscarCarroArvore(arvorePlaca, placa) == NULL) {
        printf("\n######################################\n");
        printf("ERRO: Nao existe um carro com essa placa!\n");
        printf("######################################\n\n");
    } else {
        removerLista(lista, &carroBuscado);
        removerPorPlaca(arvorePlaca, placa);
        removerPorPlaca(arvoreMarca, placa);
        removerPorPlaca(arvoreAno, placa);
        printf("\n######################################\n");
        printf("Carro removido com sucesso!\n");
        printf("######################################\n\n");
    }
}

void buscarCarro(ListaDuplamenteEncadeada* lista, ArvoreBinariaCarro* arvorePlaca) {
    char placa[9];
    printf("BUSCAR CARRO:\n");
    printf("--------------------------------------\n");
    printf("Digite a placa do carro: ");
    limparBuffer();
    scanf("%s", placa);
    printf("--------------------------------------\n");
    if (buscarCarroArvore(arvorePlaca, placa) == NULL) {
        printf("\n######################################\n");
        printf("ERRO: Nao existe um carro com essa placa!\n");
        printf("######################################\n\n");
    } else {
        Carro carro = buscarCarroArvore(arvorePlaca, placa)->dados;
        printf("\n######################################\n");
        printf("Placa: %s\n", carro.placa);
        printf("Marca: %s\n", carro.marca);
        printf("Ano: %d\n", carro.ano);
        printf("######################################\n\n");
    }
}

void imprimirCarro(void* dado, int i) {
    Carro* carro = (Carro*) dado;
    printf("%d  | Placa: %s | Marca: %s | Ano: %d\n", i, carro->placa, carro->marca, carro->ano);
}

void listarPorPlaca(ListaDuplamenteEncadeada* lista) {
    printf("LISTAR CARROS POR PLACA:\n");
    printf("--------------------------------------\n");
    imprimirLista(lista, imprimirCarro);
    printf("--------------------------------------\n\n");
}

void listarPorMarca(ArvoreBinariaCarro* arvoreMarca) {
    printf("LISTAR CARROS POR MARCA:\n");
    printf("--------------------------------------\n");
    imprimirArvoreCarro(arvoreMarca);
    printf("--------------------------------------\n\n");
}

void listarPorAno(ArvoreBinariaCarro* arvoreAno) {
    printf("LISTAR CARROS POR ANO:\n");
    printf("--------------------------------------\n");
    imprimirArvoreCarro(arvoreAno);
    printf("--------------------------------------\n\n");
}

int main() {
    ListaDuplamenteEncadeada listaDeCarros = criarLista(sizeof(Carro));
    ArvoreBinariaCarro* arvorePlaca = criarArvoreCarro();
    ArvoreBinariaCarro* arvoreMarca = criarArvoreCarro();
    ArvoreBinariaCarro* arvoreAno = criarArvoreCarro();
    int opcao = 0;
    while (opcao != 7) {
        printf("\n\n----- MENU -----\n");
        printf("1 - Inserir um carro na lista\n");
        printf("2 - Remover um carro da lista\n");
        printf("3 - Buscar um carro na arvore binaria auxiliar\n");
        printf("4 - Listar os carros ordenados pela placa, atraves da lista\n");
        printf("5 - Listar os carros ordenados pela marca, atraves da arvore auxiliar\n");
        printf("6 - Listar os carros ordenados pelo ano, atraves da arvore auxiliar\n");
        printf("7 - Sair do programa\n");
        printf("\n-----> Digite a opcao desejada: ");
        scanf("%d", &opcao);
        printf("\n\n");
        switch (opcao) {
            case 1:
                inserirCarro(&listaDeCarros, arvorePlaca, arvoreMarca, arvoreAno);
                break;
            case 2:
                removerCarro(&listaDeCarros, arvorePlaca, arvoreMarca, arvoreAno);
                break;
            case 3:
                buscarCarro(&listaDeCarros, arvorePlaca);
                break;
            case 4:
                listarPorPlaca(&listaDeCarros);
                break;
            case 5:
                listarPorMarca(arvoreMarca);
                break;
            case 6:
                listarPorAno(arvoreAno);
                break;
            case 7:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("\n\nOpcao invalida!\n");
                break;
        }
    }
    liberarLista(&listaDeCarros);
    destruirArvoreCarro(arvorePlaca);
    destruirArvoreCarro(arvoreMarca);
    destruirArvoreCarro(arvoreAno);
    return 0;
}