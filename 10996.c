#include <stdio.h>

void printStars(int n)
{
    if(n == 1){
        printf("*");
        return;
    }

    int f = (n % 2 == 0) ? n / 2 : (n / 2) + 1;
    int s = n - f;

    for(int i = 0; i < f; i++) printf("* ");
    printf("\n");
    for(int i = 0; i < s; i++) printf(" *");
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);

    for(int i = 0 ; i < N; i++) printStars(N);

    return 0;
}
