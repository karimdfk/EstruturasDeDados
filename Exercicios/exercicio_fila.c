#include<stdlib.h>
#include<stdio.h>

#define  MAX  5

// fila estatica e sequencial
struct fila {
    int primeiro;   // primeiro elemento da fila
    int final;      // posicao livre para inserir
    int n_elem;     // numero de elementos
    int elementos[MAX];    // vetor com elementos
};

// definicao do TAD fila
typedef struct fila Fila;

// Prototipos (ou Assinaturas) das funcoes
Fila *criar(int *DeuCerto);
void destruir(Fila *F);
int cheia(Fila *F);
int vazia(Fila *F);
void inserir(Fila *F, int X, int *DeuCerto);
void remover(Fila *F, int *X, int *DeuCerto);

int main()
{
    Fila *F1, *F2, *F;
    int DeuCerto;
    int valor;
    int i, x, c;

    F1 = criar(&DeuCerto);
    if (DeuCerto == 0) {// nao deu certo
        printf("Erro ao criar a fila\n");
        exit(-1);
    }

    F2 = criar(&DeuCerto);
    if (DeuCerto == 0) {// nao deu certo
        printf("Erro ao criar a fila\n");
        exit(-1);
    }

    F = criar(&DeuCerto);
    if (DeuCerto == 0) {// nao deu certo
        printf("Erro ao criar a fila\n");
        exit(-1);
    }

    inserir(F1, 10, &DeuCerto);
    inserir(F1, 20, &DeuCerto);
    inserir(F2, 30, &DeuCerto);
    inserir(F2, 45, &DeuCerto);
    inserir(F2, 21, &DeuCerto);

    x = F1->n_elem + F2->n_elem;
    c = 0;

    for(i=0; i<x; i++){
        if(c%2 == 0 || F2->n_elem == 0){
            remover(F1, &valor, &DeuCerto);
            if(DeuCerto==1) inserir(F, valor, &DeuCerto);
            c++;
        }
        if(c%2 != 0 || DeuCerto == 0){
            remover(F2, &valor, &DeuCerto);
            inserir(F, valor, &DeuCerto);
            c++;
        }
    }


    // imprime os elemento de F
    remover(F, &valor, &DeuCerto);
    while (DeuCerto == 1) {
        printf(" %d ", valor);
        remover(F, &valor, &DeuCerto);
    }
    printf("\n");

    destruir(F1);
    destruir(F2);
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
        F->final    = 0;
        F->n_elem   = 0;
        *DeuCerto = 1;
    }

    return F;
}

void destruir(Fila *F)
{
    if (F != NULL) free(F);
}

void inserir(Fila *F, int X, int *DeuCerto)
{
    if (cheia(F) == 1) // esta cheia
        *DeuCerto = 0;  // NAO DEU CERTO
    else {
        *DeuCerto = 1;
        F->n_elem = F->n_elem + 1;
        F->elementos[ F->final ] = X;
        /* OU
           int pos = F->final;
           F->elementos[ pos ] = X; */

        if (F->final == (MAX - 1))
            F->final = 0;
        else F->final = F->final + 1;
    }
}

void remover(Fila *F, int *X, int *DeuCerto)
{
    if (vazia(F) == 1) // esta vazia
        *DeuCerto = 0;  // NAO DEU CERTO
    else {
        *DeuCerto = 1;
        F->n_elem = F->n_elem - 1;
        *X = F->elementos[ F->primeiro ];
        /* OU
           int pos = F->final;
           F->elementos[ pos ] = X; */

        if (F->primeiro == (MAX - 1))
            F->primeiro = 0;
        else F->primeiro = F->primeiro + 1;
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
