/* read_and_print_one.h */
#ifndef READ_AND_PRINT_ONE
#define READ_AND_PRINT_ONE
#include <stdio.h>
#include <unistd.h>
static inline void read_and_print_one(int fd)
{
    char c;
    read(fd, &c, 1);
    printf("%c", c);
    fflush(stdout);
}
#endif