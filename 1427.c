#include <stdio.h>
#include <stdlib.h>

int intToArray(int *arr, int n)
{
    int mul = 10;
    int idx = 0;

    while(n != 0)
    {
        arr[idx++] = n % mul;
        n /= mul;
    }

    return idx;
}

int compare(const void *a, const void *b)
{
    int n1 = *(int *)a;
    int n2 = *(int *)b;
    if(n1 > n2) return 1;
    if(n1 < n2) return -1;
    return 0;
}

int main(int argc, char const *argv[])
{
    int N, arr[9];

    scanf("%d", &N);
    int length = intToArray(arr, N);
    qsort((void *)arr, (size_t)length, sizeof(int), compare);

    for(int i = length - 1; i >= 0; i--) printf("%d", arr[i]);
    printf("\n");
    
    return 0;
}
