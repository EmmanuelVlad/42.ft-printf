/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:09:34 by evlad             #+#    #+#             */
/*   Updated: 2017/03/27 18:12:33 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


int		conv_dou(char type, t_flag *active, va_list args)
{
	if (type == 'D')
		type = 'd';
	else if (type == 'O')
		type = 'o';
	else if (type == 'U')
		type = 'u';
	return (conv_int(type, active, args));
}

int		conv_c(char	type, t_flag *active, va_list args)
{
	char	*str;

	str = ft_strnew(2)	;
	active->malloc = 1;
	str[0] = (unsigned char)va_arg(args, int);
	str[1] = '\0';
	active->converter = type;
	apply_flags(str, 1, active);
	return (1);
}

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
