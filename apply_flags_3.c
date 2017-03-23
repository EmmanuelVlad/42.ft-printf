/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:02:05 by evlad             #+#    #+#             */
/*   Updated: 2017/03/23 17:02:06 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		apply_l(t_flag *active)
{
	if (active->converter)
		write(1, "l", 1);
	return (0);
}

int		apply_ll(t_flag *active)
{
	if (active->converter)
		write(1, "l", 1);
	return (0);
}

int		apply_h(t_flag *active)
{
	if (active->converter)
		write(1, "h", 1);
	return (0);
}

int		apply_hh(t_flag *active)
{
	if (active->converter)
		write(1, "hh", 1);
	return (0);
}

int		apply_j(t_flag *active)
{
	if (active->converter)
		write(1, "j", 1);		
	return (0);
}
