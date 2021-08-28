#include <stdio.h>
#include <stdlib.h>

typedef enum{FALSE, TRUE} boolean;
typedef enum{EXG, RL, EMB} mode;

boolean isIn(int *arr, int key, int len)
{
    boolean res = FALSE;
    for(int i = 0; i < len; i++) {
        if(arr[i] == key) {
            res = TRUE;
            break;
        }
    }

    return res;
}

void combine(int *arr1, int *arr2, int* arr1len, int* arr2len)
{
    for(int i = 0; i < *arr2len; i++)
    {   
        if(!isIn(arr1, arr2[i], *arr1len)) arr1[(*arr1len)++] = arr2[i];
    }
}

mode whatToSay(int *row, int *knowR, int *knowE, int len, int kN, int eN)
{
    boolean r = FALSE, e = FALSE;
    mode res = EXG;

    for(int i = 0; i < len; i++)
    {
        if(isIn(knowR, row[i], kN)) r = TRUE;
        if(isIn(knowE, row[i], eN)) e = TRUE;

        if(r && e) break;
    }
    
    if(r && e) {
        res = EMB;
        return res;
    }

    else if(r) {
        res = RL;
        return res;
    }

    else return res;
}

int main(int argc, char const *argv[])
{
    //define variables
    int N, M;
    int kN; //# of people who know real
    int eN = 0; //# of people who know exg info
    int res = 0; //result

    //dealing with input and define arrays
    scanf("%d %d", &N, &M);
    int *knowR = (int *)malloc(sizeof(int) * N);    // ids of people who know real
    int *knowE = (int *)malloc(sizeof(int) * N);    // ids of people who know exaggerated info

    int *nPeople = (int *)malloc(sizeof(int) * M);  // # of people who come to (i + 1)th party
    int **party = (int **)malloc(sizeof(int *) * M);
    for(int i = 0; i < M; i++) party[i] = (int *)malloc(sizeof(int) * N);

    scanf("%d", &kN);
    for(int i = 0; i < kN; i++) scanf("%d", &knowR[i]);

    for(int i = 0; i < M; i++)
    {
        scanf("%d", &nPeople[i]);
        for(int j = 0; j < nPeople[i]; j++) scanf("%d", &party[i][j]);
    }

    //evaluation
    for(int i = 0; i < M; i++)
    {
        
    }

    return 0;
}
