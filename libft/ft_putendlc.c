/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendlc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aancel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 12:17:44 by aancel            #+#    #+#             */
/*   Updated: 2017/01/10 12:17:47 by aancel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putendlc(char *color, char *str)
{
	ft_putstr(color);
	ft_putstr(str);
	ft_putendl(FIN);
}
