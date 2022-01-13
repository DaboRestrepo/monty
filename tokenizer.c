#include "monty.h"
/**
 * token - tokenize the string.
 * @buffer: string.
 * @delim: delimitator.
 * Return: a tokenizer string.
 */
char **token(char *buffer, char *delim)
{
	unsigned int wc = 0, pos = 0;
	char **arg = NULL;

	wc = word_counter(buffer, delim);
	arg = malloc(sizeof(char *) * (wc + 1));
	if (arg == NULL)
	{
		free(buffer);
		free(arg);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	arg[pos] = _strdup(strtok(buffer, delim));
	pos++;
	while (pos < wc)
	{
		arg[pos] = _strdup(strtok(NULL, delim));
		pos++;
	}
	arg[pos] = NULL;
	free(buffer);
	return (arg);
}
