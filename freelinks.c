#include "monty.h"
/**
* free_stack -Will free a doubly linked list
* @head: Top of the stack
*/
void free_stack(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}
