/*
 * Essa versao inclui uma maneira diferente de incrementar
 * as posicoes de inicio e fim de final.
 * Note que nao temos mais a posicao de final de fila, ou seja,
 * a posicao disponivel para insercao; em vez disso, temos 
 * um indice que aponta para o ultimo elemento da fila.
 */

#include<stdlib.h>
#include<stdio.h>

#define  MAX  5

// fila estatica e sequencial
struct fila {
    int primeiro;    // posicao do primeiro elemento da fila
    int ultimo;      // posicao DO ULTIMO elemento
    int n_elem;      // total de elementos na fila
    char elementos[MAX];    // vetor com elementos
};

// definicao do TAD fila
typedef struct fila Fila;

// Prototipos (ou Assinaturas) das funcoes
Fila *criar(int *DeuCerto);
void destruir(Fila *F);
int cheia(Fila *F);
int vazia(Fila *F);
void inserir(Fila *F, char X, int *DeuCerto);
void remover(Fila *F, char *X, int *DeuCerto);

int main()
{
    Fila *F;
    int DeuCerto;
    char valor;

    F = criar(&DeuCerto);
    if (DeuCerto == 0) {// nao deu certo
        printf("Erro ao criar a fila\n");
        exit(-1);
    }

    inserir(F, 'a', &DeuCerto);
    printf(" DeuCerto = %d\n", DeuCerto);
    inserir(F, 'b', &DeuCerto);
    printf(" DeuCerto = %d\n", DeuCerto);
    inserir(F, 'c', &DeuCerto);
    printf(" DeuCerto = %d\n", DeuCerto);
    inserir(F, 'd', &DeuCerto);
    printf(" DeuCerto = %d\n", DeuCerto);
    inserir(F, 'e', &DeuCerto);
    printf(" DeuCerto = %d\n", DeuCerto);
    inserir(F, 'f', &DeuCerto);
    printf(" DeuCerto = %d\n", DeuCerto);

    // imprime os elemento de F
    remover(F, &valor, &DeuCerto);
    while (DeuCerto == 1) {
        printf(" %c ", valor);
        remover(F, &valor, &DeuCerto);
    }
    printf("\n");

    destruir(F);

    return 0;
}

Fila *criar(int *DeuCerto)
{
    Fila *F;
    // aloca memoria para a fila
    F = malloc(sizeof(Fila));

    if (F == NULL) *DeuCerto = 0;   // nao deu certo
    else {
        F->primeiro = 0;
        F->ultimo    = 0;
        F->n_elem   = 0;
        *DeuCerto = 1;
    }

    return F;
}

void destruir(Fila *F)
{
    if (F != NULL) free(F);
}

void inserir(Fila *F, char X, int *DeuCerto)
{
    if (cheia(F) == 1) // esta cheia
        *DeuCerto = 0;  // NAO DEU CERTO
    else {
        *DeuCerto = 1;
	F->n_elem = F->n_elem + 1;
        F->elementos[ F->ultimo ] = X;

	// Nova maneira de incrementar o indice de final de fila
	F->ultimo = (F->ultimo + 1) % MAX;

    }
}

void remover(Fila *F, char *X, int *DeuCerto)
{
    if (vazia(F) == 1) // esta vazia
        *DeuCerto = 0;  // NAO DEU CERTO
    else {
        *DeuCerto = 1;
        F->n_elem = F->n_elem - 1;
        *X = F->elementos[ F->primeiro ];

	// Nova maneira de incrementar o indice de inicio de fila
	F->primeiro = (F->primeiro + 1) % MAX;
    }
}

int cheia(Fila *F)
{
    if (F->n_elem == MAX) return 1; // true
    else return 0;  // false

    // OU
    //return (F->n_elem == MAX);
}

int vazia(Fila *F)
{
    if (F->n_elem == 0) return 1;   // true
    else return 0;  // false
}
