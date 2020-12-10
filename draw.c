#include "rtt.h"

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
