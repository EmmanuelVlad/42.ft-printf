/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 08:14:34 by evlad             #+#    #+#             */
/*   Updated: 2017/01/30 17:53:55 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		formating(const char *restrict format, va_list args)
{
	t_flag	*active;
	int		i;

	active = init_flag();
	i = 1;
	while (conv(format[i], active, args) == 0)
	{
		check_flags(format + i, active);
		i++;
	}
	return (i);
}
