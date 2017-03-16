/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_first_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:17:14 by evlad             #+#    #+#             */
/*   Updated: 2017/03/16 17:30:13 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	apply_first_flags(char converter, char *buffer, int length, t_flag *active)
{
	if (active->diese)
		apply_flag_diese(converter);
	if (active->zero)
		apply_flag_zero(converter);
	if (active->plus)
		apply_flag_plus(converter, buffer);
	if (active->min_size && !active->minus)
		apply_flag_min_size(converter, length, active);
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
