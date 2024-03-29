/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 09:40:30 by aancel            #+#    #+#             */
/*   Updated: 2016/11/17 11:21:17 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbr(int n)
{
	unsigned int p;

	if (n < 0)
		ft_putchar('-');
	p = ABS(n);
	if (p >= 10)
	{
		ft_putnbr(p / 10);
		ft_putnbr(p % 10);
	}
	else
	{
		ft_putchar(p + '0');
	}
}
