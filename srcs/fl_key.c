/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 16:44:59 by aancel            #+#    #+#             */
/*   Updated: 2017/02/01 16:45:01 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		fl_key_code(int kc, t_ptr *ptr)
{
	if (kc == 53)
		fl_close(ptr);
	if (kc == 42)
		fl_zoom1(ptr->px, ptr->py, ptr);
	if (kc == 36)
		fl_zoom2(ptr->px, ptr->py, ptr);
	if (kc == 9)
		ptr->v = (ptr->v == 0 ? 1 : 0);
	if (kc == 126 || kc == 125 || kc == 124 || kc == 123)
		fl_key_code1(kc, ptr);
	if (kc == 49)
		ft_change_col(ptr, 1);
	if (kc == 12)
		ft_change_col(ptr, 255);
	if (kc == 69 || kc == 78)
		fl_key_code2(kc, ptr);
	fl_aff_fract(ptr);
	return (0);
}

int		fl_key_code1(int kc, t_ptr *ptr)
{
	if (kc == 126)
	{
		ptr->y1 = ptr->y1 + 10 * ptr->ys;
		ptr->y2 = ptr->y2 + 10 * ptr->ys;
	}
	if (kc == 125)
	{
		ptr->y1 = ptr->y1 - 10 * ptr->ys;
		ptr->y2 = ptr->y2 - 10 * ptr->ys;
	}
	if (kc == 124)
	{
		ptr->x1 = ptr->x1 - 10 * ptr->xs;
		ptr->x2 = ptr->x2 - 10 * ptr->xs;
	}
	if (kc == 123)
	{
		ptr->x1 = ptr->x1 + 10 * ptr->xs;
		ptr->x2 = ptr->x2 + 10 * ptr->xs;
	}
	return (0);
}

int		fl_key_code2(int kc, t_ptr *ptr)
{
	if (kc == 69)
	{
		if (ptr->iteramax >= 10)
			ptr->iteramax += 10;
		else
			ptr->iteramax = (ptr->iteramax <= 1 ? 2 : ptr->iteramax + 1);
	}
	if (kc == 78)
	{
		if (ptr->iteramax > 10)
			ptr->iteramax -= 10;
		else
			ptr->iteramax = (ptr->iteramax < 1 ? 1 : ptr->iteramax - 1);
	}
	return (0);
}
