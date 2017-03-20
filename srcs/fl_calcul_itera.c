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

int		mouse_code1(int x, int y, t_ptr *ptr)
{
	if (ptr->v == 1)
	{
		ptr->xc = -2 + (x * 0.004);
		ptr->yc = -2 + (y * 0.004);
	}
	ptr->px = x;
	ptr->py = y;
	fl_aff_fract(ptr);
	return (0);
}

int		mouse_code(int button, int x, int y, t_ptr *ptr)
{
	x += 0;
	y += 0;
	if (button == 4)
		fl_zoom1(x, y, ptr);
	if (button == 5)
		fl_zoom2(x, y, ptr);
	fl_aff_fract(ptr);
	return (0);
}

int		fl_nbr_itera(long double xc, long double yc, t_ptr *ptr)
{
	t_pnt	pnt;

	if (ptr->fract == 1)
	{
		pnt.x = xc;
		pnt.y = yc;
		pnt.xc = ptr->xc;
		pnt.yc = ptr->yc;
	}
	if (ptr->fract == 2 || ptr->fract == 3)
	{
		pnt.x = 0;
		pnt.y = 0;
		pnt.xc = xc;
		pnt.yc = yc;
	}
	return (fl_calc_itera(&pnt, ptr));
}

int		fl_calc_itera(t_pnt *pnt, t_ptr *ptr)
{
	int			itera;
	long double	tmp;

	itera = 0;
	while (((pnt->x * pnt->x) + (pnt->y * pnt->y))
		< 4 && itera < ptr->iteramax)
	{
		tmp = pnt->x;
		pnt->x = (pnt->x * pnt->x) - (pnt->y * pnt->y) + pnt->xc;
		if (ptr->fract == 3)
		{
			pnt->y = (2 * ABS(pnt->y) * ABS(tmp)) + pnt->yc;
			pnt->x = ABS(pnt->x);
			pnt->y = ABS(pnt->y);
		}
		else
			pnt->y = (2 * pnt->y * tmp) + pnt->yc;
		itera += 1;
	}
	return (itera);
}
