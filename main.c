#include "rtt.h"

void draw_stuff(SDL_Instance instance) {
	SDL_SetRenderDrawColor(instance.renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(instance.renderer, 320, 200, 300, 240);
}

int poll_events(void) {
	SDL_Event event;
	SDL_KeyboardEvent key;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			return (1);
		case SDL_KEYDOWN:
			key = event.key;
			if (key.keysym.scancode == 0x29)
				return (1);
			break;
		}
	}
	return (0);
}

int init(RTT_Data *data, char *filename)
{
	FILE *fp;

	fp = fopen(filename, "r");

	if (check_file(fp, filename) != 0)
		return (1);

	if (init_data(data, fp) != 0)
		return (1);
	fseek(fp, 0, SEEK_SET);

	if (init_file(data, fp) != 0)
		return (1);

	return (0);	
}

int main(int ac, char **av)
{
	RTT_Data data;

	if (ac != 2) {
		fprintf(stderr, "Usage: ./terrain file\n");
		return (1);
	}

	if (init(&data, av[1]) != 0)
		return (1);

	while ("Holberton is Cool!") {
		SDL_SetRenderDrawColor(data.instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(data.instance.renderer);
		if (poll_events() == 1)
			break;
		draw_stuff(data.instance);
		SDL_RenderPresent(data.instance.renderer);
	}
	SDL_DestroyRenderer(data.instance.renderer);
	SDL_DestroyWindow(data.instance.window);
	SDL_Quit();
	return (0);
}
