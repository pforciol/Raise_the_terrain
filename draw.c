#include "rtt.h"

void stick_to_zero(RTT_Data *data)
{
	int x, y = 0;
	int add_top, add_left;

	add_top = data->coord[0][0].m_y < 0 ? -data->coord[0][0].m_y : 0;
	add_left = data->coord[data->height - 1][0].m_x < 0
		? -data->coord[data->height - 1][0].m_x : 0;

	if (add_top != 0 || add_left != 0)
	{
		while (y < data->height)
		{
			x = 0;
			while (x < data->width)
			{
				data->coord[y][x].m_x += add_left;
				data->coord[y][x].m_y += add_top;
				x++;
			}
			y++;
		}
	}

	data->px_width = data->coord[0][data->width - 1].m_x - data->coord[data->height - 1][0].m_x;
	data->px_height = data->coord[data->height - 1][data->width - 1].m_y - data->coord[0][0].m_y;
}

void get_zoom(RTT_Data *data)
{
	int x, y;
	
	while (data->coord[0][data->width - 1].m_x + (data->zoom + data->width + PAD) < data->w_width
		&& data->coord[data->height - 1][data->width - 1].m_y + (data->zoom + data->height + PAD) < data->w_height)
	{
		y = 0;
		while (y < data->height)
		{
			x = 0;
			while (x < data->width)
			{
						

				data->coord[y][x].m_x =
					data->coord[y][x].x * data->zoom * INCL
					- data->coord[y][x].y * data->zoom * INCL;
				data->coord[y][x].m_y =
					data->coord[y][x].x * data->zoom * (1 - INCL)
					+ data->coord[y][x].y * data->zoom * (1 - INCL)
					- data->coord[y][x].z / 2;
				x++;
			}
			y++;
		}
		data->zoom++;
	}
}

void pad_grid(RTT_Data *data)
{
	int x, y = 0;

	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			data->coord[y][x].m_x += (data->w_width - data->px_width) / 2 + PAD / 2;
			data->coord[y][x].m_y += (data->w_height - data->px_height) / 2 + PAD / 2 ;
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
			SDL_RenderDrawPoint(instance.renderer, data.coord[y][x].m_x, data.coord[y][x].m_y);
			x++;
		}
		SDL_RenderDrawLine(instance.renderer, data.coord[y][x].m_x, data.coord[y][x].m_y, data.coord[y + 1][x].m_x, data.coord[y + 1][x].m_y);
		SDL_RenderDrawPoint(instance.renderer, data.coord[y][x].m_x, data.coord[y][x].m_y);
		y++;
	}
	x = 0;
	while (x < data.width - 1)
	{
		SDL_RenderDrawLine(instance.renderer, data.coord[y][x].m_x, data.coord[y][x].m_y, data.coord[y][x + 1].m_x, data.coord[y][x + 1].m_y);
		x++;
	}
	SDL_RenderDrawPoint(instance.renderer, data.coord[y][x].m_x, data.coord[y][x].m_y);
}
