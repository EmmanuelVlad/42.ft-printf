/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:09:28 by evlad             #+#    #+#             */
/*   Updated: 2017/01/30 17:52:48 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		conv(char type, t_flag *active, va_list args)
{
	int					i;
	static const t_conv	g_conv[] = {
		{ "bdiouxX", &conv_int },
		{ "DOU", &conv_dou },
		{ "Cc", &conv_c },
		{ "s", &conv_s },
		{ "S", &conv_ws },
		{ "p", &conv_p },
		{ "%", &conv_pct }
	};

	i = 0;
	while (i < 7)
	{
		if (ft_strchr(g_conv[i].type, type))
			return (g_conv[0].function(type, active, args));
		i++;
	}
	return (0);
}

int		conv_int(char type, t_flag *active, va_list args)
{
	int		len;
	int		nbr;

	if (type)
		nbr = 1;
	nbr = va_arg(args, int);
	len = ft_strlen(ft_itoa(nbr));
	apply_flags(type, active);
	ft_putnbr(nbr);
	return (len);
}

int		conv_dou(char type, t_flag *active, va_list args)
{
	if (type && active && args)
		return (1);
	return (0);
}

int		conv_c(char type, t_flag *active, va_list args)
{
	if (type && active && args)
		return (1);
	return (0);
}

int		conv_s(char type, t_flag *active, va_list args)
{
	if (type && active && args)
		return (1);
	return (0);
}
