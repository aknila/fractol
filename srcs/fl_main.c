/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 16:44:59 by aancel            #+#    #+#             */
/*   Updated: 2017/02/01 16:45:01 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		fl_close(t_ptr *ptr)
{
	mlx_destroy_image(ptr->mlx, ptr->img->ptr_img);
	mlx_destroy_window(ptr->mlx, ptr->win);
	exit(0);
	return (0);
}

int		fl_error(int err)
{
	if (err == 1)
		ft_putendlc(C_ROUGE, "usage : ./fractol fractal_name");
	if (err == 2)
		ft_putendlc(C_ROUGE, "invalid fractal name");
	return (-1);
}

char	*fl_name(int fract)
{
	if (fract == 1)
		return ("Fractal de Julia");
	if (fract == 2)
		return ("Fractal de Mandelbrot");
	if (fract == 3)
		return ("Fractal de Burning Ship");
	return (NULL);
}

int		fl_set_fract(char *name)
{
	if (ft_strcmp(name, "julia") == 0)
		return (1);
	if (ft_strcmp(name, "mandelbrot") == 0)
		return (2);
	if (ft_strcmp(name, "burning_ship") == 0)
		return (3);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		return (fl_error(1));
	else
	{
		if (fl_set_fract(argv[1]) == 0)
			return (fl_error(2));
		fl_aff_main(argv[1]);
	}
	return (0);
}
