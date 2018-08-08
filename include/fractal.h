# ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 900
# define LENGTH 900
# include <stdlib.h>
# include "libft.h"
# include "math.h"
# include "pthread.h"

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

}             t_fractal
