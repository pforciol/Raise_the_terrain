#include "rtt.h"

void print_data(RTT_Data *data)
{
	int y = 0, x;

	printf("Zoom: %d\n", data->zoom);

	printf("Instance window address: %p\n", (void *)data->instance.window);
	printf("Instance renderer address: %p\n\n", (void *)data->instance.renderer);

	printf("Window Informations:\n\t- Width: %d\n\t- Height : %d\n\n", data->w_width, data->w_height);

	printf("Grid Informations:\n\t- Width: %d points\n\t- Height : %d points\n", data->width, data->height);
	printf("\t- Width: %d px\n\t- Height : %d px\n\n", data->px_width, data->px_height);
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
