/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:06:13 by evlad             #+#    #+#             */
/*   Updated: 2017/01/30 17:06:24 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		apply_flag_j(char converter)
{
	if (converter)
		write(1, "j", 1);
	return (0);
}

int		apply_flag_z(char converter)
{
	if (converter)
		write(1, "z", 1);
	return (0);
}
