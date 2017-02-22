/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttqbnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 01:17:33 by aancel            #+#    #+#             */
/*   Updated: 2016/11/17 13:22:24 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_puttabnbr(int **map, int l, int c)
{
	int a;
	int b;

	a = 0;
	while (a < l)
	{
		b = 0;
		while (b < c)
		{
			ft_putnbr(map[a][b]);
			ft_putchar(' ');
			b++;
		}
		ft_putchar('\n');
		a++;
	}
}
