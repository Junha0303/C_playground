#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    int *data = (int *)malloc(sizeof(int) * N);
    int *dp = (int *)malloc(sizeof(int) * N);
    for(int i = 0; i < N; i++) scanf("%d", &data[i]);

    dp[0] = 1;

    for(int i = 1; i < N; i++)
    {
        int temp = 0;
        for(int j = 0; j < i; j++)
        {
            if(data[i] > data[j]) 
            {
                if(temp < dp[j]) temp = dp[j];
            }
        }
        dp[i] = temp + 1;
    }
    
    int ans = 1;
    for(int i = 1; i < N; i++)
    {
        if(ans < dp[i]) ans = dp[i];
    }
    printf("%d\n", ans);
    return 0;
}
