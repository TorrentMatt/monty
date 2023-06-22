#include "monty.h"
/**
 * f_pint - Will print the top of stack
 * @head: Top of the stack
 * @count: number
 * Return: no return
*/
void f_pint(stack_t **head, unsigned int count)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can not print stack, stack empty\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
