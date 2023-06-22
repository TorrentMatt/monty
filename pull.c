#include "monty.h"
/**
 * f_pall - Will print the stack
 * @head_t: Top of stack 
 * @counter: number used
 * Return: no return
*/
void f_pall(stack_t **head_t, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head_t;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
