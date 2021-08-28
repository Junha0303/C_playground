#include <stdio.h>

struct foo {
    int a;
    int b;
};

void printFoo(struct foo *f);

int main(int argc, char const *argv[])
{
    struct foo f = {.a = 1, .b = 2};

    printFoo(&f);
}

void printFoo(struct foo *f)
{
    f->a = 10;
    f->b = 20;

    printf("%d %d\n", f->a, f->b);
}
