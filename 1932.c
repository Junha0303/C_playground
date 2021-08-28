#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {return a > b ? a : b;}

// void printArr(int **arr, int n)
// {
//     for(int i = 0; i < n; i++)
//     {
//         for(int j = 0; j <= i; j++)
//         {
//             printf("%d ", arr[i][j]);
//         }
//         printf("\n");
//     }
// }

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);

    int **data = (int **) malloc(sizeof(int *) * N);
    for(int i = 0; i < N; i++) data[i]= (int *) malloc(sizeof(int) * N);
    int **dp = (int **) malloc(sizeof(int *) * N);
    for(int i = 0; i < N; i++) dp[i]= (int *) malloc(sizeof(int) * N);

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            scanf("%d", &data[i][j]);
        }
    }

    dp[0][0] = data[0][0];
    for(int i = 1; i < N; i++)
    {
        dp[i][0] = dp[i - 1][0] + data[i][0];
        dp[i][i] = dp[i - 1][i - 1] + data[i][i]; 
        for(int j = 1; j < i; j++) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + data[i][j];
    }

    int ans = dp[N - 1][0];
    for(int i = 1; i < N; i++)
    {
        if(ans < dp[N - 1][i]) ans = dp[N - 1][i];
    }

    printf("%d\n", ans);

    return 0;
}
