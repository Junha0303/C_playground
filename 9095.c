#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int T, N;
    scanf("%d %d", &T, &N);
    int dp[12] = {1, 2, 4, };
    while(T--)
    {
        scanf("%d", &N);
        for(int i = 3; i < N; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        printf("%d\n", dp[N - 1]);
    }
    return 0;
}
