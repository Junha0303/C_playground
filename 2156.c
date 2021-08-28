#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) (a) > (b) ? (a) : (b)
#define MAX_3(a, b, c) MAX(MAX(a, b), c)

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);

    int *wine = (int *)malloc(sizeof(int) * N);
    int *dp = (int *)malloc(sizeof(int) * N);
    for(int i = 0; i < N; i++) scanf("%d", &wine[i]);

    dp[0] = wine[0];
    dp[1] = wine[0] + wine[1];
    dp[2] = MAX_3(wine[0] + wine[1], wine[0] + wine[2], wine[1] + wine[2]);

    for(int i = 3; i < N; i++)
    {
        dp[i] = MAX(dp[i - 3] + wine[i - 1] + wine[i], dp[i - 2] + wine[i]);
        dp[i] = MAX(dp[i], dp[i - 1]);
    }
    
    int max = -1;
    for(int i = 0; i < N; i++) {
        if(dp[i] > max) max = dp[i];
    }
    printf("%d\n", max);

    return 0;
}
