#include "fractol.h"

static int	usage(void)
{
	write(1, "usage fractol [Mandelbrot - Julia -", 35);
	write(1, " Deep_sheep - Appolonius - Feigenbaum]\n", 40);
	return (1);
}

static	int	select_fractal(char *name)
{
	const char *name_tab[5] = {
		"Mandelbrot", "Julia", "Deep_sheep",
		"Appolonius", "Feigenbaum"
	};
	int i;

	i = 0;
	while (i < 5)
	{
		if (!ft_strcmp(name, name_tab[i]))
			return (i);
		i++;
	}
	return (-1);
}

void		define_size(int *x, int *y, int ac, char **av)
{
	*x = DEFAULT_WIN_SIZE_X;
	*y = DEFAULT_WIN_SIZE_Y;
	if (ac >= 3)
		*x = ft_atoi(av[2]);
	if (ac >= 4)
		*y = ft_atoi(av[3]);
}

int			main(int ac, char **av)
{
	int i;
	int x;
	int y;

	i = 1;
	if (ac < 2 || ac > 4)
		return (usage());
	define_size(&x, &y, ac, av);
	if ((i = select_fractal(av[1])) == -1)
		return (usage());
	fractol(i, x, y);
	return (0);
}