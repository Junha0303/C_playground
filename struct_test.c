#include <stdio.h>

struct A
{
    int a;
    char b[10];
    char c;
};

int main(int argc, char const *argv[])
{
    struct A *a = NULL;
    if(a == NULL || a->a == 4)
    {
        printf("HI THERE\n");
        return 0;
    }
}
