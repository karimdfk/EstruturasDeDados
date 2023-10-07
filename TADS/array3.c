#include<stdlib.h>
#include<stdio.h>

int main()
{
    int i;
    int m, n;
    int **mat;

    printf("Digite as dimensoes da matriz: ");
    scanf("%d %d", &m, &n);

    // alocando memoria
    mat = (int **) malloc(m * sizeof(int *));
    for (i = 0; i < m; i++) {
        mat[i] = (int *) malloc(n * sizeof(int));
    }

    // liberando memoria
    for (i = 0; i < m; i++)
        free(mat[i]);
    free(mat);


    return 0;
}
