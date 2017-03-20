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

int		ft_sqrt(int nb)
{
	int a;
	int n;

	a = 0;
	n = 0;
	if (nb == 0 || 0 > nb)
		return (0);
	while ((n < nb) && (n != nb))
	{
		a++;
		n = a * a;
	}
	return (a);
}

void	pix_put_img(t_ptr *ptr, int x, int y, int color)
{
	int		r;
	int		g;
	int		b;

	r = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	b = (color & 0xFF);
	if (y >= 0 && x >= 0 && y < SIZE_Y && x < SIZE_X)
	{
		ptr->img->bts[(y * ptr->img->size_line)
			+ ((ptr->img->bpp / 8) * x) + 2] = r;
		ptr->img->bts[(y * ptr->img->size_line)
			+ ((ptr->img->bpp / 8) * x) + 1] = g;
		ptr->img->bts[(y * ptr->img->size_line)
			+ ((ptr->img->bpp / 8) * x)] = b;
	}
}

void	fl_aff_fract(t_ptr *ptr)
{
	int i;
	int j;
	int color;
	int itera;

	color = 0x00000000;
	j = 0;
	ft_bzero(ptr->img->bts, ptr->img->size_line * SIZE_Y);
	while (j <= SIZE_Y)
	{
		i = 0;
		while (i <= SIZE_X)
		{
			itera = 0;
			itera = fl_nbr_itera(ptr->x1 + (i * ptr->xs),
				ptr->y1 + (j * ptr->ys), ptr);
			if (itera == ptr->iteramax || itera == 0)
				pix_put_img(ptr, i, j, color);
			else
				pix_put_img(ptr, i, j, color + (itera * ptr->color));
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img->ptr_img, 0, 0);
}

void	fl_initialis(t_ptr *ptr)
{
	ptr->v = 0;
	ptr->px = 0;
	ptr->py = 0;
	ptr->x1 = -2;
	ptr->x2 = 2;
	ptr->y1 = -2;
	ptr->y2 = 2;
	ptr->xs = (ptr->x2 - ptr->x1) / SIZE_X;
	ptr->ys = (ptr->y2 - ptr->y1) / SIZE_Y;
	ptr->xc = -1.3;
	ptr->yc = 0;
	ptr->a = 0;
	ptr->iteramax = ITERAMAX;
	ptr->max = 1;
	ptr->color = 0x00001010;
	ptr->i = 0;
}

void	fl_aff_main(char *fractname)
{
	t_ptr	ptr;
	t_img	img;

	fl_initialis(&ptr);
	ptr.fract = fl_set_fract(fractname);
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, SIZE_X, SIZE_Y, fl_name(ptr.fract));
	img.ptr_img = mlx_new_image(ptr.mlx, SIZE_X, SIZE_Y);
	img.bts = mlx_get_data_addr(img.ptr_img, &(img.bpp),
		&(img.size_line), &(img.end));
	ptr.img = &img;
	fl_aff_fract(&ptr);
	mlx_hook(ptr.win, 17, (1L << 17), fl_close, &ptr);
	mlx_hook(ptr.win, 2, 3, fl_key_code, &ptr);
	mlx_hook(ptr.win, 6, 1L << 6, mouse_code1, &ptr);
	mlx_mouse_hook(ptr.win, mouse_code, &ptr);
	mlx_loop(ptr.mlx);
}
