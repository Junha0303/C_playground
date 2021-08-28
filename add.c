#include <stdio.h>

int f(int a, int b)
{
    return a+b;
}

int main(int argc, char const *argv[])
{
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    
    printf("%d\n", f(a, b));
    return 0;
}
