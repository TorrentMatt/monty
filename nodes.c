#include "monty.h"
/**
 * addnode - Will add node to the head stack
 * @head: top of the stack
 * @num: number
 * Return: no return
*/
void addnode(stack_t **head, int num)
{

	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->prev = new_node;
	new_node->n = num;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
