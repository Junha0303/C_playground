#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char *a = "abcdefgh";
    char *b = "abcdef";
    
    char tmp[100];

    memcpy((void *)tmp, (void *)a, 6);
    printf("%d\n", strlen(tmp));
}
