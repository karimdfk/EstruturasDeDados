#include<stdlib.h> // malloc, free, exit
#include<stdio.h>  // printf, scanf
#include<string.h>

#define  MAX  10

// pilha estatica e sequencial
struct pilha {
    int topo;
    char elementos[MAX];
};

typedef struct pilha Pilha; // tipo Pilha

Pilha* criar(int *DeuCerto)
{
    Pilha* p;

    p = (Pilha*) malloc(sizeof(Pilha));
    if (p == NULL) *DeuCerto = 0; // 0 == false
    else {
        p->topo = -1;
        *DeuCerto = 1;
    }

    return p;
}

void destruir(Pilha *p)
{
    /*if (p == NULL) // pilha nao existe
        *DeuCerto = 0;
    else {
        *DeuCerto = 1;
        free(p);
    }
    */
    //OU

    if (p != NULL) free(p);

}

int vazia(Pilha *p)
{
    if (p->topo == -1) // a pilha esta vazia
        return 1;   // 1 == true
    else return 0;  // 0 == false
}

int cheia(Pilha *p)
{
    if (p->topo == MAX-1) // a pilha esta cheia
        return 1;   // 1 == true
    else return 0;  // 0 == false
}

void empilhar(Pilha *p, char x, int *DeuCerto)
{
    if (cheia(p) == 1) // pilha cheia
        *DeuCerto = 0;
    else {  // pilha nao tah cheia
        p->topo = p->topo + 1;
        // int t = p->topo;
        // p->elementos[t] = x;
        p->elementos[p->topo] = x;
        *DeuCerto = 1;
    }
}

void desempilhar(Pilha *p, char *x, int *DeuCerto)
{
    if (vazia(p) == 1) // pilha vazia
        *DeuCerto = 0;
    else {  // pilha nao tah cheia
        *x = p->elementos[p->topo];
        p->topo = p->topo - 1;
        *DeuCerto = 1;
    }
}

int verifica(char s1[MAX], char s2[MAX]){
    Pilha *p1;
    char c1, str[MAX];
    int DeuCerto, i, x, y;

    x = strlen(s1);

    p1 = criar(&DeuCerto);
    if (DeuCerto == 0) { // tratar o erro aqui...
        printf("Erro na criacao da pilha");
        exit(1);
    }


    for(i=0; i<x; i++){
        empilhar(p1, s1[i], &DeuCerto);
    }

    for(i=0; i<x; i++){
        desempilhar(p1, &c1, &DeuCerto);
        str[i] = c1;
    }

    if(strcmp(str, s2) == 0){
        y = 1;
    }

    destruir(p1);

    return y;
}


int main()
{
    Pilha *p;
    int DeuCerto;
    char c, str1[MAX], str2[MAX];

    p = criar(&DeuCerto);
    if (DeuCerto == 0) { // tratar o erro aqui...
        printf("Nao foi possivel criar a pilha");
        exit(1);
    }


    printf("Digite a 1a palavra:\n");
    scanf("%s", str1);

    printf("Digite a 2a palavra:\n");
    scanf("%s", str2);

    int v = verifica(str1,str2);
    if(v == 1){
        printf("A string eh da forma xy\n");
    }
    else{
        printf("Neh nao\n");
    }


    destruir(p);

    return 0;
}
