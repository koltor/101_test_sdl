#include "fractol.h"

t_env	*g_env(t_env *env)
{
	static t_env *genv = NULL;

	if (genv == NULL)
		genv = env;
	return (genv);
}

static void	init_fractal(t_fractal *frcl)
{
	frcl->x1 = -2.1;
	frcl->x2 = 0.6;
	frcl->y1 = -1.2;
	frcl->y2 = 1.2;
	frcl->x = 0.285;
	frcl->y = 0.01;
	frcl->iteration_max = 350;
	frcl->color = 16779532;
}

int    init_sdl(int n_fractal, int x, int y)
{
	t_env *env;

	env = g_env(NULL);
	env->win_size.x = x;
	env->win_size.y = y;
	env->frcl.zoom_x = env->win_size.x / 4;
	env->frcl.zoom_y = env->win_size.y / 3;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
	{
		dprintf(1, "Échec de l'initialisation de la SDL (%s)\n", SDL_GetError());
		return (0);
	}
	if(!(env->pWindow = SDL_CreateWindow("fractol",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, x, y, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE)))
	{
		dprintf(1, "Erreur de création de la fenêtre: %s\n", SDL_GetError());
		return (0);
	}
	env->renderer = SDL_CreateRenderer(env->pWindow, -1, SDL_RENDERER_ACCELERATED);
	env->fractal = n_fractal;
	init_fractal(&env->frcl);
	return (1);
}

void sdl_keydown_event(SDL_KeyboardEvent key)
{
	t_env *env;

	env = g_env(NULL);
	dprintf(1, "%d\n", key.keysym.sym);
	if (key.keysym.sym == SDLK_ESCAPE)
		exit(1);
	else if (key.keysym.sym == SDLK_KP_PLUS)
	{
		env->frcl.zoom_x += 15;
		env->frcl.zoom_y += 15;
		show_fractal();
	}
	else if (key.keysym.sym == 1073741910)
	{
		env->frcl.zoom_x -= 15;
		env->frcl.zoom_y -= 15;
		show_fractal();
	}
}


void sdl_windows_event(SDL_WindowEvent window)
{
	t_env *env;

	env = g_env(NULL);
//	dprintf(1, "%d\n", window.event);
	if (window.event == SDL_WINDOWEVENT_CLOSE)
		exit(1);
	else if (window.event == SDL_WINDOWEVENT_RESIZED)
	{
		SDL_GetWindowSize(env->pWindow, &env->win_size.x, &env->win_size.y);
		dprintf(1, "x:%d | y:%d\n", env->win_size.x, env->win_size.y);
		env->frcl.zoom_x = env->win_size.x / 4;
		env->frcl.zoom_y = env->win_size.y / 3;
		show_fractal();
	}
}

void sdl_loop()
{
	SDL_Event ev;
	while (1)
	{
    	while (SDL_WaitEvent(&ev))
    	{
			if (ev.type == SDL_KEYDOWN)
				sdl_keydown_event(ev.key);
			else if (ev.type == SDL_WINDOWEVENT)
				sdl_windows_event(ev.window);
    	}
	}
}

void	quit_sdl(t_env *env)
{
	SDL_DestroyWindow(env->pWindow);
	SDL_Quit();
}

int fractol(int n_fractal, int x, int y)
{
	t_env env;

	g_env(&env);
	if (!init_sdl(n_fractal, x, y))
		return (0);
	show_fractal();
	sdl_loop();
	quit_sdl(&env);
	return (1);
}