/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 08:33:26 by evlad             #+#    #+#             */
/*   Updated: 2017/03/23 15:17:41 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_printf(const char *restrict format, ...)
{
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			format += formating(format, args);
		else
			write(1, &(*format), 1);
		format++;
	}
	va_end(args);
	return (0);
}
