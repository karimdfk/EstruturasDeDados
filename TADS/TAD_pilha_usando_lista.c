#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

// declaracao do no da *lista*
typedef struct node Node;
struct node {
    char info;
    Node *next;
};

// declaracao da pilha em si
typedef struct pilha Pilha;
struct pilha {
    Node *topo;
};

/*
- newNode: criava um NODE da pilha
- deleteNode: libera memoria de um NODE

- criar: cria uma pilha vazia
- empilhar: insere elemento na pilha
- desempilha: remove e retorna elemento da pilha
- vazia: verifica se pilha eh vazia
- cheia: verifica se pilha eh cheia
- destruir: libera todas as posicoes da pilha
*/

Node *newNode(bool *deuCerto)
{
    Node *n;

    n = malloc(sizeof(Node));
    if (n == NULL) *deuCerto = false;
    else *deuCerto = true;

    return n;
}

void deleteNode(Node *n)
{
    if (n != NULL) free(n);
}

Pilha *criar(bool *deuCerto)
{
    Pilha *p;

    p = malloc(sizeof(Pilha));
    if (p == NULL) *deuCerto = false;
    else {
        *deuCerto = true;
        p->topo = NULL; // pilha vazia
    }

    return p;
}

bool cheia(Pilha *p)
{
    return false;
}

void empilhar(Pilha *p, char X, bool *deuCerto)
{
    Node *paux;
    bool ok;

    if (cheia(p) == true) *deuCerto = false;
    else {
        paux = newNode(&ok);
        // poderia tratar o caso de ok == false
        paux->info = X;
        paux->next = p->topo;
        p->topo = paux;
        *deuCerto = true;
    }
}

bool vazia(Pilha *p)
{
    if (p->topo == NULL) return true;
    else return false;
}

void desempilhar(Pilha *p, char *X, bool *deuCerto)
{
    Node *paux;

    if (vazia(p) == true) *deuCerto = false;
    else {
        paux = p->topo;
        *X = paux->info;
        p->topo = paux->next;
        deleteNode(paux);
        *deuCerto = true;
    }
}

void destruir(Pilha *p)
{
    bool deuCerto;
    char c;

    while (!vazia(p)) {
        desempilhar(p, &c, &deuCerto);
    }

    free(p);
}

int main()
{
    Pilha *p;
    bool deuCerto;
    char c;

    p = criar(&deuCerto);
    if (deuCerto == false) {
        printf("Erro ao criar a pilha\n");
        exit(1);
    }

    empilhar(p, 'A', &deuCerto);
    empilhar(p, 'B', &deuCerto);
    empilhar(p, 'C', &deuCerto);
    empilhar(p, 'D', &deuCerto);
    empilhar(p, 'E', &deuCerto);

    while (!vazia(p)) {
        desempilhar(p, &c, &deuCerto);
        printf("%c\n", c);
    }

    destruir(p);

    return 0;
}
