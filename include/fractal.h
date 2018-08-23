#ifndef FRACTAL_H
#define FRACTAL_H

#include "libft.h"
#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include "../minilibx/mlx.h"
#define WIDTH 800
#define HEIGHT 800

typedef struct		s_fractal
{
	void *mlx;
	void *win;
	void *img;
	char *img_ptr;

	int	f_type;
	int iter_max;
	int iter;
	int bpp;
	int sl;
	int en;
	int pointer_x;
	int pointer_y;

	float x_move;
	float y_move;
	float julia_shape;

	int y_max;
	int color;
	int c_coef;
	int c_coeff;
	int n;

	float zoom;
	double z;
	double c;

	double c_a;
	double c_b;

	int x;
	int y;
}					t_fractal;

// mandelbrot.c
void	init_mandelbrot		(t_fractal *i);
void	calc_mandelbrot		(t_fractal *i);
void	*execute_mandelbrot	(void *ft);

void	init_julia			(t_fractal *i);
void	calc_julia			(t_fractal *i);
void	*execute_julia		(void *ft);

void	init_burningship	(t_fractal *i);
void	calc_burningship	(t_fractal *i);
void	*execute_burningship(void *ft);

void	init_hydra			(t_fractal *i);
void	calc_hydra			(t_fractal *i);
void	*execute_hydra		(void *ft);

// utility.c
void	pixel_to_image		(t_fractal *i, int x, int y, int color);
void	multipthread		(t_fractal *i);

// key.c
int		key_hook			(int key, t_fractal *i);
int		pointer_hook		(int a, int b, t_fractal *i);
int		mouse_hook			(int key, int x, int y, t_fractal *i);

#endif
