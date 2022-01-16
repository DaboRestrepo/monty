#include "monty.h"
/**
 * _add - add the two top elements.
 * @stack: the list.
 * @line_number: giving number.
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	unsigned int sum = 0;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	sum = (*stack)->n + tmp->n;
	free(*stack);
	*stack = tmp;
	(*stack)->n = sum;
}
/**
 * _sub - substract the two top elements.
 * @stack: the list.
 * @line_number: giving number.
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL, *head = *stack;
	int count = 0;
	unsigned int sub = 0;

	while (head)
	{
		head = head->next;
		count++;
	}
	if ((*stack)->next == NULL || count <= 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	sub = (*stack)->n - tmp->n;
	free(*stack);
	*stack = tmp;
	(*stack)->n = sub;
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

/**
 * free_dlist - free the list variable.
 * @stack: the list.
 */
void free_dlist(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack->next;
		free(tmp);
		stack = tmp;
	}
}
