#include "fractal.h"

int key_operate(int key, t_fractal *i)
{
	key == 53 ? exit_success() : 0;
}

int key_mouse(int key, t_fractal *i)
{
}

int deal_key(int key, t_fractal *i)
{
	key == 53 ? key_operate(key, i) : 0;

	key == mouse key ? key_mouse(key, i) : 0;

}
