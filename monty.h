#ifndef MONTY_H
#define MONTY_H
#define  _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

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

/* Global variable */
int data_type;

/* Stack and math functions */
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);

/* Auxiliars functions */
int _strlen(char *c);
int _strcmp(char *s1, char *s2);
void free_grid(char **grid);
char **token(char *buffer, char *delim);
int word_counter(char *buffer, char *delim);
char *_strdup(char *str);

/* Check functions */
void get_funct(char **str, stack_t **stack, unsigned int line_number);
void read_line(FILE *fd, stack_t *stack);
int is_digit(char *str);
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

static const instruction_t name[] = {
	{"push", _push},
	{"pall", _pall},
	{"pint", _pint},
	{"pop", _pop},
	{"add", _add},
	{"nop", _nop},
	{"swap", _swap},
	{NULL, NULL},
};

#endif
