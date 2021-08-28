#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <unistd.h>

int staticVar = 0;

void test()
{
    staticVar += 1;
    sleep(10);   
    printf("Addr : %x, Val : %d\n", &staticVar, staticVar);
}
int main(int argc, char const *argv[])
{
    fork();
    test();
}
