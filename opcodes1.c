#include "monty.h"

/**
 * nop - does nothing
 * @stack: pointer to a node of the stack
 * @line_number: line number of the opcode
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to top node
 * @line_number: line number of the opcode
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "swap");
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}
