#include "monty.h"
/**
 * _pall - print the monty file
 * @stack: the list.
 * @line_number: giving number.
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	(void)line_number;

	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->prev;
	}
}

/**
 * _push - push a line in the monty file
 * @stack: the list.
 * @line_number: giving number.
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *top = malloc(sizeof(stack_t));
	(void)line_number;

	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(top);
		exit(EXIT_FAILURE);
	}
	top->n = data_type;
	top->next = NULL;
	if (*stack == NULL)
	{
		top->prev = NULL;
		*stack = top;
	}
	else
	{
		(*stack)->next = top;
		top->prev = *stack;
		*stack = top;
	}
}

/**
 * _pint - Print the top value.
 * @stack: the list.
 * @line_number: giving number.
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
}

/**
 * _pop - Delete the top element.
 * @stack: the list.
 * @line_number: giving number.
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

/**
 * _swap - Swap the two top elements.
 * @stack: the list.
 * @line_number: giving number.
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	int i;

	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	i = head->n;
	head->n = head->next->n;
	head->next->n = i;
}
