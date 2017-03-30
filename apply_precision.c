/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:13:17 by evlad             #+#    #+#             */
/*   Updated: 2017/03/30 21:04:13 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*apply_precision_negative(char *buffer, int length, t_flag *active)
{
	char	*str;
	int		i;
	int		j;

	str = ft_strnew(active->precision + 2);
	i = 0;
	j = 0;
	while (i < (active->precision - length + 2))
		str[i++] = '0';
	str[0] = '-';
	ft_strcpy(str + i, buffer + 1);
	freemalloc(buffer, active, 1);
	return (str);
}

char	*apply_precision_2(char *buffer, int length, t_flag *active)
{
	char	*str;
	int		i;
	int		j;

	if (active->converter == 'b')
		return (buffer);
	if (ft_atoi(buffer) < 0)
		return (apply_precision_negative(buffer, length, active));
	str = ft_strnew(active->precision + 1);
	i = 0;
	j = 0;
	while ((i < (active->precision - length)) && active->converter != 's')
		str[i++] = '0';
	while (buffer[j])
		str[i++] = buffer[j++];
	str[i] = '\0';
	freemalloc(buffer, active, 1);
	return (str);
}

char	*apply_precision(char *buffer, int length, t_flag *active)
{
	if (length >= active->precision && active->converter == 's')
	{
		active->second_malloc = 1;
		return (ft_strsub(buffer, 0, active->precision));
	}
	else if (length >= active->precision && active->converter == 'S')
		return (0);
	else if (length >= active->precision)
		return (buffer);
	else if (length < active->precision && (active->converter == 'c' ||
											active->converter == 'C'))
		return (buffer);
	else
		return (apply_precision_2(buffer, length, active));
}
