/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:34:53 by evlad             #+#    #+#             */
/*   Updated: 2017/03/27 18:07:01 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*apply_flags_2(char *buffer, int length, t_flag *active)
{
	if (active->precision != -1)
		buffer = apply_precision(buffer, length, active);
	if (active->space)
		buffer = apply_space(buffer, active);
	if (active->diese)
		apply_diese(active);
	if (active->zero)
		apply_zero(active);
	if (active->plus)
		buffer = apply_plus(buffer, active);
	if (active->minus)
		buffer = apply_minus(buffer, active);
	if (active->width && !active->minus)
		buffer = apply_width(buffer, active);
	return (buffer);
}

char	*apply_flags(char *buffer, int length, t_flag *active)
{
	buffer = apply_flags_2(buffer, length, active);
	ft_putstr(buffer);
	return (buffer);
}
