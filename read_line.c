#include "monty.h"
/**
 * read_line - Read the giving line.
 * @fd: file descriptor.
 * @stack: list.
 */
void read_line(FILE *fd, stack_t *stack)
{
	char *buffer = NULL, **str = NULL;
	size_t len = 0;
	unsigned int line_number = 0;

	while ((getline(&buffer, &len, fd)) != -1)
	{
		line_number++;
		str = token(buffer, "\n\t\r ");
		if (str[1])
		{
			if (is_digit(str[1]) == -1)
			{
				fprintf(stderr, "L<%d>: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			data_type = atoi(str[1]);
		}
		if (str != NULL)
			get_funct(str, &stack, line_number);
	}
}
