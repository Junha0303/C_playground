#include <stdio.h>

int main(int argc, char const *argv[])
{
    int count = 0;
    int n;
    scanf("%d", &n);
    while(n > 1)
    {
        count++;
        if(n & 1)
            n = n * 3 + 1;
        else
            n = n / 2;
    }

    printf("%d\n", count);
}
