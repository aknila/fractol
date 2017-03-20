/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 16:44:59 by aancel            #+#    #+#             */
/*   Updated: 2017/02/01 16:45:01 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		fl_zoom1(long double x, long double y, t_ptr *ptr)
{
	long double	dx;
	long double	dy;
	long double cur_x;
	long double cur_y;

	cur_x = ptr->x1 + (x * ptr->xs);
	cur_y = ptr->y1 + (y * ptr->ys);
	dx = ptr->x2 - ptr->x1;
	dy = ptr->y2 - ptr->y1;
	ptr->x1 = ptr->x1 + (cur_x - ptr->x1) / 2;
	ptr->y1 = ptr->y1 + (cur_y - ptr->y1) / 2;
	ptr->x2 = ptr->x1 + (dx / 2);
	ptr->y2 = ptr->y1 + (dy / 2);
	ptr->xs = (ptr->x2 - ptr->x1) / SIZE_X;
	ptr->ys = (ptr->y2 - ptr->y1) / SIZE_Y;
	ptr->a++;
	return (0);
}

int		fl_zoom2(long double x, long double y, t_ptr *ptr)
{
	long double	dx;
	long double	dy;
	long double cur_x;
	long double cur_y;

	cur_x = ptr->x1 + (x * ptr->xs);
	cur_y = ptr->y1 + (y * ptr->ys);
	dx = ptr->x2 - ptr->x1;
	dy = ptr->y2 - ptr->y1;
	ptr->x1 = ptr->x1 - (cur_x - ptr->x1);
	ptr->y1 = ptr->y1 - (cur_y - ptr->y1);
	ptr->x2 = ptr->x1 + (dx * 2);
	ptr->y2 = ptr->y1 + (dy * 2);
	ptr->xs = (ptr->x2 - ptr->x1) / SIZE_X;
	ptr->ys = (ptr->y2 - ptr->y1) / SIZE_Y;
	ptr->a--;
	return (0);
}

void	ft_change_col(t_ptr *ptr, int i)
{
	ptr->color += i * 0x00001010;
	if (ptr->color == 0x00FFFF00)
		ptr->color = 0x00001010;
}
