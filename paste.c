#include "monty.h"
/**
 * f_pstr - Will print string starting at the top of the stack
 * @head: Top of stack
 * @count: number
 * Return: no return
*/
void f_pstr(stack_t **head, unsigned int count)
{
	stack_t *h;
	(void)count;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
