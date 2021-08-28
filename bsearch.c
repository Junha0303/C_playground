#include <stdio.h>

int bs(int *arr, int len, int k, int *resinx)
{
    int low = 0;
    int high = len - 1;
    int mid;

    while (low < high)
    {
        mid = (low + high) / 2;
        printf("%d %d %d\n", low, mid, high);
        if (k > arr[mid])
            low = mid + 1;
        else if (k < arr[mid])
            high = mid - 1;
        else
        {
            *resinx = mid;
            return 1;
        }
    }
    printf("%d %d %d\n", low, mid, high);

    if (k == arr[low])
    {
        *resinx = low;
        return 1;
    }
    else if (k > arr[low])
    {
        *resinx = low;
        return 0;
    }
    else
    {
        *resinx = low - 1;
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int *resinx;
    int res = bs(arr, 8, 9, resinx);

    if (res)
    {
        printf("Entry Found At : %d\n", *resinx);
    }
    else
    {
        printf("Entry Not Found, the nearest and smaller than k is %d\n", *resinx);
    }

    return 0;
}
