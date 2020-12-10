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

	//stick_to_zero(&data);
	get_zoom(&data);
	stick_to_zero(&data);
	print_data(&data);
	pad_grid(&data);

	while ("Holberton is Cool!")
	{
		SDL_SetRenderDrawColor(data.instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(data.instance.renderer);
		draw_grid(data.instance, data);
		SDL_RenderPresent(data.instance.renderer);
		if (poll_events() == 1)
			break;
		SDL_RenderPresent(data.instance.renderer);
	}
	SDL_DestroyRenderer(data.instance.renderer);
	SDL_DestroyWindow(data.instance.window);
	SDL_Quit();
	return (0);
}
