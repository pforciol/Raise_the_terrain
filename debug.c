#include "rtt.h"

void print_data(RTT_Data *data)
{
	int y = 0, x;

	printf("Instance window address: %p\n", (void *)data->instance.window);
	printf("Instance renderer address: %p\n\n", (void *)data->instance.renderer);

	printf("Window Informations:\n\t- Width: %d\n\t- Height : %d\n\n", data->w_width, data->w_height);

	printf("Grid Informations:\n\t- Width: %d\n\t- Height : %d\n\n", data->width, data->height);
	while (y < data->height)
	{
		x = 0;
		while (x < 8 * data->width)
		{
			x++;
			printf("-");
		}
		printf("-\n");
		x = 0;
		while (x < data->width)
		{
			printf("| %4d  ", data->coord[y][x].z);
			x++;
		}
		printf("|\n");
		y++;
	}
	x = 0;
	while (x < 8 * data->width)
	{
		x++;
		printf("-");
	}
	printf("-\n");
}
