#include "monty.h"
/**
  *f_sub- Will sustration
  *@head: Top of the stack
  *@count: number
  *Return: no return
 */
void f_sub(stack_t **head, unsigned int count)
{
	stack_t *aux;
	int ss, nodes;

	aux = *head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can not subtract stack, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	ss = aux->next->n - aux->n;
	aux->next->n = ss;
	*head = aux->next;
	free(aux);
}
