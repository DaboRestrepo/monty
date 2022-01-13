#include "monty.h"
/**
 * _add - add the two top elements.
 * @stack: the list.
 * @line_number: giving number.
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	size_t count = 0;
	unsigned int sum = 0;

	while (top != NULL)
	{
		count++;
		top = top->next;
	}
	if (count < 2)
	{
		fprintf(stderr, "L<%d>: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum += top->n;
	_pop(stack, line_number);
	top->n += sum;
}
/**
 * _sub - substract the two top elements.
 * @stack: the list.
 * @line_number: giving number.
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	size_t count = 0;
	unsigned int sub = 0;

	while (top != NULL)
	{
		count++;
		top = top->next;
	}
	if (count < 2)
	{
		fprintf(stderr, "L<%d>: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sub -= top->n;
	_pop(stack, line_number);
	top->n -= sub;
}
/**
 * _nop - Do anything.
 * @stack: the list.
 * @line_number: giving number.
 */
void _nop(__attribute__((unused))stack_t **stack,
__attribute__((unused))unsigned int line_number)
{
	;
}
