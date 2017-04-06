/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 17:03:12 by evlad             #+#    #+#             */
/*   Updated: 2017/04/06 20:15:15 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*apply_zero_x(char *buffer, t_flag *active)
{
	int		i;

	i = 2;
	buffer[0] = '0';
	buffer[1] = active->converter;
	while (buffer[i] != active->converter)
		buffer[i++] = '0';
	buffer[i] = '0';
	return (buffer);
}

char	*apply_zero_p(char *buffer, t_flag *active)
{
	char	*str;
	int		i;

	str = ft_strdup(buffer);
	str[0] = '0';
	str[1] = 'x';
	while (str[i] != 'x' && str[i])
		str[i++] = '0';
	str[i] = '0';
	freemalloc(buffer, active, 1);
	return (str);
}

char	*apply_zero_3(char *buffer, t_flag *active)
{
	int		j;

	buffer[0] = '-';
	j = 1;
	while (buffer[j])
	{
		if (buffer[j] == '-' || buffer[j] == ' ')
			buffer[j] = '0';
		j++;
	}
	return (buffer);
}

char	*apply_zero_2(char *buffer, t_flag *active)
{
	int		i;

	i = 0;
	if (active->precision >= 0)
		i = ft_strlen(buffer) - active->precision;
	if ((active->converter == 'x' || active->converter == 'X') && active->diese)
		return (apply_zero_x(buffer, active));
	else if (active->converter == 'p')
		return (apply_zero_p(buffer, active));
	else
	{
		while (buffer[i])
		{
			if (buffer[i] == ' ')
				buffer[i] = '0';
			i++;
		}
	}
	return (buffer);
}

char	*apply_zero(char *buffer, t_flag *active)
{
	char	*str;

	if (active->minus)
		return (buffer);
	else if (ft_atoi(buffer) < 0)
		str = apply_zero_3(buffer, active);
	else
		str = apply_zero_2(buffer, active);
	return (buffer);
}
