#include "monty.h"
/**
 * get_funct - choose the right function.
 * @buffer: string.
 * @stack: linked list.
 * @line_number: the number of the line.
 */
void get_funct(char **buffer, stack_t **stack, unsigned int line_number)
{
	int i = 0;

	while (name[i].opcode != NULL)
	{
		if ((_strcmp(name[i].opcode, buffer[0]) == 0))
		{
			name[i].f(stack, line_number);
		}
		i++;
	}
	if (name[i].opcode == NULL)
	{
		fprintf(stderr, "L<%d>: unknown instruction <%s>\n", line_number, buffer[0]);
		exit(EXIT_FAILURE);
	}
	free_grid(buffer);
}
