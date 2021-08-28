#include <stdio.h>
#include <math.h>

int alphaCentauri(int n)
{
    if(n <= 3) return n;

    int i = floor(sqrt((double)n));
    if(i * i == n) return 2 * i - 1;
    else if((n > i * i )&& (n <= i * (i + 1))) return 2 * i;
    else return 2 * i + 1;
}

int main(int argc, char const *argv[])
{
    int T, src, dest; 
    scanf("%d", &T);
    for(int i = 0; i < T; i++) {
        scanf("%d %d", &src, &dest);
        int N = dest - src;
        printf("%d\n", alphaCentauri(N));
    }
    return 0;
}
