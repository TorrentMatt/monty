#include "monty.h"
void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);

/**
 * usage_error - Will print usage error messages.
 * Return: (EXIT_FAILURE) always.
 */
int usage_error(void)
{
    fprintf(stderr, "USAGE: monty file\n");
    return (EXIT_FAILURE);
}


/**
 * malloc_error - Will print malloc error messages.
 * Return: (EXIT_FAILURE) always.
 */
int malloc_error(void)
{
    fprintf(stderr, "Error: malloc failed\n");
    return (EXIT_FAILURE);
}


/**
 * f_open_error - Will print file opening error messages 
 * @filename: Name of file
 * Return: (EXIT_FAILURE) always.
 */
int f_open_error(char *filename)
{
    fprintf(stderr, "Error: Can't open file %s\n", filename);
    return (EXIT_FAILURE);
}


/**
 * unknown_op_error - Will print unknown instruction error messages.
 * @opcode: Opcode 
 * @line_num: number
 *
 * Return: (EXIT_FAILURE) always.
 */
int unknown_op_error(char *opcode, unsigned int line_num)
{
    fprintf(stderr, "L%u: unknown instruction %s\n",
        line_num, opcode);
    return (EXIT_FAILURE);
}


/**
 * no_int_error - Will print invalid  argument error messages.
 * @line_numb: number
 *
 * Return: (EXIT_FAILURE) always.
 */
int no_int_error(unsigned int line_num)
{
    fprintf(stderr, "L%u: usage: push integer\n", line_num);
    return (EXIT_FAILURE);
}

