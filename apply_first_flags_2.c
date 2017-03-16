/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_first_flags_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:18:47 by evlad             #+#    #+#             */
/*   Updated: 2017/03/16 18:26:21 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		apply_flag_diese(char converter)
{
	if (converter)
		write(1, "#", 1);
	return (0);
}

int		apply_flag_zero(char converter)
{
	if (converter)
		write(1, "0", 1);
	return (0);
}

int		apply_flag_plus(char converter, char *buffer)
{
	if (converter)
	{
		if ((int)buffer >= 0)
			write(1, "+", 1);
	}
	return (0);
}

int		apply_flag_min_size(char converter, int length, t_flag *active)
{
	int		i;

	i = active->min_size - length;
	if (ft_strchr("sd", converter) && active->precision_size)
		i = active->min_size - active->precision_size;
	while (i-- > 0)
		write(1, " ", 1);
	return (0);
}
