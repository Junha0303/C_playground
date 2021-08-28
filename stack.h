#ifndef __STACK_H__
#define __STACK_H__

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#define DEFAULT_STACK_SIZE 16
#define NULL (void *)0

struct stack {
    void **array;
    int top;
    int size;
};

typedef enum {
    true,
    false
} bool;

bool stack_init (struct stack *stack);
bool stack_is_empty (struct stack *stack);
int stack_get_size (struct stack *stack);
void **stack_get_array (struct stack *stack);
int stack_get_length (struct stack *stack);
bool stack_push (struct stack *stack, void *item);
void *stack_pop (struct stack *stack);
void *stack_get_item (struct stack *stack, int inx);
void stack_print_array (struct stack *stack);
void stack_destroy (struct stack *stack);

#endif