/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 16:44:47 by aancel            #+#    #+#             */
/*   Updated: 2017/02/01 16:44:50 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx_macos/mlx.h"
# include "color.h"
# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define ABS(x) ((x) < 0 ? -(x) : (x))
# define SIZE_X 700
# define SIZE_Y 700
# define ITERAMAX 50

typedef struct	s_img
{
	void		*ptr_img;
	char		*bts;
	int			size_line;
	int			bpp;
	int			end;
}				t_img;

typedef struct	s_pnt
{
	long double x;
	long double y;
	long double xc;
	long double yc;
}				t_pnt;

typedef struct	s_ptr
{
	void		*mlx;
	void		*win;
	int			size_x;
	int			size_y;
	int			fract;
	int			iteramax;
	int			color;
	float		h;
	int			v;
	float		max;
	long double	xc;
	long double	yc;
	long double px;
	long double py;
	long double	xs;
	long double	ys;
	long double x1;
	long double y1;
	long double x2;
	long double y2;
	long double x;
	long double y;
	long double verti;
	long double hori;
	int			a;
	int			i;
	t_img		*img;
}				t_ptr;

int				main(int argc, char **argv);
void			fl_aff_main(char *fractname);
void			fl_aff_fract(t_ptr *ptr);
int				fl_nbr_itera(long double xc, long double yc, t_ptr *ptr);
int				ft_sqrt(int nb);
int				fl_set_fract(char *name);
char			*fl_name(int fract);
int				fl_error(int err);
int				mouse_code1(int x, int y, t_ptr *ptr);
int				mouse_code(int button, int x, int y, t_ptr *ptr);
int				fl_close(t_ptr *ptr);
int				fl_zoom1(long double x, long double y, t_ptr *ptr);
int				fl_zoom2(long double x, long double y, t_ptr *ptr);
char			*ft_putprec(long double nbr);
void			fl_initialis(t_ptr	*ptr);
int				fl_key_code(int kc, t_ptr *ptr);
void			pix_put_img(t_ptr *ptr, int x, int y, int color);
int				fl_key_code1(int kc, t_ptr *ptr);
int				fl_key_code2(int kc, t_ptr *ptr);
int				fl_calc_itera(t_pnt *pnt, t_ptr *ptr);
void			ft_change_col(t_ptr *ptr, int i);

#endif
