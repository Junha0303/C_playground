#include <stdio.h>

void f(int x)
{
    f(x-1);
}

int main(int argc, char const *argv[])
{
    f(1);
    return 0;
}
