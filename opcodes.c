#include "monty.h"

/**
 * pop_top_stack - removes a node to the stack
 * @stack: pointer to pointer pointing to top stack
 * @line_number: integer representing tthe line number
 */
void pop_top_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * print_top_stack - prints the top of the stack
 * @stack: pointer to the top node
 * @line_number: int representing opcode
 */
void print_top_stack(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}

/**
 * add_stack - adds a node to the stack
 * @new_node: pointer to the new node
 * @line: interger represenitng the line number of the opcode
 */
void add_stack(stack_t **new_node, __attribute__((unused))unsigned int line)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	head = *new_node;
	head->next = temp;
	temp->prev = head;
}

/**
 * print_stack - prints all nodes in a stack
 * @stack: pointer to top node
 * @line_number: representing the line number of the opcode
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * add_to_queue - adds a node to a queue
 * @new_node: pointer to the new node
 * @line: line number of the opcode
 */
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int line)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *new_node;
	(*new_node)->prev = temp;
}
