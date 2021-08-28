#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    if(num1 > num2) return 1;
    if(num1 < num2) return -1;
    return 0;
}

int binarySearch(int *arr, int first, int last, int target)
{
    if (first >= last)
    {
        if(arr[first] == target) return first;
        else return -1;
    }
    int mid = (first + last) / 2;
    if(target < arr[mid]) return binarySearch(arr, first, mid - 1, target);
    else if(target == arr[mid]) return mid;
    else return binarySearch(arr, mid + 1, last, target);
}

int main(int argc, char const *argv[])
{
    int N, M, narr[100001], marr[100001];
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &narr[i]);
    qsort((void *)narr, (size_t)N, sizeof(int), compare);
    scanf("%d", &M);
    for(int i = 0; i < M; i++) scanf("%d", &marr[i]);

    for(int i = 0 ; i < M; i++)
    {
        int target = marr[i];
        int result = (binarySearch(narr, 0, N - 1, target) == -1) ? 0 : 1;
        printf("%d\n", result);
    }
    return 0;
}
