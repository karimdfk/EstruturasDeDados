#include<stdlib.h>
#include<stdio.h>

void fun(int *vet, int n)
{
    int i;

    for (i = 0; i < n; i++)
        vet[i] = i * 2;
}

int main()
{
    int i, n;
    int *v;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    // cria um vetor de N inteiros
    v = malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
        v[i] = i;

    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");

    fun(v, n);

    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");

    free(v);

    return 0;
}
