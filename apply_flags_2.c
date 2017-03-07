/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:05:42 by evlad             #+#    #+#             */
/*   Updated: 2017/01/30 17:44:05 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		apply_flag_space(char converter)
{
	if (converter)
		write(1, " ", 1);
	return (0);
}

int		apply_flag_l(char converter)
{
	if (converter)
		write(1, "l", 1);
	return (0);
}

int		apply_flag_ll(char converter)
{
	if (converter)
		write(1, "l", 1);
	return (0);
}

int		apply_flag_h(char converter)
{
	if (converter)
		write(1, "h", 1);
	return (0);
}

int		apply_flag_hh(char converter)
{
	if (converter)
		write(1, "hh", 1);
	return (0);
}
