/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:09:34 by evlad             #+#    #+#             */
/*   Updated: 2017/03/22 15:30:11 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		conv_ws(char type, t_flag *active, va_list args)
{
	if (type && active && args)
		return (1);
	return (0);
}

int		conv_p(char type, t_flag *active, va_list args)
{
	if (type && active && args)
		return (1);
	return (0);
}

int		conv_pct(char type, t_flag *active, va_list args)
{
	if (type && args)
		;
	apply_flags("%\0", 1, active);
	return (1);
}
