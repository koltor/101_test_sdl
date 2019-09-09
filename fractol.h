/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/04 16:15:39 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/06 11:33:15 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include <SDL2/SDL.h>
#include "libft.h"

#define UINT unsigned int

#define DEFAULT_WIN_SIZE_X 700;
#define DEFAULT_WIN_SIZE_Y 700;

typedef struct			s_fractal
{
	double				x1;
	double				x2;
	double				y1;
	double				y2;
	double				x;
	double				y;
	unsigned int		iteration_max;
	double				zoom_x;
	double				zoom_y;
	unsigned int		color;
}						t_fractal;

typedef struct			s_complexe
{
	double				r;
	double				i;
}						t_complexe;

typedef struct			s_win_size
{
	int					x;
	int					y;
}						t_win_size;

typedef struct			s_env
{
    SDL_Renderer		*renderer;
    SDL_Window			*pWindow;
	struct s_win_size	win_size;
    char				fractal;
	struct s_fractal	frcl;
}               		t_env;

t_complexe	algo_complexe(t_complexe z, t_complexe c, char frc);
int			fractol(int n_fractal, int x, int y);
void		show_fractal();

t_complexe	new_complexe(t_complexe new, double r, double i);
t_env	*g_env(t_env *env);
#endif
