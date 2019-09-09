#include "fractol.h"

void		sect_f(t_env *env, t_complexe *c, t_complexe *z, double x, double y)
{
	if (env->fractal == 0 || env->fractal == 2 || env->fractal == 4)
	{
		*c = new_complexe(*c, x / env->frcl.zoom_x + env->frcl.x1,
										y / env->frcl.zoom_y + env->frcl.y1);
		*z = new_complexe(*z, 0, 0);
	}
	else if (env->fractal == 1)
	{
		*c = new_complexe(*c, env->frcl.x, env->frcl.y);
		*z = new_complexe(*z, x / env->frcl.zoom_x + env->frcl.x1, y / env->frcl.zoom_y + env->frcl.y1);
	}
	else
	{
		*c = new_complexe(*c, x / env->frcl.zoom_x + env->frcl.x1, y / env->frcl.zoom_y + env->frcl.y1);
		*z = new_complexe(*z, 0, 0);
	}
}
void		calcul_fractal(t_env *env)
{
	t_complexe	z;
	t_complexe	c;
	int			i;
	int 		y;
    int         x;

	y = -1;
    x = -1;
	while (++x < env->win_size.x)
	{
		y = -1;
		while (++y < env->win_size.y)
		{
			i = 0;
			sect_f(env, &c, &z, (double)x, (double)y);
			while (z.r * z.r + z.i * z.i < 4 && ++i < env->frcl.iteration_max)
				z = algo_complexe(z, c, env->fractal);
            if (i != env->frcl.iteration_max)
            {
                SDL_SetRenderDrawColor(env->renderer, 0, 0 ,  i * 255, 0);
                SDL_RenderDrawPoint(env->renderer, x, y);
            }
            else
            {
                SDL_SetRenderDrawColor(env->renderer, 0, 0, 0, 0);
				SDL_RenderDrawPoint(env->renderer, x, y);
			}
		}
		SDL_RenderPresent(env->renderer);
	}
}

void    show_fractal()
{
    t_env *env;

    env = g_env(NULL);
	SDL_SetRenderDrawColor(env->renderer, 0, 0 , 0, 0);
	SDL_RenderClear(env->renderer);
	SDL_RenderPresent(env->renderer);
    calcul_fractal(env);
	SDL_RenderPresent(env->renderer);
}