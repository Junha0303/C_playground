#include <stdio.h>
#include <stdlib.h>

void g(char **a, char **b)
{
    *a = *b;
}

void printArray(int *a, int n)
{
    for(int i = 0; i < n; i++) printf("%d ", *(a + i));
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int *a = (int *)malloc(sizeof(int) * 3);
    int *b = (int *)malloc(sizeof(int) * 3);

    a[0] = 1; a[1] = 2; a[2] = 3;
    b[0] = 4; b[1] = 5; b[2] = 6;

    printArray(a, 3);
    a = b;
    printArray(a, 3);

    free(a); free(b);
}
