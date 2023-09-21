#define _GNU_SOURCE
#include "monty.h"

/**
 * open_file - opens a file to the user
 * @fileName: the filename in form of a stirng
 */
void open_file(char *fileName)
{
	int check;
	FILE *file_descriptor;

	if (fileName == NULL)
		err(2, fileName);
	check = access(fileName, R_OK);
	if (check == -1)
		err(2, fileName);
	file_descriptor = fopen(fileName, "r");
	if (file_descriptor == NULL)
		err(2, fileName);
	readfile(file_descriptor);
	fclose(file_descriptor);
}

/**
 * readfile - reads contents line by line
 * @file_d: a pointer to the fd of an open file
 */
void readfile(FILE *file_d)
{
	int line;
	int fmt;
	char *ptr;
	size_t n;

	ptr = NULL;
	n = 0;
	fmt = 0;

	if (file_d == NULL)
		err(2, "file_name");
	for (line = 1; getline(&ptr, &n, file_d) != EOF; line++)
	{
		fmt = tokenize_line(ptr, line, fmt);
	}
	free(ptr);
}

/**
 * tokenize_line - breaks each line into tokens to determing
 * which function to call
 * @lineptr: represents a line in a file
 * @line_num: the line numb for opcode
 * @format: the format specifier for the nodes in a stack
 *
 * Return: 0 if stack, 1 if queue
 */
int tokenize_line(char *lineptr, int line_num, int format)
{
	const char *delimeter;
	char *op;
	char *val;

	if (lineptr == NULL)
		err(4);
	delimeter = "\n ";
	op = strtok(lineptr, delimeter);

	if (op == NULL)
		return (format);
	val = strtok(NULL, delimeter);

	if (strcmp(op, "queue") == 0)
		return (1);
	else if (strcmp(op, "stack") == 0)
		return (0);
	f_func(op, val, line_num, format);
	return (format);
}

/**
 * f_func - finds the functions to run the opcode instruction
 * @opcode: the operaction code
 * @val: value for the operation
 * @line: line number for the opcode
 * @format: format specifier
 */
void f_func(char *opcode, char *val, int line, int format)
{
	int n;
	int flag;

	instruction_t function_list[] = {
		{"push", add_stack},
		{"pall", print_stack},
		{"pint", print_top_stack},
		{"pop", pop_top_stack},
		{"nop", nop},
		{"add", add_nodes},
		{"swap", swap},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;
	/* it goes through the list to find the right function */
	for (flag = 1, n = 0; function_list[n].opcode != NULL; n++)
	{
		if (strcmp(opcode, function_list[n].opcode) == 0)
		{
			calls_fn(function_list[n].f, opcode, val, line, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, line, opcode);
}

/**
 * calls_fn - call the required function to the command line
 * @f: pointer to function
 * @opcode: string representing the opcode
 * @value: represents numeric value
 * @line: line number for the instruction
 * @format: format specifier
 */
void calls_fn(op_fun f, char *opcode, char *value, int line, int format)
{
	stack_t *node;
	int flag;
	int x;

	flag = 1;
	if (strcmp(opcode, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			flag = -1;
		}
		if (value == NULL)
			err(5, line);
		for (x = 0; value[x] != '\0'; x++)
		{
			if (isdigit(value[x]) == 0)
				err(5, line);
		}
		node = create_node(atoi(value) * flag);
		if (format == 0)
			f(&node, line);
		if (format == 1)
			add_to_queue(&node, line);
	}
	else
		f(&head, line);
}
