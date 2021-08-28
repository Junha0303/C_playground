#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);

    int **dp = (int **)malloc(sizeof(int*) * N);
    for(int i = 0; i < N; i++) dp[i] = (int *)malloc(sizeof(int) * 10);

    dp[0][0] = 0;
    for(int i = 1; i <= 9; i++) dp[0][i] = 1;

    for(int i = 1; i < N; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(j == 0) dp[i][j] = dp[i - 1][1];
            else if(j == 9) dp[i][j] = dp[i - 1][8];
            else
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
            }
        }
    }

    int res = 0;
    for(int i = 0; i < 10; i++) res = (res + dp[N - 1][i]) % 1000000000;

    printf("%d\n", res);
    return 0;
}
