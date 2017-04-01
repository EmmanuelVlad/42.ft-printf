/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:09:28 by evlad             #+#    #+#             */
/*   Updated: 2017/04/01 04:15:44 by evlad            ###   ########.fr       */
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

char	*sized_oux_int(va_list args, t_flag *active)
{
	uintmax_t	u_int;

	active->first_malloc = 1;
	u_int = unsigned_cast(args, active);
	if (active->converter == 'o')
		return (ft_itoa_base_uint(u_int, 8));
	else if (active->converter == 'u')
		return (ft_itoa_base_uint(u_int, 10));
	else if (active->converter == 'X')
		return (ft_strtoupper(ft_itoa_base_uint(u_int, 16)));
	return (ft_itoa_base_uint(u_int, 16));
}

char	*other_int(va_list args, t_flag *active)
{
	active->first_malloc = 1;
	if (active->converter == 'b')
		return (ft_binary_complete(ft_itoa_base_uint(va_arg(args, int), 2)));
	else if (active->converter == 'o')
		return (ft_itoa_base_uint((va_arg(args, uintmax_t)), 8));
	else if (active->converter == 'u')
		return (ft_itoa_base(va_arg(args, unsigned int), 10));
	else if (active->converter == 'x')
		return (ft_itoa_base_uint(va_arg(args, unsigned int), 16));
	else if (active->converter == 'X')
		return (ft_strtoupper(ft_itoa_base_uint(va_arg(args, unsigned int), 16)));
	return (ft_itoa_base(va_arg(args, int), 10));
}

int		conv_int(char type, t_flag *active, va_list args)
{
	intmax_t	s_int;
	int			len;
	char		*str;

	active->converter = type;
	s_int = 0;
	if (check_size(active) && ft_strchr("di", active->converter))
	{
		s_int = signed_cast(args, active);
		if (s_int == -9223372036854775807 - 1)
			str = "-9223372036854775808";
		else
		{
			active->first_malloc = 1;
			str = ft_itoa_base(s_int, 10);
		}
	}
	else if (check_size(active) && ft_strchr("ouxX", active->converter))
		str = sized_oux_int(args, active);
	else
		str = other_int(args, active);
	len = ft_strlen(str);
	apply_flags(str, len, active);
	return (len);
}

int		conv_s(char type, t_flag *active, va_list args)
{
	char	*str;
	int		len;

	str = va_arg(args, char*);
	len = ft_strlen(str);
	active->converter = type;
	apply_flags(str, len, active);
	if (len == 0)
		return (1);
	return (len);
}
