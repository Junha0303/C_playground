#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b, v;
    scanf("%d %d %d", &a, &b, &v);

    printf("%d\n", ((v - a) % (a - b) == 0 ? ((v - a) / (a - b)) + 1 : ((v - a) / (a - b)) + 2));
    return 0;
}
