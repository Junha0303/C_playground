#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MYLIE1 "I Like Midterm Exam"
#define MYLIE2 "I Like Midterm Exam Since It Is Easy"
#define SIZE 50

/*
char toLower(char c)
{
    return ((c >= 'a') ? c : c + ('a' - 'A'));
}

char *strcasestr(const char *s, const char *n)
{
    const char *sInx, *nInx;
    while(*s)
    {
        sInx = s;
        nInx = n;

        while((*nInx) && (*sInx))
        {
            if(toLower(*nInx) == toLower(*sInx))
            {
                nInx++;
                sInx++;
            }
            else break;
        }

        if(*nInx == '\0') return (char *)s;
        else if(*sInx == '\0') return NULL;
        else s++;
    }
    return NULL;
}
*/

/*
void swap(int *pa, int *pb)
{
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void swap_pointer(int **pa, int **pb)
{
    int *temp = *pa;
    *pa = *pb;
    *pb = temp;
}
*/

/*
void swap(int* arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void quickSort(int *arr, int left, int right)
{
    int mid, last;
    if(left >= right) return;

    mid = (left + right) / 2;   //pivot
    swap(arr, left, mid);       //now pivot is in leftmost side of arr
    last = left;

    for(int i = left + 1; i <= right; i++)
    {
        if(arr[i] <= arr[left])
        {
            //if elm is smaller than pivot then swap
            swap(arr, ++last, i);
        }   
    }
    
    swap(arr, last, left);

    quickSort(arr, left, last - 1);
    quickSort(arr, last + 1, right);
}

void merge(int* arr, int start, int mid, int end)
{
    int i, j;
    int inx = 0;
    int *temp = (int *)malloc(sizeof(int) * (end - start + 1));

    for(i = start, j = mid + 1; (i <= mid) && (j <= end); )
    {
        if(arr[i] < arr[j]) temp[inx++] = arr[i++];
        else temp[inx++] = arr[j++];
    }
    
    if(i == mid + 1)
    {
        while(j <= end) temp[inx++] = arr[j++];
    }

    if(j == end + 1)
    {
        while(i <= mid) temp[inx++] = arr[i++];
    }

    inx = 0;
    for(int k = start; k <= end; k++)
    {
        arr[k] = temp[inx++];
    }
}

void mergeSort(int *arr, int start, int end)
{
    if(start >= end) return;
    
    int mid = (start + end) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

void printArr(int *arr, int len)
{
    for(int i = 0; i < len; i++) printf("%d ", arr[i]);
    printf("\n");
}

*/

/*
void excludeInx(char *s, int inx, int len)
{
    for(int i = inx + 1; i < len; i++)
    {
        s[i - 1] = s[i];
    }
    s[len - 1] = '\0';
}

void addChar(char *str, char ch, int len)
{
    str[len] = ch;
    str[len + 1] = '\0';
}

void printCombination(const char *s, char *k, int len)
{
    if(len == 0)
    {
        //base case
        printf("%s\n", k);
        return;
    }

    for(int i = 0; i < len; i++)
    {
        char *ps = strdup(s);
        char *pk = strdup(k);
        char temp = ps[i];
        
        excludeInx(ps, i, len);
        addChar(pk, temp, strlen(pk));

        printCombination(ps, pk, len - 1);

        free(ps);
        free(pk);
    }
}


void printAllCombination(const char *s)
{
    char *p = strdup(s);
    if(p == NULL) return;

    char *k = malloc(sizeof(char) * strlen(p));

    printCombination(s, k, strlen(s));

    free(k);
    free(p);
}

*/

int main(int argc, char const *argv[])
{
    /*
    for(int i = 0; i < 10; i++)
    {
        printf("%d\n", i);
    }
    */

   char a[3] = "UN";
   char b[4] = "CAT";

   printf("%s %s\n", a, b);
}

