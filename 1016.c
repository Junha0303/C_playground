#include <stdio.h>

typedef enum {false, true} bool;

bool result[1000001] = {false};
long long num[1000001] = {0};

int main(int argc, char const *argv[])
{
    long long min, max;
    scanf("%lld %lld", &min, &max);
    long long cnt = 0;

    for(long long i = 2; i * i <= max; i++)
    {
        num[i] = i * i;
        cnt++;
    }

    int count = 0;
    for(int i = 2; i < cnt + 2; i++)
    {
        long long div_min = min;
        if(div_min % num[i] != 0)
        {
            div_min = (min / num[i] + 1) * num[i];
        }

        for(long long tmp = div_min; tmp <= max; tmp += num[i])
        {
            if(!result[tmp - min])
            {
                result[tmp - min] = true;
                count++;
            }
        }
    }
    printf("%lld\n", max-min-count+1);
    return 0;
}
