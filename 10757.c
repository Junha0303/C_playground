#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

char *sumBigInt(const char *a, const char *b)
{
    int i = strlen(a);
    int j = strlen(b);

    int size = MAX(i, j);
    if((i == j) && ((a[0] - '0') + (b[0] - '0') >= 10)) size++;
    char *res = (char *)malloc(sizeof(char) * (size + 1));

    int carry = 0;
    int cur_a, cur_b;

    res[size] = '\0';
    int loc = size - 1;

    i--;
    j--;
    while(i >= 0 || j >= 0)
    {
        if(i < 0) cur_a = 0;
        else cur_a = a[i--] - '0';

        if(j < 0) cur_b = 0;
        else cur_b = b[j--] - '0';

        int tempDigit = cur_a + cur_b + carry;
        if(tempDigit >= 10){
            tempDigit -= 10;
            carry = 1;
        }
        else carry = 0;

        res[loc--] = '0' + tempDigit;
    }

    if(carry) res[loc] = '0' + carry;

    return res;
}

int main(int argc, char const *argv[])
{
    char a[10001];
    char b[10001];
    scanf("%s %s", a, b);

    char *res = sumBigInt(a, b);
    printf("%s\n", res);
    free(res);
    return 0;
}
