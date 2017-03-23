/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 08:14:34 by evlad             #+#    #+#             */
/*   Updated: 2017/03/22 10:59:06 by evlad            ###   ########.fr       */
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
		i += 1 + check_flags(format + i, active);
	free(active);
	return (i);
}
