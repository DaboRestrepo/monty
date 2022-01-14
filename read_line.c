#include "monty.h"
/**
 * read_line - Read the giving line.
 * @fd: file descriptor.
 * @stack: list.
 */
void read_line(FILE *fd, stack_t *stack)
{
	char *buffer = NULL, *str = NULL, *push = "push", *arg = NULL;
	size_t len = 0;
	unsigned int line_number = 0;

	while ((getline(&buffer, &len, fd)) != -1)
	{
		line_number++;
		str = strtok(buffer, "\n\t\r ");
		if (str != NULL)
		{
			if ((_strcmp(str, push)) == 0)
			{
				arg = strtok(NULL, "\n\t\r ");
				if (arg == NULL || (is_digit(arg)) == -1)
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					free(buffer);
					exit(EXIT_FAILURE);
				}
				data_type = atoi(arg);
			}
			if (str == NULL || str[0] == '#')
				continue;
			get_funct(str, &stack, line_number);
		}
	}
	free(buffer);
}
