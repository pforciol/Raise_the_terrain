#ifndef RTT_H
#define RTT_H

#include <SDL2/SDL.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define ZOOM 25
#define INCL 0.7
#define PAD 100

/**
 * struct SDL_Instance - the SDL2 instance structure
 * 
 * @window: the window pointer
 * @renderer: the renderer pointer
 */

typedef struct SDL_Instance {
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;

/**
 * struct RTT_Point - the Point structure
 * 
 * @x: the x value of the point
 * @y: the y value of the point
 * @z: the z value of the point
 * @m_x: the modified x value of the point
 * @m_y: the modified y value of the point
 */

typedef struct RTT_Point {
	int x;
	int y;
	int z;
	int m_x;
	int m_y;
} RTT_Point;

/**
 * struct RTT_Data - the Data structure
 * 
 * @instance: the SDL2 Instance
 * @coord: the array of Points constituates the grid
 * @width: the Width of the grid
 * @height: the Height of the grid
 */

typedef struct RTT_Data {
	SDL_Instance instance;
	RTT_Point **coord;
	int width;
	int height;
	int px_width;
	int px_height;
	int w_width;
	int w_height;
	int zoom;
	int t_padding;
	int l_padding;
} RTT_Data;

/* DRAW */
void draw_grid(SDL_Instance instance, RTT_Data data);
void stick_to_zero(RTT_Data *data);
void get_zoom(RTT_Data *data);
void pad_grid(RTT_Data *data);

/* EVENTS */
int poll_events(void);

/* INIT */
int init(RTT_Data *data, char *filename);
int check_file(FILE *fp, char *filename);
int init_instance(SDL_Instance *);
int init_data(RTT_Data *data, FILE *fp);
int init_file(RTT_Data *data, FILE *fp);

/* UTILS */
int count_rows(char *line);

/* DEBUG */
void print_data(RTT_Data *data);

#endif
