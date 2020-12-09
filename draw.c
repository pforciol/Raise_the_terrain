#include "rtt.h"

void convert_iso(RTT_Data *data)
{
	int x, y = 0;

	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			data->coord[y][x].x *= ZOOM;
			data->coord[y][x].y *= ZOOM;
			data->coord[y][x].m_x = data->coord[y][x].x * 0.7 - data->coord[y][x].y * 0.7 + data->w_width / 2;
			data->coord[y][x].m_y = (1 - 0.7) * data->coord[y][x].x + (1 - 0.7) * data->coord[y][x].y - (data->coord[y][x].z / 2) + data->w_height / 3;
			x++;
		}
		y++;
	}
}

void draw_grid(SDL_Instance instance, RTT_Data data)
{
	int x, y = 0;
	
	SDL_SetRenderDrawColor(instance.renderer, 255, 255, 255, 255);

	while (y < data.height - 1)
	{
		x = 0;

		while (x < data.width - 1)
		{
			SDL_RenderDrawLine(instance.renderer, data.coord[y][x].m_x, data.coord[y][x].m_y, data.coord[y + 1][x].m_x, data.coord[y + 1][x].m_y);
			SDL_RenderDrawLine(instance.renderer, data.coord[y][x].m_x, data.coord[y][x].m_y, data.coord[y][x + 1].m_x, data.coord[y][x + 1].m_y);
			x++;
		}
		y++;
	}
}
