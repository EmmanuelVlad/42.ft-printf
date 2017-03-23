/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:09:28 by evlad             #+#    #+#             */
/*   Updated: 2017/03/23 18:02:37 by evlad            ###   ########.fr       */
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
			return (g_conv[i].function(type, active, args));
		i++;
	}
	return (0);
}

int		conv_int(char type, t_flag *active, va_list args)
{
	int		len;
	char	*nbr;

	nbr = ft_itoa(va_arg(args, int));
	len = ft_strlen(nbr);
	active->converter = type;
	apply_flags(nbr, len, active);
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
	char	*str;
	
	str = ft_strnew(2);
	active->malloc = 1;
	str[0] = (unsigned char)va_arg(args, int);
	str[1] = '\0';
	active->converter = type;
	apply_flags(str, 1, active);
	return (1);
}

int		conv_s(char type, t_flag *active, va_list args)
{
	char	*str;
	int		len;

	str = va_arg(args, char*);
	len = ft_strlen(str);
	active->converter = type;
	apply_flags(str, len, active);
	return (len);
}
