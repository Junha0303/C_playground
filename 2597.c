#include <stdio.h>
#include <math.h>

#define MAX(a, b) ((a) > (b)) ? (a) : (b)

int stair(int *score, int *mem, int n)
{
    if(mem[n]) return mem[n];
    if(n == 1) return (mem[1] = score[1]);
    if(n == 2) return (mem[2] = score[1] + score[2]);
    if(n == 3) return (mem[3] = MAX(score[1] + score[3], score[2] + score[3]));
    else
    {
        mem[n] = MAX(stair(score, mem, n - 2) + score[n], stair(score, mem, n - 3) + score[n - 1] + score[n]);
        return mem[n];
    }
    
}


int main(int argc, char const *argv[])
{
    int n, score[301] = {0, }, mem[301] = {0, };

    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &score[i]);

    printf("%d\n", stair(score, mem, n));
    return 0;
}
