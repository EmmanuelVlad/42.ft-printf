/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 08:14:34 by evlad             #+#    #+#             */
/*   Updated: 2017/04/06 22:12:07 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		formating(const char *restrict format, va_list args, t_length *len)
{
	t_flag	*active;
	int		i;

	active = init_flag();
	i = 1;
	if (format[i] == '\0')
		return (i);
	while (ft_strchr(" .0123456789+-#lhjz", format[i]) && format[i])
		i += 1 + check_flags(format + i, active);
	if (ft_strchr("bdiouxXDOUCcsSp%", format[i]) && format[i])
	{
		//printf("conv: {%c}", format[i]);
		conv(format[i], active, args, len);
		free(active);
		i++;
	}
	else if (!ft_strchr("bdiouxXDOUCcsSp", format[i]))
	{
		//printf("len: {%d}, i: {%d}", len->len, i);
		write(1, &format[i], 1);
		len->len++;
		i++;
	}
	return (i);
}
