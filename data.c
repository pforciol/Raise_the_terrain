#include "rtt.h"

int init_data(RTT_Data *data, FILE *fp)
{
	char *line = NULL;
	int line_count = 0;
	size_t len = 0, read;

	if (init_instance(&data->instance) != 0)
		return (1);

	while ((read = getline(&line, &len, fp) != -1))
		line_count++;
	free(line);
	data->coord = malloc(sizeof(RTT_Point *) * line_count);
	if (data->coord == NULL)
		return (1);

	data->width = 0;
	data->height = line_count;
	return (0);
}
