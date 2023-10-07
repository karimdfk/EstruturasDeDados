/*
Karim de Freitas Karam - 12111BSI226
Gustavo Achcar Filho - 12111BSI209
Wothon Mateus de Araujo - 12111BSI262
*/
#include<stdlib.h> // malloc, free, exit
#include<stdio.h>  // printf, scanf

#define  MAX  30

// pilha estatica e sequencial
struct pilha {
    int topo;
    int elementos[MAX];
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

void empilhar(Pilha *p, int x, int *DeuCerto)
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

void desempilhar(Pilha *p, int *x, int *DeuCerto)
{
    if (vazia(p) == 1) // pilha vazia
        *DeuCerto = 0;
    else {  // pilha nao tah cheia
        *x = p->elementos[p->topo];
        p->topo = p->topo - 1;
        *DeuCerto = 1;
    }
}


/* ....................................................fim do TAD pilha................................................ */

void organiza_entradas(int arestas, int pos1[arestas], int pos2[arestas], int valor[arestas]){
    int i, j, aux1, aux2, auxv;

    for(i=0; i<arestas; i++){//organiza baseado na primeira entrada 'pos1'
        for(j=i; j<arestas; j++){
            if(pos1[i] > pos1[j]){
                aux1 = pos1[i];
                pos1[i] = pos1[j];
                pos1[j] = aux1;

                aux2 = pos2[i];
                pos2[i] = pos2[j];
                pos2[j] = aux2;

                auxv = valor[i];
                valor[i] = valor[j];
                valor[j] = auxv;
            }
        }
    }

    for(i=0; i<arestas; i++){//organiza baseado na segunda entrada 'pos2'
        for(j=i; j<arestas; j++){
            if(pos1[i] == pos1[j] && pos2[i] > pos2[j]){
                aux1 = pos1[i];
                pos1[i] = pos1[j];
                pos1[j] = aux1;

                aux2 = pos2[i];
                pos2[i] = pos2[j];
                pos2[j] = aux2;

                auxv = valor[i];
                valor[i] = valor[j];
                valor[j] = auxv;
            }
        }
    }

}

void cria_matriz(int vertices, int arestas, int pos1[arestas], int pos2[arestas], int valor[arestas], int matriz[vertices][vertices])
{//Esta função preenche minha matriz
    int i, j, c1;
    c1=0;

    for(i=1; i<=vertices; i++){
        for(j=1; j<=vertices; j++){
            if(pos1[c1] == i && pos2[c1] == j){
                matriz [i][j] = valor[c1];
                c1++;
            }
            else{
                matriz[i][j] = 0;
            }

        }
    }

}

int confere(int inicio, int fim, int vertices, int arestas, int pos1[arestas], int pos2[arestas], int valor[arestas], int matriz[vertices][vertices], int *soma)
{
    int i, j, c1, x, DeuCerto, guardai[vertices], guardaj[vertices];
    Pilha *p;
    c1=0;

    p = criar(&DeuCerto);//Criando uma pilha
    if (DeuCerto == 0) {
        printf("Nao foi possivel criar a pilha");
        exit(1);
    }

    for(i=inicio; i<=vertices; i++){
        for(j=1; j<=vertices; j++){


            if(matriz[i][j] != 0){//Se a posição contém algum valor, quer dizer que existe um caminho
                empilhar(p, matriz[i][j], &DeuCerto);
                guardai[c1] = i;
                guardaj[c1] = j;
                c1++;

                if(j == fim){//Caso o cainho encontrado seja o final indicado pelo usuário...
                    while(vazia(p)== 0){
                        desempilhar(p, &x, &DeuCerto);//... desempilhar toda a pilha e somar os valores de 'x'
                        *soma = *soma + x;
                    }
                    destruir(p);
                    return 1;
                }

                if(j!=vertices){//Se eu percorri todos os valores de 'j', não existe caminho direto entre 'i' e 'fim', tratar abaixo
                    i = j-1;
                    break;
                }

            }

            if(i == inicio && j == fim && vazia(p)==1){
                *soma = 0;
                destruir(p);
                return 0;
            }


            if(j == vertices && matriz[i][vertices] == 0 && c1 == 0){//Se c1 == 0, todas as conferências possíveis na linha foram feitas
                i = inicio;
                j = guardaj[0];

                while(vazia(p)== 0){//Nesse caso, preciso voltar a conferir a linha inicial. Desempilho tudo
                    desempilhar(p, &x, &DeuCerto);
                }
            }

            if(j == vertices && matriz[i][vertices] == 0 && c1 != 0){//Este 'if' volta nos caminhos em que a linha inicial se liga
                desempilhar(p, &x, &DeuCerto);
                i = guardai[c1-1];
                j = guardaj[c1-1];
                c1 = c1-1;
            }

        }

    }
    return 0;
}


int main()
{
    int vertices, arestas, inicio, fim;

    scanf("%d", &vertices);
    scanf("%d", &arestas);

    int pos1[arestas], pos2[arestas], valor[arestas], i;

    for(i=0; i<arestas; i++){
        scanf("%d%d%d", &pos1[i], &pos2[i], &valor[i]);
    }

    scanf("%d%d", &inicio, &fim);

/* ....................Fim das entradas do programa.................... */

    organiza_entradas(arestas, pos1, pos2, valor);

    int matriz[vertices][vertices];

    cria_matriz(vertices, arestas, pos1, pos2, valor, matriz);//Cria a matriz que ajuda a resolver o problema

    int soma;
    soma = 0;

    confere(inicio, fim, vertices, arestas, pos1, pos2, valor, matriz, &soma);



    if(soma == 0){
        printf("%d", -1);
    }
    else{
        printf("%d", soma);
    }



    return 0;
}
