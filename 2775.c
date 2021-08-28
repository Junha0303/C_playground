#include <stdio.h>

int getNum(int k, int n)
{
    // k : floor
    // n : room #

    if(k == 0) return n;
    if(n == 1) return 1;

    return (getNum(k, n - 1) + getNum(k - 1, n));
}

int main(int argc, char const *argv[])
{
    int k, n, rep;
    scanf("%d", &rep);
    
    for(int i = 0; i < rep; i++)
    {
        scanf("%d %d", &k, &n);
        printf("%d\n", getNum(k, n));
    }
    
    return 0;
}
