#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int getDigit (int num)
{
    int cnt = 0;
    while(num != 0)
    {
        num /= 10;
        cnt++;
    }
    
    return cnt;
}

char *toString (int num, int *length)
{
    int digits = getDigit(num);
    char *result = (char *) calloc (digits + 1, sizeof(char));
    
    *length = digits;
    while(num != 0)
    {
        result[--digits] = '0' + (num % 10);
        num /= 10;
    }

    return result;
}

char *concatStr (const char *str1, const char *str2)
{
    int strlen1 = strlen(str1);
    int strlen2 = strlen(str2);
    int totalLength = strlen1 + strlen2;
    
    char *resStr = (char *) calloc (totalLength + 1, sizeof(char));
    
    for(int i = 0; i < strlen1; i++)
        resStr[i] = str1[i];
    for(int i = 0; i < strlen2; i++)
        resStr[i + strlen1] = str2[i];
    
    return resStr;
}

void makeString (char *container, char **pool, int numbers_len)
{
    int global_inx = 0;
    for(int i = 0; i < numbers_len; i++)
    {
        int local_inx = 0;
        while(pool[i][local_inx] != '\0')
            container[global_inx++] = pool[i][local_inx++];
    }
}

int compare (const void *first, const void *second)
{
    char *firstStr = *(char **)first;
    char *secondStr = *(char **)second;

    char *firstCatStr = concatStr(firstStr, secondStr);
    char *secondCatStr = concatStr(secondStr, firstStr);

    int compRes = strcmp(firstCatStr, secondCatStr);

    free(firstCatStr);
    free(secondCatStr);

    return -compRes;
}

void dumpPool(char **pool, size_t numbers_len) {
    printf("======Pool Dump Result======\n");
    for(int i = 0; i < numbers_len; i++)
        printf("%d : %s\n", i, pool[i]);
    printf("============================\n");
}

// numbers_len은 배열 numbers의 길이입니다.
char* solution(int numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    
    int totallength = 0;
    
    // allocate pool
    char **pool = (char **) malloc (sizeof(char *) * numbers_len);
    
    // construct pool
    int tmp;
    for(int i = 0; i < numbers_len; i++)
    {
        pool[i] = toString(numbers[i], &tmp);
        totallength += tmp;
    }
    
    //dumpPool(pool, numbers_len);
    qsort(pool, numbers_len, sizeof(char *), compare);
    //dumpPool(pool, numbers_len);
    
    char *resString = (char *) calloc (totallength + 1, sizeof(char));
    makeString(resString, pool, numbers_len);
    
    for(int i = 0; i < numbers_len; i++)
        free(pool[i]);
    free(pool);

    return resString;
}

int main(int argc, char const *argv[])
{
    int arr[5] = {3, 30, 34, 5, 9};
    printf("%s\n", solution(arr, 5));
    return 0;
}
