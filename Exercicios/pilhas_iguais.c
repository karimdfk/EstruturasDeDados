#include<stdlib.h> // malloc, free, exit
#include<stdio.h>  // printf, scanf

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

int iguais(Pilha *p1, Pilha *p2){
    int DeuCerto, i, x;
    char c1, c2;

    for(i=0; i<MAX; i++){

        if(vazia(p1) == 1 || vazia(p2) == 1){
            if(vazia(p1) == 1 && vazia(p2) == 1){
                x = 1;
            }
            else{
                x = 0;
            }

            break;
        }

        desempilhar(p1, &c1, &DeuCerto);
        desempilhar(p2, &c2, &DeuCerto);

        if(c1 != c2){
            x = 0;
            break;
        }

    }

    return x;
}


int main()
{
    Pilha *p1, *p2;
    int DeuCerto, x, y, i, res;
    char c1, c2;

    p1 = criar(&DeuCerto);
    if (DeuCerto == 0) { // tratar o erro aqui...
        printf("Nao foi possivel criar a pilha");
        exit(1);
    }

    p2 = criar(&DeuCerto);
    if(DeuCerto == 0){
        printf("Nao foi possivel criar a pilha");
        exit(1);
    }

    for(i=0; i<MAX; i++){
        printf("Deseja adicionar um elemento na p1?\n");
        printf("1 - sim\n");
        printf("2 - nao\n");
        scanf("%d", &x);

        if(x == 2){
           break;
        }

        printf("Digite o elemento que deseja adicionar\n");
        scanf(" %c", &c1);
        empilhar(p1, c1, &DeuCerto);
    }

    for(i=0; i<MAX; i++){
        printf("Deseja adicionar um elemento na p2?\n");
        printf("1 - sim\n");
        printf("2 - nao\n");
        scanf("%d", &y);

        if(y == 2){
           break;
        }

        printf("Digite o elemento que deseja adicionar\n");
        scanf(" %c", &c2);
        empilhar(p2, c2, &DeuCerto);
    }

    res = iguais(p1, p2);

    if(res == 1){
        printf("Sao iguais\n");
    }
    else{
        printf("nao\n");
    }

    destruir(p1);
    destruir(p2);

    return 0;
}
