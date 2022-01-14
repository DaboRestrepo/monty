#include "monty.h"
/**
 * main - Read the monty file.
 * @argc: count of the arguments.
 * @argv: list of arguments.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *fd = NULL;

	if (argc <= 1 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read_line(fd, stack);
	fclose(fd);
	return (0);
}
