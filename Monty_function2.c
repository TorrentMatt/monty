#include "monty.h"

/**
 * monty_nop - Will do absolutely nothing for the Monty opcode 'nop'.
 * @stack: Top of stack
 * @line_num: number
 */
void monty_nop(stack_t **stack, unsigned int line_num)
{
    (void)stack;
    (void)line_num;
}


/**
 * monty_pchar - Will print character in the top value node of stack
 * @stack:Top of stack
 * @line_num:number
 */
void monty_pchar(stack_t **stack, unsigned int line_num)
{
    if ((*stack)->next == NULL)
    {
        set_op_tok_error(pchar_error(line_num, "stack empty"));
        return;
    }
    if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
    {
        set_op_tok_error(pchar_error(line_num,
                         "value out of range"));
        return;
    }


    printf("%c\n", (*stack)->next->n);
}


/**
 * monty_pstr - Will print string contained instack
 * @stack: Top of stack
 * @line_num: number
 */
void monty_pstr(stack_t **stack, unsigned int line_num)
{
    stack_t *tmp = (*stack)->next;


    while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
    {
        printf("%c", tmp->n);
        tmp = tmp->next;
    }


    printf("\n");


    (void)line_num;
}
