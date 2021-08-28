#include <stdio.h>
#include <stdlib.h>

int MIN(int a, int b) {return a > b ? b : a;}
int MIN_3(int a, int b, int c) {return MIN(MIN(a, b), c);}

// void print2dArr(int **arr, int h, int w)
// {
//     for(int i = 0; i < h; i++)
//     {
//         for(int j = 0; j < w; j++)
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

    int **data = (int **)malloc(sizeof(int *) * N);
    int **dp = (int **)malloc(sizeof(int *) * N);
    for(int i = 0; i < N; i++) data[i] = (int *)malloc(sizeof(int) * 3);
    for(int i = 0; i < N; i++) dp[i] = (int *)malloc(sizeof(int) * 3);
    
    for(int i = 0; i < N; i++) scanf("%d %d %d", &data[i][0], &data[i][1], &data[i][2]);

    for(int i = 0; i < 3; i++) dp[0][i] = data[0][i];
    for(int i = 1; i < N; i++)
    {
        dp[i][0] = MIN(dp[i - 1][1], dp[i - 1][2]) + data[i][0];
        dp[i][1] = MIN(dp[i - 1][0], dp[i - 1][2]) + data[i][1];
        dp[i][2] = MIN(dp[i - 1][0], dp[i - 1][1]) + data[i][2];
    }
    printf("%d\n", MIN_3(dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]));
}
