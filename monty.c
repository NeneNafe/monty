#include "monty.h"

stack_t *head = NULL;

/**
 * main - Entry Point
 * @argc: the number of command line args
 * @argv: An array containing args
 * Return: Always Success.
 */
int main(int argc, char **argv)
{
	if (argc < 2 || argc > 2)
		err(1);

	open_file(argv[1]);
	free_nodes();

	return (0);
}

/**
 * create_node - add a node and populates it
 * @n: the number to go inside the node
 * Return: Succes.
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nodes - frees all the nodes in a stack
 */
void free_nodes(void)
{
	stack_t *temp;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
