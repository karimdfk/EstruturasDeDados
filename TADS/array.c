#include<stdlib.h>
#include<stdio.h>

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

    free(v);

    return 0;
}
