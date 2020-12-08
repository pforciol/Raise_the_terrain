#include "rtt.h"

int check_file(FILE *fp, char *filename)
{
	struct stat stat;

	lstat(filename, &stat);
	if (fp == NULL || !S_ISREG(stat.st_mode))
	{
		fprintf(stderr, "Error: can't open the file %s\n", filename);
		return (1);
	}
	return (0);
}

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

int init_file(RTT_Data *data, FILE *fp)
{
	char *line = NULL, *tmp = NULL;
	size_t len = 0, read;
	int y = 0, x;	

	while (y < data->height)
	{
		read = getline(&line, &len, fp);
		data->width = count_rows(line);
		data->coord[y] = malloc(sizeof(RTT_Point) * data->width);
		if (data->coord[y] == NULL)
			return (1);
		x = 0;
		while ((tmp = strtok(x == 0 ? line : NULL, " ")))
		{
			data->coord[y][x].x = x;
			data->coord[y][x].y = y;
			data->coord[y][x].m_x = x * ZOOM;
			data->coord[y][x].m_y = y * ZOOM;
			data->coord[y][x].z = atoi(tmp);
			printf("%5d ", data->coord[y][x].z);
			x++;
		}
		printf("\n");
		y++;
	}

	return (0);
}
