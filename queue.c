#include "monty.h"
/**
 * f_queue -Will print the top stack
 * @head: Top of the stack
 * @count: Number
 * Return: no return
*/
void f_queue(stack_t **head, unsigned int count)
{
	(void)head;
	(void)count;
	bus.lifi = 1;
}

/**
 * addqueue - Will add node to tail stack
 * @num: number
 * @head: Top of stack
 * Return: no return
*/
void addqueue(stack_t **head, int num)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = num;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
