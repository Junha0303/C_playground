#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    printf("SEX");
    fflush(stdout);
    sleep(1);
    printf("\rHI\n");
    return 0;
}
