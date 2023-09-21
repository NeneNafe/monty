#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef void (*op_fun)(stack_t **, unsigned int);

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;

/* Prototypes  */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
int main(int argc, char **argv);
void err(int error_code, ...);
void more_err(int error_code, ...);
void string_err(int error_code, ...);
void rotr(stack_t **, unsigned int);

stack_t *create_node(int n);
void free_nodes(void);
void open_file(char *filename);
void readfile(FILE *file_d);

int tokenize_line(char *lineptr, int line_num, int format);
void f_func(char *opcode, char *val, int line, int format);
void calls_fn(op_fun f, char *opcode, char *value, int line, int format);

void add_stack(stack_t **new_node, __attribute__((unused))unsigned int line);
void print_top_stack(stack_t **stack, unsigned int line_number);
void print_stack(stack_t **stack, unsigned int line_number);
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int line);
void pop_top_stack(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add_nodes(stack_t **stack, unsigned int line_number);

#endif /* MONTHY_H */
