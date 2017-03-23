/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:34:53 by evlad             #+#    #+#             */
/*   Updated: 2017/03/23 17:07:23 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*apply_flags_3(char *buffer, int length, t_flag *active)
{
	if (length)
		;
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

char	*apply_flags_2(char *buffer, int length, t_flag *active)
{
	if (active->l)
		apply_l(active);
	if (active->ll)
		apply_ll(active);
	if (active->h)
		apply_h(active);
	if (active->hh)
		apply_hh(active);
	if (active->j)
		apply_j(active);
	if (active->z)
		apply_z(active);
	if (active->precision != -1)
		buffer = apply_precision(buffer, length, active);
	return (apply_flags_3(buffer, length, active));
}

char	*apply_flags(char *buffer, int length, t_flag *active)
{
	buffer = apply_flags_2(buffer, length, active);
	ft_putstr(buffer);
	return (buffer);
}
