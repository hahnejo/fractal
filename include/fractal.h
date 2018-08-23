#ifndef FRACTAL_H
#define FRACTAL_H

#define WIDTH 900
#define LENGTH 900
#include <stdlib.h>
#include "libft.h"
#include "math.h"
#include "pthread.h"
#include "../minilibx/mlx.h"

#include <stdio.h>

typedef struct s_fractal
{
	void *mlx;
	void *win;
	void *image;
	void *image_ptr;

	double c_real;
	double c_image;
	double z_real;
	double z_image;
	double x;
	double y;
	double x1;
	double x2;
	double y1;
	double y2;
	double zoom;
	double temp;
	double y_max;

	int f_type;
	int endian;
	int bpp;
	int s_l;
	int iter;
	int iter_max;
	int color;
	int mouse_julia;


}             t_fractal;

void mandelbrot_setting(t_fractal *i);
void *mandelbrot_process(void *tab);
void mandelbrot_pthread(t_fractal *i);

int key_operate(int key, t_fractal *i);
int key_mouse(int key, t_fractal *i);
int deal_key(int key, t_fractal *i);
void zoom_in(int x, int y, t_fractal *i);
void zoom_out(t_fractal *i);


int exit_success(void);
int exit_failure(void);
void display(t_fractal *i);
void	put_image(t_fractal *i, int x, int y, int color);
void set_fractal(t_fractal *i);


#endif
