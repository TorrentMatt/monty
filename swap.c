#include "monty.h"
/**
 * f_swap - Will add the top two elements of the stack.
 * @head: stack head
 * @count: number
 * Return: no return
*/
void f_swap(stack_t **head, unsigned int count)
{
	stack_t *h;
	int leng = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		leng++;
	}
	if (leng < 2)
	{
		fprintf(stderr, "L%d: can not swap, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}
