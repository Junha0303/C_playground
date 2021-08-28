#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char data[100];
    char *tmpstr = "Hello";
    int a = 300;
    short cursor = 0;

    memcpy(data, tmpstr, strlen(tmpstr));
    cursor += strlen(tmpstr);

    memcpy(data + cursor, &a, sizeof(a));

    char* b = (char *)data;
    int c = *((int *)(data + cursor));

    printf("%s\n", data);
    return 0;
}
