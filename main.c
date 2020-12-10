#include "rtt.h"

/**
 * main - entry point of Raise the Terrain
 * 
 * @ac: the count of arguments given to the program
 * @av: the array of arguments (strings) given to the program
 * 
 * Return: 0 on success, 1 if an error has occured
 */

int main(int ac, char **av)
{
	RTT_Data data;

	if (ac != 2) {
		fprintf(stderr, "Usage: ./terrain file\n");
		return (1);
	}

	if (init(&data, av[1]) != 0)
		return (1);

	get_zoom(&data);
	stick_to_zero(&data);
	pad_grid(&data);
	print_data(&data);

	while ("Holberton is Cool!")
	{
		SDL_SetRenderDrawColor(data.instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(data.instance.renderer);
		draw_grid(data.instance, data);
		SDL_RenderPresent(data.instance.renderer);
		if (data.z_mul <= 0.02 * ZOOM * 1.2)
			data.z_mul += (0.01 / 5);
		if (poll_events() == 1)
			break;
		SDL_RenderPresent(data.instance.renderer);
	}
	SDL_DestroyRenderer(data.instance.renderer);
	SDL_DestroyWindow(data.instance.window);
	SDL_Quit();
	return (0);
}
