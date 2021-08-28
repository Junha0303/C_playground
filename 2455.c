#include <stdio.h>

int main(int argc, char const *argv[])
{
    int max = -1;
    int prev = 0;
    int in, out;

    for(int i = 0; i < 4; i++)
    {
        scanf("%d %d", &out, &in);
        prev = prev - out + in;
        if(prev > max) max = prev;
    }

    printf("%d\n", max);
    return 0;
}
