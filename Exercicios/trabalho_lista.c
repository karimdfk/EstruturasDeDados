#include<stdlib.h>
#include<stdio.h>


// declaracao do no da *lista*
typedef struct node Node;
struct node {
    int info;
    Node *next;
};

// declaracao da lista em si
typedef struct lista Lista;
struct lista {
    Node *head;
};


Node *newNode(int *deuCerto)
{
    Node *n;

    n = malloc(sizeof(Node));
    if (n == NULL) *deuCerto = 0;
    else *deuCerto = 1;

    return n;
}

void deleteNode(Node *n)
{
    if (n != NULL) free(n);
}

Lista *criar(int *deuCerto)
{
    Lista *L;

    L = malloc(sizeof(Lista));
    if (L == NULL) *deuCerto = 0;
    else {
        *deuCerto = 1;
        L->head = NULL; // lista vazia
    }

    return L;
}

int cheia(Lista *L)
{
    return 0;
}

int vazia(Lista *L)
{
    if (L->head == NULL) return 1;
    else return 0;
}

// Insere de maneira ordenada
void insere(Lista *L, int X, int *deuCerto)
{
    Node *p, *paux;
    int ok;

    p = newNode(&ok); // nao vou tratar o erro se ok == false...
    p->info = X;

    // primeiro caso: lista vazia
    if (vazia(L) == 1) {
        p->next = NULL;
        L->head = p;
        *deuCerto = 1;
    }
    else {
        paux = L->head;

        while(paux->next != NULL){
            paux = paux->next;
        }
        p->next = NULL;
        paux->next = p;
        *deuCerto = 1;
    }
}

void retira(Lista *L, int X, int *deuCerto)
{
    Node *p, *anterior;
    int achou;

    p = L->head; // p = L
    anterior = NULL;

    // avanca na lista
    while ((p != NULL) && (p->info < X)) {
        anterior = p;
        p = p->next;
    }

    if ((p != NULL) && (p->info == X))
        achou = 1;
    else achou = 0;

    if (achou == 1) {
        if (p != L->head) {
            anterior->next = p->next;
            deleteNode(p);
            p = NULL;
            anterior = NULL;
        } else {
            //L->head = L->head->next;
            L->head = p->next;
            deleteNode(p);
            p = NULL;
        } // fim if-else
        *deuCerto = 1;
    } else *deuCerto = 0;
}

void imprimeTodos(Lista *L)
{
    Node *p;

    p = L->head;

    while (p != NULL) {
        printf("%d ", p->info);
        p = p->next;
    }
    printf("\n");
}

int soma(Lista *L)
{
    int deucerto;
    Lista *Laux;

    Laux = criar(&deucerto);
    if(vazia(L) == 1) //se a lista estiver vazia
    {
        return 0;
    }
    else
    {
        Laux->head = L->head->next;
        return L->head->info + soma(Laux); //retorna a soma do numero atual com a lista que agora esta com 1 elemento a menos
    }
}

int somaImpares(Lista *L)
{
    Lista *Laux;
    int deucerto;

    Laux = criar(&deucerto);

    if(vazia(L)) //se a lista estiver vazia
    {
        return 0;
    }
    else
    {
        Laux->head = L->head->next; //o primeiro elemento de L passa para o proximo elemento
        if(L->head->info % 2 == 0) //se o numero for par
        {
            return somaImpares(Laux); //chama a funcao sem somar o numero
        }
        else
        {
            return L->head->info + somaImpares(Laux); //retorna a soma do numero atual com a lista que agora esta com 1 elemento a menos
        }
    }
}

void n_esimo(Lista *L, int N, int *nesimo)
{
    int deuCerto;
    Lista *L2;

    L2 = criar(&deuCerto);

    if(N==1){
        *nesimo = L->head->info;
    }
    else{
        L2->head = L->head->next;
        N = N - 1;
        n_esimo(L2, N, nesimo);
    }

}

void comprimento(Lista *L, int *elem)
{
    int deuCerto;
    Lista *L2;

    L2 = criar(&deuCerto);

    if(vazia(L) == 1){
        *elem = 0;
    }
    else if(L->head->next == NULL){
        *elem = 1;
    }
    else{
        int elem_cau;
        L2->head = L->head->next;
        comprimento(L2, &elem_cau);
        *elem = 1 + elem_cau;
    }
}

int main()
{
    Lista *L;
    int deuCerto;

    L = criar(&deuCerto);
    if (deuCerto == 0) {
        printf("Erro ao criar a lista\n");
        exit(1);
    }

    int X, N, entradas;

    scanf("%d%d", &X, &N);

    while(scanf("%d", &entradas) != EOF){
       insere(L, entradas, &deuCerto);
    }

    int nesimo, elem, som, som_i;

    som = soma(L);

    som_i = somaImpares(L);

    n_esimo(L, N, &nesimo);

    comprimento(L, &elem);

    imprimeTodos(L);

    printf("%d\n", som);
    printf("%d\n", som_i);
    printf("%d\n", nesimo);
    printf("%d\n", elem);


    return 0;
}
