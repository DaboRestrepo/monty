#include "monty.h"
/**
 * get_funct - choose the right function.
 * @buffer: string.
 * @stack: linked list.
 * @line_number: the number of the line.
 */
void get_funct(char *buffer, stack_t **stack, unsigned int line_number)
{
	int i = 0;

	for (; name[i].opcode != NULL; i++)
	{
		if ((_strcmp(name[i].opcode, buffer) == 0))
		{
			name[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, buffer);
	free(buffer);
	free_dlist(*stack);
	exit(EXIT_FAILURE);
}
