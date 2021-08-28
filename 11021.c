#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    if(b >= c)
    {
        // Not exist
        printf("-1\n");
        return 0;
    }

    printf("%d\n", (a / (c - b)) + 1);
    return 0;
}
