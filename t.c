#include <stdio.h>

int main(int argc, char const *argv[])
{
    long long num = 1LL << 63;
    printf("%lld\n", num);
    printf("%lu\n", sizeof(long long));
}
