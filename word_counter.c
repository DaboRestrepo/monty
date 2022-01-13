#include "monty.h"
/**
 * word_counter - counts each letter from the string
 *@buffer: string
 *@delim: Delimeters
 * Return: the result
 */

int word_counter(char *buffer, char *delim)
{
	unsigned int wc = 0;
	int status = 0;

	while (*buffer)
	{
		if (*buffer == delim[0] || *buffer == delim[1] ||
		*buffer == delim[2] || *buffer == delim[3])
		{
			status = 0;
		}
		else if (status == 0)
		{
			status = 1;
			++wc;
		}
		++buffer;
	}
	return (wc);
}
