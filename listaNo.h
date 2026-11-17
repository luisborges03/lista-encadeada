#ifndef LISTANO_H
#define LISTANO_H

/*============================================================
Função constante para inicializar a lista 
1 - Funçao typedef para struct do no
============================================================*/
typedef struct no {
    int dado;
    struct no *proximo;
} TNO;
/*============================================================
Função constante para inicializar a lista 
1 - Funçao typedef para struct da lista
============================================================*/
typedef struct llse {
    int tamanho;
    TNO *inicio;
    TNO *fim;
} Tllse;
/*============================================================
Função constante para inicializar a lista 
1 - lista: define o tamanho da lista como 0 e zera os ponteiros
============================================================*/
void inicializarLista(Tllse * const lista);
/*============================================================
Função para inserir um novo elemento no início da lista
Retorna 1 se a inserção correu bem ou 0 se falhar (falta de memória)
============================================================*/
int inserirInicio(Tllse * const lista, int elemento);
/*============================================================
Função para aceder ao valor do primeiro elemento da lista
Retorna o valor do dado (deve ser usada após verificar se não está vazia)
============================================================*/
int acessar(Tllse const * const lista);
/*============================================================
Função para retirar o elemento que está no início da lista
Retorna 1 se removeu com sucesso ou 0 se a lista já estava vazia
============================================================*/
int retirarinicio(Tllse * const lista);
/*============================================================
Função para verificar se a lista está vazia
Retorna 1 (verdadeiro) se estiver vazia ou 0 (falso) caso contrário
============================================================*/
int estavazia(Tllse const * const lista);
/*============================================================
Função para inserir um novo elemento no fim da lista
Retorna 1 se a inserção correu bem ou 0 se falhar (falta de memória)
============================================================*/
void inserirfim(Tllse * const lista, int elemento);
/*============================================================
Função para acessar ao valor dos ultimos elemento da lista
Retorna o valor do dado (deve ser usada após verificar se não está vazia)
============================================================*/
int acessarfim(Tllse * const lista);
/*============================================================
Função para retirar o elemento que está no fim da lista
Retorna 1 se removeu com sucesso ou 0 se a lista já estava vazia
============================================================*/
void retirarFim(Tllse * const lista);
/*============================================================
Função para imprimir os elementos da lista
Retorna 1 se removeu com sucesso ou 0 se a lista já estava vazia
============================================================*/
void imprimirLista(Tllse const * const lista);
/*============================================================
Função para inserir um novo elemento em uma posição específica
da lista (índice 0-based).
Retorna void (aloca internamente; imprime erro se sem memória)
============================================================*/
void inserirPosicao(Tllse * const lista, int pos, int elm);
/*============================================================
Função para acessar o valor do elemento em uma posição
específica da lista. Retorna o valor do dado, ou 0 se a lista estiver vazia
ou a posição for inválida.
============================================================*/
int acessarPosicao(Tllse const * const lista, int tamanho, int pos, int *ok);
/*============================================================
Função para retirar o elemento em uma posição específica
da lista (índice 0-based).
Não faz nada se a lista estiver vazia ou a posição for inválida.
============================================================*/
void retirarPosicao(Tllse * const lista, int tamanho, int pos);

#endif