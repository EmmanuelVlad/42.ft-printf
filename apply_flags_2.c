/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:02:24 by evlad             #+#    #+#             */
/*   Updated: 2017/03/30 21:24:09 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*apply_diese(char *buffer, t_flag *active)
{
	char	*str;

	str = buffer;
	if (active->converter == 'o' && !active->hh)
	{
		str = ft_strnew(ft_strlen(buffer) + 1);
		str[0] = '0';
		ft_strcpy(str + 1, buffer);
		freemalloc(buffer, active, 1);
	}
	else if (active->converter == 'X' || active->converter == 'x')
	{
		str = ft_strnew(ft_strlen(buffer) + 2);
		str[0] = '0';
		str[1] = 'x';
		if (active->converter == 'X')
			str[1] = 'X';
		ft_strcpy(str + 2, buffer);
		freemalloc(buffer, active, 1);
	}
	return (str);
}

int		apply_zero(t_flag *active)
{
	if (active->converter)
		;
	return (0);
}

char	*apply_plus(char *buffer, t_flag *active)
{
	char	*str;

	str = NULL;
	if (ft_strchr("bdiD", active->converter) && ft_atoi(buffer) > 0)
	{
		str = ft_strnew(ft_strlen(buffer) + 1);
		ft_strcpy(str + 1, buffer);
		freemalloc(buffer, active, 1);
		if (ft_atoi(buffer) >= 0)
			str[0] = '+';
		else
			str[0] = '-';
		return (str);
	}
	return (buffer);
}

char	*apply_width(char *buffer, t_flag *active)
{
	int		i;
	char	*str;

	i = 0;
	if ((int)ft_strlen(buffer) >= active->width)
		return (buffer);
	str = ft_strnew(active->width + 1);
	while (i < (active->width - (int)ft_strlen(buffer)))
		str[i++] = ' ';
	ft_strcpy(str + i, buffer);
	freemalloc(buffer, active, 1);
	return (str);
}
