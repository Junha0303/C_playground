#include <stdio.h>
#include <pthread.h>

typedef unsigned char byte_t;

int count_ones(byte_t b)
{
    byte_t mask = 0x01;
    int cnt = 0;

    for (int i = 0; i < 8; i++)
    {
        if (b & mask)
            cnt++;
        
        mask <<= 1;
    }

    return cnt;
}

int main(int argc, char const *argv[])
{
    byte_t num;
    scanf("%u", &num);

    printf("%d\n", count_ones(num));
    return 0;
}
