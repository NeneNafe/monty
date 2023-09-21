#include "monty.h"

/**
 * err - handles all the errors that the prog meets
 * @error_code: the error coded
 * (1) - the user does not give any file to the prog
 * (2) - the file cannot not be opened or read
 * (3) - the contains invalid instructions
 * (4) - when there are memory leaks
 * (5) - when parameter passed to instruction push is not an int
 * (6) - if the stack is empty for pint
 * (7) - if the stack is empty for pop
 * (8) - when the stack is too short for operation
 */
void err(int error_code, ...)
{
	va_list argument;
	char *opcode;
	int num;

	va_start(argument, error_code);
	switch (error_code)
	{
		case 1:
			printf("USAGE: monty file\n");
			break;
		case 2:
			printf("Error: Can't open file %s\n",
					va_arg(argument, char *));
			break;
		case 3:
			num = va_arg(argument, int);
			opcode = va_arg(argument, char *);
			printf("L%d: unknown instruction %s\n", num, opcode);
			break;
		case 4:
			printf("Error: malloc failed\n");
			break;
		case 5:
			printf("L%d: usage: push integer\n", va_arg(argument, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_err - handles more errors
 * @error_code: the followint
 * (9) - Division by zero
 */
void more_err(int error_code, ...)
{
	va_list argument;
	char *opcode;
	int num;

	va_start(argument, error_code);
	switch (error_code)
	{
		case 6:
			printf("L%d: can't pint, stack empty\n",
					va_arg(argument, int));
			break;
		case 7:
			printf("L%d: can't pop an empty stack\n",
					va_arg(argument, int));
			break;
		case 8:
			num = va_arg(argument, unsigned int);
			opcode = va_arg(argument, char *);
			printf("L%d: can't %s, stack t short\n", num, opcode);
			break;
		case 9:
			printf("L%d: fivision by zero\n",
					va_arg(argument, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
