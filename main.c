#include <stdlib.h>
#include <stdio.h>
#include "listaNo.h"

int main()
{
    Tllse minhaLista;
    inicializarLista(&minhaLista);
    int opcao   = 0;
    int elemento = 0;
    int posicao  = 0;
    do
    {
        printf("\nMENU\n");
        printf("1 - Inserir Posicao\n");
        printf("2 - Acessar Posicao\n");
        printf("3 - Retirar Posicao\n");
        printf("4 - Mostrar a lista encadeada\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1:
                printf("Elemento: ");
                scanf("%d", &elemento);
                printf("Posicao: ");
                scanf("%d", &posicao);
                inserirPosicao(&minhaLista, posicao, elemento);
                imprimirLista(&minhaLista);
                break;
            case 2:
                printf("Posicao: ");
                scanf("%d", &posicao);
                int sucesso = 0;
                int val = acessarPosicao(&minhaLista, minhaLista.tamanho, posicao, &sucesso);
                if (sucesso)
                printf("Elemento na posicao %d: %d\n", posicao, val);
                break;
            case 3:
                printf("Posicao: ");
                scanf("%d", &posicao);
                retirarPosicao(&minhaLista, minhaLista.tamanho, posicao);
                imprimirLista(&minhaLista);
                break;
            case 4:
                printf("Lista: \n");
                imprimirLista(&minhaLista);
            case 0:
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcao != 0);
    return 0;
}