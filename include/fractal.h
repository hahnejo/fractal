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
	int f_type;
	int endian;
	int bpp;
	int s_l;
	int iter;
	int color;
	int mouse_julia;

}             t_fractal;

void mandelbrot_setting(t_fractal *i);
void mandelbrot(t_fractal *i);

int key_operate(int key, t_fractal *i);
int key_mouse(int key, t_fractal *i);
int deal_key(int key, t_fractal *i);

int exit_success(void);
int exit_failure(void);
