#include "monty.h"

/**
 * pop_error - Will print pop error  for empty stacks.
 * @line_num: number
 * Return: EXIT_FAILUR always.
 */
int pop_error(unsigned int line_num)
{
    fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
    return (EXIT_FAILURE);
}


/**
 * pint_error -Will print pint error messages 
 * @line_num: number
 * Return: (EXIT_FAILURE) always.
 */
int pint_error(unsigned int line_num)
{
    fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
    return (EXIT_FAILURE);
}


/**
 * short_stack_error - Will print monty math function error messages
 * @line_num: number
 * @op: Op
 * Return: (EXIT_FAILURE) always.
 */
int short_stack_error(unsigned int line_num, char *op)
{
    fprintf(stderr, "L%u: can't %s, stack too short\n", line_num, op);
    return (EXIT_FAILURE);
}


/**
 * div_error - Will print division error messages for division by 0.
 * @line_number: numbet
 * Return: (EXIT_FAILURE) always.
 */
int div_error(unsigned int line_num)
{
    fprintf(stderr, "L%u: division by zero\n", line_num);
    return (EXIT_FAILURE);
}


/**
 * pchar_error - Will prints pchar error messages for empty stacks
 * @line_num: number
 * @message: errrs mess
 * Return: (EXIT_FAILURE) always.
 */
int pchar_error(unsigned int line_num, char *message)
{
    fprintf(stderr, "L%u: can't pchar, %s\n", line_num, message);
    return (EXIT_FAILURE);
}
