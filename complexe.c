#include "fractol.h"

t_complexe	new_complexe(t_complexe new, double r, double i)
{
	new.r = r;
	new.i = i;
	return (new);
}

t_complexe	complexe_mult(t_complexe c1, t_complexe c2)
{
	t_complexe c;

	c.r = (c1.r * c2.r) - (c1.i * c2.i);
	c.i = (c1.r * c2.i) + (c1.i * c2.r);
	return (c);
}

t_complexe	complexe_div(t_complexe c1, t_complexe c2)
{
	t_complexe c;

	c.r = ((c1.r * c2.r) + (c1.i * c2.i)) / ((c2.r * c2.r) + (c2.i * c2.i));
	c.i = ((c1.i * c2.r) - (c1.r * c2.i)) / ((c2.r * c2.r) + (c2.i * c2.i));
	return (c);
}

t_complexe	complexe_plus(t_complexe c1, t_complexe c2)
{
	t_complexe d;

	d.r = c1.r + c2.r;
	d.i = c1.i + c2.i;
	return (d);
}

t_complexe	algo_complexe2(t_complexe z, t_complexe c, char frc)
{
	t_complexe tmp;

	if (frc == 4)
	{
		z = complexe_mult(z, z);
		tmp = complexe_mult(c, c);
		c = complexe_mult(tmp, c);
		z = complexe_plus(z, c);
		tmp = new_complexe(tmp, -1.401155, 0);
		z = complexe_plus(z, tmp);
		return (z);
	}
	else if (frc == 0 || frc == 2 || frc == 1)
	{
		z = complexe_mult(z, z);
		z = complexe_plus(z, c);
		return (z);
	}
	else
	{
		z = complexe_mult(z, z);
		z = complexe_plus(z, c);
	}
	return (z);
}

t_complexe	algo_complexe(t_complexe z, t_complexe c, char frc)
{
	t_complexe tmp;

	if (frc == 2)
	{
		z.i = fabs(z.i);
		z.r = fabs(z.r);
	}
	if (frc == 3)
	{
		z = complexe_mult(z, z);
		tmp = complexe_mult(c, c);
		c = complexe_mult(tmp, c);
		z = complexe_plus(z, c);
		tmp = new_complexe(tmp, -1.401155, 0);
		z = complexe_plus(z, tmp);
		z = complexe_div(c, z);
		return (z);
	}
	else
		return (algo_complexe2(z, c, frc));
	return (z);
}