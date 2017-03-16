/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 15:06:27 by evlad             #+#    #+#             */
/*   Updated: 2017/03/16 15:50:24 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_flags(const char *flag, t_flag *active)
{
	int i;

	i = 0;
	if (flag[0] == '+')
		active->plus = 1;
	if (flag[0] == ' ')
		active->min_size = 1;
	if (flag[0] == '#')
		active->diese = 1;
	if (flag[0] == '0')
		active->zero = 1;
	if (flag[0] == '-')
		active->minus = 1;
	if (flag[0] == 'l' && flag[1] != 'l')
		active->l = 1;
	if (flag[0] == 'l' && flag[1] == 'l')
		active->ll = 1;
	if (flag[0] == 'h' && flag[1] != 'h')
		active->h = 1;
	if (flag[0] == 'h' && flag[1] == 'h')
		active->hh = 1;
	if (flag[0] == 'j')
		active->j = 1;
	if (flag[0] == 'z')
		active->z = 1;
	if (flag[0] == '.')
		active->precision = 1;
	while (flag[i] >= 48 && flag[i] <= 57 && active->precision != 1)
	{
		if (active->min_size)
			active->min_size *= 10;
		active->min_size += (int)(flag[i] - 48);
		i++;
	}
	while (flag[i] >= 48 && flag[i] <= 57 && active->precision == 1)
	{
		if (active->precision_size)
			active->precision_size *= 10;
		active->precision_size += (int)(flag[i] - 48);
		i++;
	}
	if (i == 0)
		return (0);
	else
		return (i - 1);
}
