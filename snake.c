#include <stdio.h>
#define LINEBREAK 3

void printSpace(int n)
{
    for(int i = 0; i < n; i++) printf(" ");
    return;
}

void printSnake(int period, int length, char *str)
{
    int sp = 0;
    int inx = 0;
    int adder = 1;

    while(inx <= length)
    {
        for(int i = 0; i < LINEBREAK; i++) 
        {
            printSpace(sp * 2);
            printf("%s\n", str);
        }
        inx++;

        sp += adder;
        if(sp == period - 1 || sp == 0) adder = -adder;
    }
    
    return;
}

int main(int argc, char const *argv[])
{
    int p, l;
    char str[100];
    printf("INPUT STRING (MAXLEN = 100): ");
    scanf("%s", str);
    printf("INPUT PERIOD : ");
    scanf("%d", &p);
    printf("INPUT LENGTH : ");
    scanf("%d", &l);

    printSnake(p, l / 3, str);
    return 0;
}
