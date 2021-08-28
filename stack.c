#include "stack.h"

/* initialize stack.
* default size is 16, and its size is extensible. */

bool stack_init (struct stack *stack)
{
    assert(stack != NULL);
    
    stack->array = (void **) malloc (sizeof(void *) * DEFAULT_STACK_SIZE);
    if(stack->array == NULL)
        return false;
    
    stack->size = DEFAULT_STACK_SIZE;
    stack->top = 0;
    return true;
}

bool stack_expand (struct stack *stack)
{
    assert(stack != NULL);

    int new_size = stack->size * 2;
    stack->array = (void **) realloc(stack->array, sizeof(void *) * new_size);
    if(stack->array == NULL)
        return false;
    
    stack->size = new_size;
    return true;
}

bool stack_is_empty (struct stack *stack)
{
    assert(stack != NULL);
    return (stack->top == 0);
}

void **stack_get_array (struct stack *stack)
{
    assert(stack != NULL);
    return stack->array;
}

int stack_get_size (struct stack *stack)
{
    assert(stack != NULL);
    return stack->size;
}

int stack_get_length (struct stack *stack)
{
    assert(stack != NULL);
    return stack->top;
}

bool stack_push (struct stack *stack, void *item)
{
    if(stack->top == stack->size)
    {
        // need to be expanded
        if(!stack_expand(stack))
            return false;
    }

    stack->array[stack->top++] = item;
    return true;
}

void *stack_pop (struct stack *stack)
{
    if(stack_is_empty(stack))
        return NULL;
    
    return stack->array[--stack->top];
}

void *stack_get_item (struct stack *stack, int inx)
{
    if(stack->top <= inx)
        return NULL;
    
    return stack->array[inx];
}

/* use only for int type stack */
void stack_print_array (struct stack *stack)
{
    printf("====== STACK BOTTOM ======\n");
    for(int i = 0; i < stack->top; i++)
        printf("%d\n", *((int *)stack->array[i]));
    printf("======== STACK TOP ========\n");
}

void stack_destroy (struct stack *stack)
{
    free(stack->array);
}