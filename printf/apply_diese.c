/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_diese.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 18:27:44 by evlad             #+#    #+#             */
/*   Updated: 2017/04/06 21:11:30 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*apply_diese_x(char *buffer, t_flag *active)
{
	char	*str;

	str = ft_strnew(ft_strlen(buffer) + 2);
	str[0] = '0';
	str[1] = 'x';
	if (active->converter == 'X')
		str[1] = 'X';
	ft_strcpy(str + 2, buffer);
	freemalloc(buffer, active, 1);
	return (str);
}

char	*apply_diese_2(char *buffer, t_flag *active)
{
	char	*str;
	int		i;

	i = 0;
	if (buffer[0] == ' ')
	{
		while (buffer[i] == ' ')
			i++;
		buffer[i - 1] = '0';
		return (buffer);
	}
	else
	{
		str = ft_strnew(ft_strlen(buffer) + 1);
		str[0] = '0';
		ft_strcpy(str + 1, buffer);
		freemalloc(buffer, active, 1);
	}
	return (str);
}

char	*apply_diese(char *buffer, t_flag *active)
{
	int		i;

	i = 0;
	if (ft_strchr("csdiupUCDS%", active->converter) || ft_atoi(buffer) == 0)
		return (buffer);
	else if (active->converter == 'o' && !active->hh)
		return (apply_diese_2(buffer, active));
	else if (ft_strchr("xX", active->converter))
		return (apply_diese_x(buffer, active));
	return (buffer);
}
