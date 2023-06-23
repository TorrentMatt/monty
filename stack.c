#include "monty.h"
#include <string.h>

/**
 * free_stack - Will Free  stack.
 * @stack: Top of stack.
 */
void free_stack(stack_t **stack)
{
    stack_t *tmp = *stack;


    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
}


/**
 * init_stack - Will initialize a stack 
 * @stack: Top of stack
 *Return: 0
 */
int init_stack(stack_t **stack)
{
    stack_t *v;


    v = malloc(sizeof(stack_t));
    if (v == NULL)
        return (malloc_error());


    v->n = STACK;
    v->prev = NULL;
    v->next = NULL;


    *stack = v;


    return (EXIT_SUCCESS);
}


/**
 * check_mode - Checks a stack
 * @stack: Top of stack
 * Return: stacks.
 */
int check_mode(stack_t *stack)
{
    if (stack->n == STACK)
        return (STACK);
    else if (stack->n == QUEUE)
        return (QUEUE);
    return (2);
}

