#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    int sum = 0;
    
    /* Declare stack and initialize it. */
    struct stack stack;
    stack_init(&stack);
    
    for(int i = 0; i < N; i++)
    {
        int tmp;
        scanf("%d", &tmp);

        if(tmp == 0)
            stack_pop(&stack);
        else
            stack_push(&stack, &tmp);
    }

    stack_print_array(&stack);
    /* get sum */
    while(!stack_is_empty(&stack))
    {
        int val = *((int *)stack_pop(&stack));
        sum += val;
    }

    stack_destroy(&stack);
    printf("%d\n", sum);
    return 0;
}
