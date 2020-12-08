#include "rtt.h"

void convert_iso(RTT_Data *data)
{
	int x, y = 0;

	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			//data->coord[y][x].m_x = data->coord[y][x].m_x * 0.7 - data->coord[y][x].m_y * 0.7 + data->w_width / 2;
			//data->coord[y][x].m_y = (1 - 0.7) * data->coord[y][x].m_x + (1 - 0.7) * data->coord[y][x].m_y;
			x++;
		}
		y++;
	}
}

void draw_grid(SDL_Instance instance, RTT_Data data)
{
	int x, y = 0;
	
	SDL_SetRenderDrawColor(instance.renderer, 255, 255, 255, 255);

	while (y < data.height)
	{
		x = 0;
		while (x < data.width)
		{
			SDL_RenderDrawPoint(instance.renderer, data.coord[y][x].m_x * 0.7 - data.coord[y][x].m_y * 0.7 + data.w_width / 2, (1 - 0.7) * data.coord[y][x].m_x + (1 - 0.7) * data.coord[y][x].m_y);
			x++;
		}
		y++;
	}
}
