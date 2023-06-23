#include "monty.h"

void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);
/**
 * monty_rotl - Will rotate the top value of a stack to the bottom.
 * @stack: top of stack
 * @line_num: number
 */
void monty_rotl(stack_t **stack, unsigned int line_num)
{
    stack_t *top, *bottom;


    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
        return;


    top = (*stack)->next;
    bottom = (*stack)->next;
    while (bottom->next != NULL)
        bottom = bottom->next;


    top->next->prev = *stack;
    (*stack)->next = top->next;
    bottom->next = top;
    top->next = NULL;
    top->prev = bottom;


    (void)line_num;
}


/**
 * monty_rotr - Wil rotate the bottom value of a stack to the top.
 * @stack: Top of stack
 * @line_num: number
 */
void monty_rotr(stack_t **stack, unsigned int line_num)
{
    stack_t *top, *bottom;


    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
        return;


    top = (*stack)->next;
    bottom = (*stack)->next;
    while (bottom->next != NULL)
        bottom = bottom->next;


    bottom->prev->next = NULL;
    (*stack)->next = bottom;
    bottom->prev = *stack;
    bottom->next = top;
    top->prev = bottom;


    (void)line_num;
}


/**
 * monty_stack - Will convert  queue to a stack.
 * @stack: top of stack
 * @line_num: number
 */
void monty_stack(stack_t **stack, unsigned int line_num)
{
    (*stack)->n = STACK;
    (void)line_num;
}


/**
 * monty_queue - will convert a stack to a queue.
 * @stack: top of stack
 * @line_num: lin
 */
void monty_queue(stack_t **stack, unsigned int line_num)
{
    (*stack)->n = QUEUE;
    (void)line_num;
}

