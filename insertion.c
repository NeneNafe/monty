#include "monty.h"

stack_t *stack = NULL;

/**
 * push - an insertion function to a stack
 * @stack: this is the pointer to the stack
 * @line_number: tthe integer value of the pushed 
 * numbers
 * Return: the new file
 */
void push(stack_t **stack, unsigned int line_number)
{
	if (!data)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node)
	{
		if (!new_node)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		new_node.n = atoi(data);
		new_node.prev = new_node;
	}
	else
	{
		new_node.next = NULL;
	}
	*stack = new_node;
}

/**
 * pall - prints all values that are in the stack
 * @stack: double pointer to a stack
 * @line_number: the number of lines
 * Return: All printed vals
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (!current)
	{
		return;
	}
	while (current)
	{
		printf("%d\n", current.n);
		current = current.next;
	}
}
