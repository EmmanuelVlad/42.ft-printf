/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:06:50 by evlad             #+#    #+#             */
/*   Updated: 2017/01/30 17:06:52 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	apply_flags(char converter, t_flag *active)
{
	if (active->diese)
		apply_flag_diese(converter);
	if (active->zero)
		apply_flag_zero(converter);
	if (active->minus)
		apply_flag_minus(converter);
	if (active->plus)
		apply_flag_plus(converter);
	if (active->space)
		apply_flag_space(converter);
	if (active->l)
		apply_flag_l(converter);
	if (active->ll)
		apply_flag_ll(converter);
	if (active->h)
		apply_flag_h(converter);
	if (active->hh)
		apply_flag_hh(converter);
	if (active->j)
		apply_flag_j(converter);
	if (active->z)
		apply_flag_z(converter);
}

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

int		apply_flag_minus(char converter)
{
	if (converter)
		write(1, "-", 1);
	return (0);
}

int		apply_flag_plus(char converter)
{
	if (converter)
		write(1, "+", 1);
	return (0);
}
