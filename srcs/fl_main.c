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

int		fl_nbr_itera(long double xc, long double yc, t_ptr *ptr)
{
	long double x;
	long double y;
	int itera;
	long double tmp;

	tmp = 0;
	if (ptr->fract == 1)
	{
		x = xc;
		y = yc;
		xc = ptr->xc;
		yc = ptr->yc;
	}
	if (ptr->fract == 2)
	{
		x = 0;
		y = 0;
	}
	if (ptr->fract == 3)
	{
		// xc = ABS(xc);
		// yc = ABS(yc);
		// x = 0;
		// y = 0;
		x = ABS(xc);
		y = ABS(yc);
		xc = ptr->xc;
		yc = ptr->yc;
	}
	itera = 0;
	ptr->fract += 0;
	// printf("x1 = %LF \n", x);
	// printf("y1 = %LF \n", y);
	while (((x * x) + (y * y)) < 4 && itera < ptr->iteramax)
	{
		// ft_putnbrl(itera);
		// printf("x2 = %LF \n", x = (x * x) - (y * y) + xc);
		// printf("y2 = %LF \n", y = (2 * y) + yc);
		tmp = x;
		x = (x * x) - (y * y) + xc;
		y = (2 * y * tmp) + yc;
		if (ptr->fract == 3)
		{
			x = ABS(x);
			y = ABS(y);
		}
		itera += 1;
	}
	return (itera);
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
		ptr->img->bts[(y * ptr->img->size_line) + ((ptr->img->bpp / 8) * x) + 2] = r;
		ptr->img->bts[(y * ptr->img->size_line) + ((ptr->img->bpp / 8) * x) + 1] = g;
		ptr->img->bts[(y * ptr->img->size_line) + ((ptr->img->bpp / 8) * x)] = b;
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
			itera = fl_nbr_itera(ptr->x1 + (i * ptr->xs), ptr->y1 + (j * ptr->ys), ptr);
			if (itera == ptr->iteramax)
				pix_put_img(ptr, i, j, color);
				// mlx_pixel_put(ptr->mlx, ptr->img->ptr_img, i, j, color);
			else
				pix_put_img(ptr, i, j, color + (itera * 0x00001010));
				// mlx_pixel_put(ptr->mlx, ptr->img->ptr_img, i, j, color + (itera * 0x00001010));
			// printf("x = %d, y = %d \n", i, j);
			i++;
		}
		j++;
	}
	// ft_putendl("\n\n");
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img->ptr_img, 0, 0);
	if (ptr->i == 1)
	{
		mlx_string_put(ptr->mlx, ptr->win, 5, 0, 0x00ff9933, ft_strjoin("x", ft_itoa(ptr->a)));
		mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 2, 0, 0x00ff9933, ft_strjoin("y = ", ft_putprec(ptr->y1)));
		mlx_string_put(ptr->mlx, ptr->win, SIZE_X / 2, SIZE_Y - 25, 0x00ff9933, ft_strjoin("y = ", ft_putprec(ptr->y2)));
		mlx_string_put(ptr->mlx, ptr->win, 0, SIZE_Y / 2, 0x00ff9933, ft_strjoin("x = ", ft_putprec(ptr->x1)));
		mlx_string_put(ptr->mlx, ptr->win, SIZE_X - (ft_strlen(ft_putprec(ptr->x2)) * 15), SIZE_Y / 2, 0x00ff9933, ft_strjoin("x = ", ft_putprec(ptr->x2)));
	}
}

char *ft_putprec(long double nbr)
{
	char *str;
	int i;

	i = 0;
	if (nbr < 0)
	{
		nbr = -1 * nbr;
		str = ft_strjoin("-", ft_strjoin(ft_itoa(nbr), ","));
	}
	else
		str = ft_strjoin(ft_itoa(nbr), ",");
	nbr = nbr - ABS(atoi(str)) + 1;
	nbr = nbr * 1000000;
	str = ft_strjoin(str, ft_itoa(nbr));
	while (str[i])
	{
		if (str[i] == ',')
			str[i + 1] = str[i + 1] - 1;
		i++;
	}
	return (str);
}

int		fl_zoom(int button, float x, float y, t_ptr *ptr)
{
	// static int a = 0;
	// static int b = 1;

	if (button == 3)
	{
		ptr->x1 = x - (ptr->x1 + 15 * ptr->xs);
		ptr->x2 = x + (ptr->x2 - 15 * ptr->xs);
		ptr->y1 = y - (ptr->y1 + 15 * ptr->ys);
		ptr->y2 = y + (ptr->y2 - 15 * ptr->ys);
		ptr->xs = (ptr->x2 - ptr->x1) / SIZE_X;
		ptr->ys = (ptr->y2 - ptr->y1) / SIZE_Y;
		ptr->x1 = x - (ptr->x1 + 15 * ptr->xs);
		ptr->x2 = x + (ptr->x2 - 15 * ptr->xs);
		ptr->y1 = y - (ptr->y1 + 15 * ptr->ys);
		ptr->y2 = y + (ptr->y2 - 15 * ptr->ys);
		ptr->xs = (ptr->x2 - ptr->x1) / SIZE_X;
		ptr->ys = (ptr->y2 - ptr->y1) / SIZE_Y;
		ptr->a++;
		// b--;
		// if (a % 10 == 0)
		// 	ptr->iteramax *= 2;
	}
	if (button == 4)
	{
		ptr->x1 = x + (ptr->x1 - 15 * ptr->xs);
		ptr->x2 = x - (ptr->x2 + 15 * ptr->xs);
		ptr->y1 = y + (ptr->y1 - 15 * ptr->ys);
		ptr->y2 = y - (ptr->y2 + 15 * ptr->ys);
		ptr->xs = (ptr->x2 - ptr->x1) / SIZE_X;
		ptr->ys = (ptr->y2 - ptr->y1) / SIZE_Y;
		ptr->x1 = x + (ptr->x1 - 15 * ptr->xs);
		ptr->x2 = x - (ptr->x2 + 15 * ptr->xs);
		ptr->y1 = y + (ptr->y1 - 15 * ptr->ys);
		ptr->y2 = y - (ptr->y2 + 15 * ptr->ys);
		ptr->xs = (ptr->x2 - ptr->x1) / SIZE_X;
		ptr->ys = (ptr->y2 - ptr->y1) / SIZE_Y;
		// b++;
		ptr->a--;
		// if (b % 10 == 0)
		// 	ptr->iteramax /= 2;
	}
	return (0);
}

// void	fl_aff_fract(t_ptr *ptr)
// {
// 	float x1 = -2.1;
// 	// float x2 = 0.6;
// 	float y1 = -1.2;
// 	// float y2 = 1.2;
// 	// long double zoom_x;
// 	double zoom;
// 	int i;
// 	int j;
// 	int itera;
// 	int color;

// 	fract += 0;
// 	color = 0x00000000;
// 	zoom = 200;
// 	// zoom_y = ptr->size_y / (y2 - y1);
// 	i = 0;
// 	while (i < ptr->size_x)
// 	{
// 		j = 0;
// 		while (j < ptr->size_y)
// 		{
// 			itera = fl_nbr_itera(i / zoom + x1, j / zoom + y1, ptr);
// 			// if (itera == 20)
// 				// mlx_pixel_put(ptr->mlx, ptr->win, i, j, color);
// 			// else
// 			mlx_pixel_put(ptr->mlx, ptr->win, i, j, color + (itera * 0x00001010));
// 			j++;
// 		}
// 		i++;
// 	}
// }

int		fl_close(t_ptr *ptr)
{
	mlx_destroy_image(ptr->mlx, ptr->img->ptr_img);
	mlx_destroy_window(ptr->mlx, ptr->win);
	exit(0);
	return (0);
}

int		fl_key_code(int kc, t_ptr *ptr)
{
	if (kc == 53)
		fl_close(ptr);
	if (kc == 36)
		fl_zoom(3, 0, 0, ptr);
	if (kc == 258)
		fl_zoom(4, 0, 0, ptr);
	if (kc == 34)
		ptr->i = (ptr->i == 1 ? 0 : 1);
	if (kc == 9)
		ptr->v = (ptr->v == 0 ? 1 : 0);
	if (kc == 69)
	{
		if (ptr->iteramax >= 10)
			ptr->iteramax += 10;
		else
			ptr->iteramax = (ptr->iteramax <= 1 ? 2 : ptr->iteramax + 1);
		ft_putnbr(ptr->iteramax);
		ft_putchar('\n');
	}
	if (kc == 78)
	{
		if (ptr->iteramax > 10)
			ptr->iteramax -= 10;
		else
			ptr->iteramax = (ptr->iteramax < 1 ? 1 : ptr->iteramax - 1);
		ft_putnbr(ptr->iteramax);
		ft_putchar('\n');
	}
	fl_aff_fract(ptr);
	return (0);
}

int		mouse_code(int x, int y, t_ptr *ptr)
{
	// ptr->xs = 4;
	// ptr->xs = ptr->xs / SIZE_X;
	// ptr->ys = 4;
	// ptr->ys = ptr->ys / SIZE_Y;
	// ft_putnbrl(x);
	// ft_putnbrl(y);
	// ft_putchar('\n');
	if (ptr->v == 1)
	{
		// ptr->xc = ptr->x1 + (x * ptr->xs);
		// ptr->yc = ptr->y1 + (y * ptr->ys);
		ptr->xc = ptr->x1 + (x * 0.004);
		ptr->yc = ptr->y1 + (y * 0.004);
	}
	// ptr->x = ptr->x1 + (x * ptr->xs);
	// ptr->y = ptr->y1 + (y * ptr->ys);
	fl_aff_fract(ptr);
	return (0);
}

void	fl_aff_main(char *fractname)
{
	t_ptr	ptr;
	t_img	img;

	ptr.fract = fl_set_fract(fractname);
	ptr.size_x = SIZE_X;
	ptr.size_y = SIZE_Y;
	
	ptr.v = 0;
	ptr.x1 = -2;
	ptr.x2 = 2;
	ptr.y1 = -2;
	ptr.y2 = 2;
	ptr.xs = (ptr.x2 - ptr.x1) / SIZE_X;
	ptr.ys = (ptr.y2 - ptr.y1) / SIZE_Y;
	// ptr.xc = ptr.x1 + (500 * ptr.xs);
	// ptr.yc = ptr.x2 + (175 * ptr.ys);
	ptr.xc = -1.3;
	ptr.yc = 0;
	ptr.a = 0;
	ptr.iteramax = ITERAMAX;
	ptr.max = 1;
	ptr.i = 0;
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, ptr.size_x, ptr.size_y, fl_name(ptr.fract));
	img.ptr_img = mlx_new_image(ptr.mlx, SIZE_X, SIZE_Y);
	img.bts = mlx_get_data_addr(img.ptr_img, &(img.bpp), &(img.size_line), &(img.end));
	ptr.img = &img;
	fl_aff_fract(&ptr);
	mlx_hook(ptr.win, 17, (1L << 17), fl_close, &ptr);
	mlx_hook(ptr.win, 2, 3, fl_key_code, &ptr);
	mlx_hook(ptr.win, 6, 1L << 6, mouse_code, &ptr);
	// mlx_hook(ptr.win, 3, 1 << 10, fl_zoom, &ptr);
	mlx_loop(ptr.mlx);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		return (fl_error(1));
	else
	{
		if (fl_set_fract(argv[1]) == 0)
			return (fl_error(2));
		fl_aff_main(argv[1]);
	}
	return (0);
}