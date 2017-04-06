/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:34:53 by evlad             #+#    #+#             */
/*   Updated: 2017/04/06 20:17:40 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*apply_space(char *buffer, t_flag *active)
{
	char	*str;

	if (active->plus || ft_atoi(buffer) < 0 ||
			ft_strchr("%cu", active->converter))
		return (buffer);
	str = ft_strnew(ft_strlen(buffer) + 1);
	str[0] = ' ';
	ft_strcpy(str + 1, buffer);
	freemalloc(buffer, active, 1);
	return (str);
}

char	*apply_flags_2(char *buffer, int length, t_flag *active)
{
	if (active->precision == 0 && active->diese == 1 &&
			ft_strchr("oO", active->converter) && ft_atoi(buffer) == 0)
	{
		freemalloc(buffer, active, 0);
		return ("0");
	}
	if (active->precision != -1)
		buffer = apply_precision(buffer, length, active);
	if (active->space)
		buffer = apply_space(buffer, active);
	if (active->minus)
		buffer = apply_minus(buffer, active);
	if (active->diese)
		buffer = apply_diese(buffer, active);
	if (active->width && !active->minus)
		buffer = apply_width(buffer, active);
	if (active->zero)
		apply_zero(buffer, active);
	if (active->plus)
		buffer = apply_plus(buffer, active);
	return (buffer);
}

void	apply_flags(char *buffer, int length, t_flag *active, t_length *len)
{
	buffer = apply_flags_2(buffer, length, active);
	ft_putstr(buffer);
	if (active->converter == 'c')
	{
		len->len = 1;
		if (active->width)
			len->len = active->width;
		if (buffer == '\0')
			len->len -= 1;
	}
	else
		len->len += ft_strlen(buffer);
	freemalloc(buffer, active, 0);
}
