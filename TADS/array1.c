#include<stdlib.h>
#include<stdio.h>

int main()
{
    int i, n = 10;
    int v[10];

    for (i = 0; i < n; i++)
        *(v + i) = i;

    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");

    return 0;
}
