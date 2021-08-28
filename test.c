#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *p1 = (char *)malloc(sizeof(char) * 3);
    strcpy(p1, "Hi");

    free(p1);
    p1 = NULL;
} 