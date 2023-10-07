#include<stdlib.h> // malloc, free, exit
#include<stdio.h>  // printf, scanf

#define  MAX  20

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


int main()
{
    int DeuCerto, vertices, arestas, inicio, fim;

    scanf("%d", &vertices);
    scanf("%d", &arestas);

    int pos1[arestas], pos2[arestas], valor[arestas], i;

    for(i=0; i<arestas; i++){
        scanf("%d%d%d", &pos1[i], &pos2[i], &valor[i]);
    }

    for(i=0; i<arestas; i++){
        printf("%d%d%d", pos1[i], pos2[i], valor[i]);
    }

    scanf("%d%d", &inicio, &fim);

    //Entradas do programa acima deste comentario

    int cont_pilhas, ajuda;
    ajuda = pos1[0];
    cont_pilhas = 1;

    /*
    O 'for' abaixo determina a quantidade de pilhas que devem ser criadas
    Esse valor é armazenado no 'cont_pilhas'.
    */
    for(i=1; i<arestas; i++){
        if(ajuda != pos1[i]){
            cont_pilhas++;
        }
        ajuda = pos1[i];
    }



    int cont_caminhos[cont_pilhas], k;
    k = 0;

    for(i=0; i<cont_pilhas; i++){ //Todos os contadores do vetor com valor inicial = 1
        cont_caminhos[i] = 1;
    }

    /*
    O 'for' abaixo determina a quantidade de elementos em cada pilha
    cont_caminhos[n] armazena cada quantidade no contador n
    */


    for(i=0; i<arestas; i++){
        if(pos1[i] == pos1[i+1]){
            cont_caminhos[k] = cont_caminhos[k] + 1;
        }
        else{
            k++;
        }
    }

    int elem_pilha_inicio[cont_pilhas];
    int qual = 0;
    int g = 0;
    int h = 1;

    for(i=0; i<cont_pilhas; i++){
        elem_pilha_inicio[i] = 0;
    }

    for(i=0; i<arestas; i++){ //Determina a quantidade de elementos de cada pilha
        if((h) == pos1[i]){
            elem_pilha_inicio[g] = elem_pilha_inicio[g] + 1;
        }
        else{
            g++;
            h++;
            if((h) == pos1[i]){
                elem_pilha_inicio[g] = elem_pilha_inicio[g] + 1;
            }
        }
    }

    for(i=0; i<cont_pilhas; i++){
        printf("%d\n", elem_pilha_inicio[g]);
    }


    for(i=0; i<arestas; i++){ //Indica a posição na qual a pilha inicia começa
        if(inicio == pos1[i]){
            qual = i;
            break;
        }
    }


    Pilha *p[cont_pilhas];

    /*
    O 'for' abaixo cria as pilhas que serao usadas no programa
    */
    for(i=0; i<cont_pilhas; i++){
        p[i] = criar(&DeuCerto);
        if (DeuCerto == 0) {
            printf("Nao foi possivel criar a pilha");
            exit(1);
        }
    }

    /*
    O 'for' abaixo adiciona os elementos às pilhas
    */
    int j;
    k = 0;

    for(j=0; j<cont_pilhas; j++){
        for(i=0; i<cont_caminhos[j]; i++){
            empilhar(p[j], pos2[k], &DeuCerto);
            k++;
        }
    }

    /*
        Daqui pra baixo começa a ressolução do problema
    */


    int x, y, z, w, n1, soma, aoba;
    soma = 0;
    n1 = inicio;
    aoba=0;

    for(w=0; w<arestas; w++){ //'aoba' recebe a posição em que a pilha inicial começa
        if(inicio == pos1[w]){
            aoba = w;
            break;
        }
    }

    for(z=0; z<10; z++){//Percorre a quantidade de caminhos possíveis (falta arrumar)

        if(n1 == fim){
            break;
        }
        soma = 0;
        n1 = inicio;


        for(y=0; y<cont_pilhas; y++){//Percorre todas as pilhas

            if(n1 == fim){
                break;
            }

            for(x=0; x<arestas; x++){//Percorre todos os possíveis elementos das pilhas
                if(n1 == pos1[x]){
                    desempilhar(p[y], &n1, &DeuCerto);
                    if(DeuCerto == 1){
                        soma = soma + valor[x];
                        printf("%d\n", soma);//printf de teste
                    }
                    break;
                }
            }
        }
    }


    if(soma == 0){
        printf("%d\n", -1);
    }
    else{
        printf("%d\n", soma);
    }



     /*
    O 'for' abaixo destroi todas as pilhas criadas
    */
    for(i=0; i<cont_pilhas; i++){
        destruir(p[i]);
    }

    return 0;
}
