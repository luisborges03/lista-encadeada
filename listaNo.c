#include <stdio.h>
#include <stdlib.h>
#include "listaNo.h"

/*============================================================
Função constante para inicializar a lista 
1 - lista: define o tamanho da lista como 0 e zera os ponteiros
============================================================*/
void inicializarLista(Tllse * const lista)
{
    lista->tamanho = 0;
    lista->inicio  = NULL;
    lista->fim = NULL;
}

/*============================================================
Função para verificar se a lista está vazia
Retorna 1 (verdadeiro) se estiver vazia ou 0 (falso) caso contrário
============================================================*/
int estavazia(Tllse const * const lista)
{
    return(lista->tamanho == 0);
}

/*============================================================
Função para inserir um novo elemento no início da lista
Retorna 1 se a inserção correu bem ou 0 se falhar (falta de memória)
============================================================*/
int inserirInicio(Tllse * const lista, int elemento)
{
    TNO *pAux = (TNO *) malloc(sizeof(TNO));
    if(pAux == NULL) 
    {
        printf("ERRO\n");
        return 0;
    }
    pAux->dado    = elemento;
    pAux->proximo = NULL;

    if(estavazia(lista)) 
    {
        lista->inicio = pAux;
        lista->fim = pAux;
    } 
    else 
    {
        pAux->proximo = lista->inicio;
        lista->inicio = pAux;
    }
    lista->tamanho++;
    return 1;
}

/*============================================================
Função para aceder ao valor do primeiro elemento da lista
Retorna o valor do dado (deve ser usada após verificar se não está vazia)
============================================================*/
int acessar(Tllse const * const lista)
{
    if(estavazia(lista)) 
    {
        printf("Lista vazia\n");
        return 0;
    }
    return lista->inicio->dado;
}

/*============================================================
Função para retirar o elemento que está no início da lista
Retorna 1 se removeu com sucesso ou 0 se a lista já estava vazia
============================================================*/
int retirarinicio(Tllse * const lista)
{
    if(estavazia(lista)) 
    {
        printf("Lista vazia\n");
        return 0;
    }
    TNO *pAux = lista->inicio;
    lista->inicio = lista->inicio->proximo;
    free(pAux);
    lista->tamanho--;
    if(estavazia(lista))
        lista->fim = NULL;
    return 1;
}

/*============================================================
Função para inserir um novo elemento no fim da lista
Retorna 1 se a inserção correu bem ou 0 se falhar (falta de memória)
============================================================*/
void inserirfim(Tllse * const lista, int elemento)
{
    TNO *pAux = (TNO *) malloc(sizeof(TNO));
    if(pAux == NULL) 
    {
        printf("No nao criado\n");
        return;                        
    }
    pAux->dado    = elemento;
    pAux->proximo = NULL;
    if(estavazia(lista)) 
    {
        lista->inicio = pAux;
        lista->fim    = pAux;
    } 
    else 
    {
        lista->fim->proximo = pAux;
        lista->fim          = pAux;
    }
    lista->tamanho++;
}

/*============================================================
Função para acessar ao valor dos ultimos elemento da lista
Retorna o valor do dado (deve ser usada após verificar se não está vazia)
============================================================*/
int acessarfim(Tllse * const lista)
{
    if(estavazia(lista)) 
    {
        printf("Lista esta vazia\n");
        return 0;
    }
    return lista->fim->dado;
}

/*============================================================
Função para retirar o elemento que está no fim da lista
Retorna 1 se removeu com sucesso ou 0 se a lista já estava vazia
============================================================*/
void retirarFim(Tllse * const lista)
{
    if(estavazia(lista)) 
    {
        printf("Lista esta vazia\n");
        return;
    }
    if(lista->inicio == lista->fim) 
    {
        free(lista->inicio);           
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tamanho = 0;
        return;
    }
    TNO *pAux = lista->inicio;
    while(pAux->proximo != lista->fim)
        pAux = pAux->proximo;
    free(lista->fim);
    pAux->proximo = NULL;
    lista->fim    = pAux;
    lista->tamanho--;
}

/*============================================================
Função para inserir um novo elemento em uma posição específica
da lista (índice 0-based).
Retorna void (aloca internamente; imprime erro se sem memória)
============================================================*/
void inserirPosicao(Tllse * const lista, int pos, int elm)
{
    if(pos < 0 || pos > lista->tamanho) 
    {
        printf("Posicao invalida\n");
        return;
    }
    if(pos == 0) 
    {
        inserirInicio(lista, elm); 
        return;
    }
    if(pos == lista->tamanho) 
    {
        inserirfim(lista, elm);        
        return;
    }
    TNO *novo = (TNO *) malloc(sizeof(TNO));
    if(novo == NULL) 
    {
        printf("No nao criado\n");
        return;
    }
    novo->dado = elm;
    TNO *pAux = lista->inicio;
    for (int i = 0; i < pos - 1; i++)
        pAux = pAux->proximo;
    novo->proximo  = pAux->proximo;
    pAux->proximo  = novo;
    lista->tamanho++;
}

/*============================================================
Função para acessar o valor do elemento em uma posição
específica da lista. Retorna o valor do dado, ou 0 se a lista estiver vazia
ou a posição for inválida.
============================================================*/
int acessarPosicao(Tllse const * const lista, int tamanho, int pos, int *ok)
{
    if(estavazia(lista) || pos < 0 || pos >= lista->tamanho)
    {
        printf("Posicao invalida\n");
        *ok = 0;
        return 0;
    }
    *ok = 1;
    TNO *pAux = lista->inicio;
    for (int i = 0; i < pos; i++)
        pAux = pAux->proximo;
    return pAux->dado;
}

/*============================================================
Função para retirar o elemento em uma posição específica
da lista (índice 0-based).
Não faz nada se a lista estiver vazia ou a posição for inválida.
============================================================*/
void retirarPosicao(Tllse * const lista, int tamanho, int pos)
{
    if(estavazia(lista)) {
        printf("Lista esta vazia\n");
        return;
    }
    if(pos < 0 || pos >= lista->tamanho) {
        printf("Posicao invalida\n");
        return;
    }
    if(pos == 0) {
        retirarinicio(lista);
        return;
    }
    if(pos == lista->tamanho - 1) {
        retirarFim(lista);
        return;
    }
    TNO *pAux = lista->inicio;
    for (int i = 0; i < pos - 1; i++)
        pAux = pAux->proximo;
    TNO *alvo      = pAux->proximo;
    pAux->proximo  = alvo->proximo;
    free(alvo);
    lista->tamanho--;
}

/*============================================================
Função para imprimir os elementos da lista
Retorna 1 se removeu com sucesso ou 0 se a lista já estava vazia
============================================================*/
void imprimirLista(Tllse const * const lista)
{
    if(estavazia(lista)) 
    {
        printf("Lista: [ Vazia ]\n");
        return;
    }
    TNO *atual = lista->inicio;
    printf("Lista (%d elementos): ", lista->tamanho);
    while(atual != NULL) 
    {
        printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }
}