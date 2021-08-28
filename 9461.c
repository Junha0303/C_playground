#include <stdio.h>

typedef long long ll;

ll mem[101] = {0, 1, 1, 1, 2, 2, };

ll waveSeq(int n)
{
    if(mem[n]) return mem[n];
    else return (mem[n] = waveSeq(n - 1) + waveSeq(n - 5));
}

int main(int argc, char const *argv[])
{
     int T, N;
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        scanf("%d", &N);
        printf("%lld\n", waveSeq(N));
    }
    return 0;
}