/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:02:13 by evlad             #+#    #+#             */
/*   Updated: 2017/03/23 17:02:18 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		apply_z(t_flag *active)
{
	if (active->converter)
		write(1, "z", 1);
	return (0);
}

char	*apply_space(char *buffer, t_flag *active)
{
	char	*str;

	if (active->plus || ft_atoi(buffer) < 0)
		return (buffer);
	str = ft_strnew(ft_strlen(buffer) + 1);
	str[0] = ' ';
	ft_strcpy(str + 1, buffer);
	free(buffer);
	return (str);
}

char	*apply_minus( char *buffer, t_flag *active)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if ((int)ft_strlen(buffer) >= active->width)
		return (buffer);
	str = ft_strnew(active->width + 1);
	while (j < (int)ft_strlen(buffer))
		str[i++] = buffer[j++];
	j = 0;
	while (j++ < (active->width - (int)ft_strlen(buffer)))
		str[i++] = ' ';
	str[i] = '\0';
	return (str);
}
