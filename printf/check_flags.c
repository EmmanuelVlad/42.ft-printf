/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 15:06:27 by evlad             #+#    #+#             */
/*   Updated: 2017/04/06 17:56:53 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		check_size(t_flag *active)
{
	if (active->l)
		return (1);
	else if (active->ll)
		return (1);
	else if (active->h)
		return (1);
	else if (active->hh)
		return (1);
	else if (active->j)
		return (1);
	else if (active->z)
		return (1);
	return (0);
}

int		check_flags_2(const char *flag, t_flag *active)
{
	int i;

	i = 0;
	while (flag[i] >= 48 && flag[i] <= 57 && active->precision == -1)
		active->width = (active->width * 10) + (int)(flag[i++] - 48);
	while (flag[i] >= 48 && flag[i] <= 57 && active->precision != -1)
		active->precision = (active->precision * 10) + (int)(flag[i++] - 48);
	if (i == 0)
		return (0);
	else
		return (i - 1);
}

int		check_flags(const char *flag, t_flag *active)
{
	if (flag[0] == '+')
		active->plus = 1;
	if (flag[0] == ' ')
		active->space = 1;
	if (flag[0] == '#')
		active->diese = 1;
	if (flag[0] == '0' && active->precision == -1)
		active->zero = 1;
	if (flag[0] == '-')
		active->minus = 1;
	if (flag[0] == 'l' && flag[1] != 'l' && !active->ll)
		active->l = 1;
	if (flag[0] == 'l' && flag[1] == 'l')
		active->ll = 1;
	if (flag[0] == 'h' && flag[1] != 'h' && !active->hh)
		active->h = 1;
	if (flag[0] == 'h' && flag[1] == 'h')
		active->hh = 1;
	if (flag[0] == 'j')
		active->j = 1;
	if (flag[0] == 'z')
		active->z = 1;
	if (flag[0] == '.')
		active->precision = 0;
	return (check_flags_2(flag, active));
}
