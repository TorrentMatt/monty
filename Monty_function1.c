#include "monty.h"
void monty_add(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);

/**
 * monty_add - Will add top two values of a stack
 * Stack: Top of stack
 * line_num: number
 */
void monty_add(stack_t **stack, unsigned int line_num)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_error(short_stack_error(line_num, "add"));
        return;
    }


    (*stack)->next->next->n += (*stack)->next->n;
     monty_pop(stack, line_num);
}

/**
 * monty_sub -Will subtract the second value of stack
 * @stack: top of stack 
 * @line_num: number
 */
void monty_sub(stack_t **stack, unsigned int line_num)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_error(short_stack_error(line_num, "sub"));
        return;
    }


    (*stack)->next->next->n -= (*stack)->next->n;
    monty_pop(stack, line_num);
}


/**
 * monty_div - Will divide the second value from stack list
 * @stack: Top of stack
 * @line_num: number
 */
void monty_div(stack_t **stack, unsigned int line_num)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_error(short_stack_error(line_num, "div"));
        return;
    }


    if ((*stack)->next->n == 0)
    {
        set_op_tok_error(div_error(line_num));
        return;
    }


    (*stack)->next->next->n /= (*stack)->next->n;
    monty_pop(stack, line_num);
}


/**
 * monty_mul - Will multiply values from the top of a stack linked list
 * @stack: Top of stack
 * @line_num: number
 */
void monty_mul(stack_t **stack, unsigned int line_num)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_error(short_stack_error(line_num, "mul"));
        return;
    }


    (*stack)->next->next->n *= (*stack)->next->n;
    monty_pop(stack, line_num);
}


/**
 * monty_mod - Will computes the modulus of the value from the top of a stack
 * @stack: Top of stack
 * @line_number: number
 */
void monty_mod(stack_t **stack, unsigned int line_num)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_error(short_stack_error(line_num, "mod"));
        return;
    }


    if ((*stack)->next->n == 0)
    {
        set_op_tok_error(div_error(line_num));
        return;
    }


    (*stack)->next->next->n %= (*stack)->next->n;
    monty_pop(stack, line_num);
}

