#ifndef RTT_H
#define RTT_H

#include <SDL2/SDL.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define ZOOM 50

typedef struct SDL_Instance {
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;

typedef struct RTT_Point {
	int x;
	int y;
	int z;
	int m_x;
	int m_y;
} RTT_Point;

typedef struct RTT_Data {
	SDL_Instance instance;
	RTT_Point **coord;
	int width;
	int height;
} RTT_Data;

int init_instance(SDL_Instance *);
int check_file(FILE *fp, char *filename);
int init_data(RTT_Data *data, FILE *fp);
int init_file(RTT_Data *data, FILE *fp);

#endif
