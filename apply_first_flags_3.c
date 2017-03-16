/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_first_flags_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:18:56 by evlad             #+#    #+#             */
/*   Updated: 2017/03/13 18:19:01 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

int		apply_flag_j(char converter)
{
	if (converter)
		write(1, "j", 1);		
	return (0);
}
