/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_last_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:21:31 by evlad             #+#    #+#             */
/*   Updated: 2017/03/16 18:27:55 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	apply_last_flags(char converter, char *buffer, int length,
		t_flag *active)
{
	if (active->precision)
		apply_flag_precision(converter);
	if (active->precision_size)
		apply_flag_precision_size(converter, buffer, active);
	if (active->minus)
		apply_flag_minus(converter, length, active);
}

int		apply_flag_minus(char converter, int length, t_flag *active)
{
	int		i;

	i = active->min_size - length;
	if (ft_strchr("sd", converter) && active->precision_size)
		i = active->min_size - active->precision_size;
	while (i-- > 0)
		write(1, " ", 1);
	return (0);
}

int		apply_flag_precision(char converter)
{
	if (converter)
		return (0);
	return (0);
}

char	*apply_flag_precision_size(char converter, char *buffer, t_flag *active)
{
	char	*tmp;
	size_t	size;

	tmp = NULL;
	size = active->precision_size;
	if (ft_strchr("sd", converter))
	{
		tmp = buffer;
		buffer = malloc(sizeof(char) * (active->precision_size + 1));
		strncat(buffer, tmp, active->precision_size);
		if (converter == 'd')
		{
			while (size > ft_strlen(tmp))
			{
				buffer = ft_strjoin("0", buffer);
				size--;
			}
		}
		ft_putstr(buffer);
	}
	return (buffer);
}
