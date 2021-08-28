#include <stdio.h>
#include "mystring.h"
#include <stdlib.h>

typedef enum _bool {false, true} bool;

char **parse_path (char *path, int *size)
{
    char *path_copy = (char *) malloc (sizeof(char) * (strlen(path) + 1)); //bounce
    if(path_copy == NULL)
        return NULL;
    strcpy(path_copy, path);

    char *token, *saved_ptr; 
    int n = 0;

    for(token = strtok_r(path_copy, "/", &saved_ptr); token != NULL; token = strtok_r(NULL, "/", &saved_ptr))
        n++;
    strcpy(path_copy, path);

    char **parse = malloc(sizeof(char *) * (n + 1));
    if(parse == NULL)
    {
        free(path_copy);
        return NULL;
    }

    int inx = 0;
    for(token = strtok_r(path_copy, "/", &saved_ptr); token != NULL; token = strtok_r(NULL, "/", &saved_ptr))
    {
        size_t token_size = strlen(token) + 1;
        char *token_copy = (char *) malloc (sizeof(char) * token_size);
        if(token_copy == NULL)
        {
            free(path_copy);
            for(int i = 0; i < inx; i++)
                free(parse[i]);
            free(parse);

            return NULL;
        }

        strncpy(token_copy, token, token_size);
        parse[inx++] = token_copy;
    }

    free(path_copy); 
    *size = inx;
    return parse;
}

void free_parsed_path(char **parse, int size)
{
    for(int i = 0; i < size; i++)
        free(parse[i]);
    free(parse);
}

void print_2d_array(char **arr, int size)
{
    for(int i = 0; i < size; i++)
        printf("%s\n", arr[i]);
}

int main(int argc, char const *argv[])
{
    int size;
    char **parse = parse_path("/ /", &size);
    printf("%d\n", size);
    print_2d_array(parse, size);
    free_parsed_path(parse, size);

    unsigned int x = -1;
    printf("💕💕\n");

    return 0;
}
