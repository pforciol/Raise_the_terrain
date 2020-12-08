#include "rtt.h"

/**
 * count_rows - returns the number of rows in a line
 * 
 * @line: the line to count rows of
 * 
 * Return: the number of rows in the line line
 */

int count_rows(char *line)
{
	int i = 0, count = 1;

	if (!line)
		return (-1);
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
			count++;
		i++;
	}
	return (count);
}
