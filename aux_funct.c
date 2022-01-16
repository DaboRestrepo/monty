#include "monty.h"
/**
 * _strlen - Function that returns the lenght of a string.
 * @c: String
 * Return: the result
 */

int _strlen(char *c)
{
	int count = 0;

	while (c[count])
		count++;
	return (count);
}

/**
 * _strcmp - Function to compares two strings.
 * @s1: String one
 * @s2: String two
 * Return: the subtraction of the strings.
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * free_grid - Frees the space on memory for the grid
 * @grid: grid
 */

void free_grid(char **grid)
{
	int i = 0;

	for (i = 0; grid[i]; i++)
		free(grid[i]);
	free(grid);
}
/**
 * is_digit - Check if the string is a digit.
 * @str: string.
 * Return: -1 if not, 1 if it is.
 */
int is_digit(char *str)
{
	int pos = 0;

	if (str[0] == '-')
		pos++;
	while (str[pos])
	{
		if (!(str[pos] >= 48 && str[pos] <= 57))
		{
			return (-1);
		}
		pos++;
	}
	return (1);
}
