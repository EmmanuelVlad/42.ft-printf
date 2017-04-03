/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 08:14:34 by evlad             #+#    #+#             */
/*   Updated: 2017/04/03 17:31:57 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		formating(const char *restrict format, va_list args, t_length *len)
{
	t_flag	*active;
	int		i;

	active = init_flag();
	i = 1;
	while (conv(format[i], active, args, len) == 0)
		i += 1 + check_flags(format + i, active);
	free(active);
	return (i);
}
