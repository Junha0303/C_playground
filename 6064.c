#include <stdio.h>

int gcd(int x, int y)
{
    int n;
    while(y != 0)
    {
        n = x % y;
        x = y;
        y = n;
    }
    return x;
}

int lcm(int x, int y)
{
    return (x * y) / gcd(x, y);
}

int ans(int N, int M, int x, int y)
{
    if(x > N || y > M) return -1;
    int l = lcm(N, M);
    
    for(;;)
    {
        if((x > l) || ((x - 1) % M + 1 == y)) break;
        x += N;
    }

    if(x > l) return -1;
    else return x;
}

int main(int argc, char const *argv[])
{
    int rep, N, M, x, y;
    scanf("%d", &rep);

    while(rep--)
    {
        scanf("%d %d %d %d", &N, &M, &x, &y);
        printf("%d\n", ans(N, M, x, y));
    }
    return 0;
}
