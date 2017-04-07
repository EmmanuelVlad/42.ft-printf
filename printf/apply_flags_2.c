/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:02:24 by evlad             #+#    #+#             */
/*   Updated: 2017/04/07 19:46:20 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*apply_plus(char *buffer, t_flag *active)
{
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	if (!ft_strchr("bdiD", active->type) || ft_atoi(buffer) < 0)
		return (buffer);
	if (active->zero && buffer[0] == '0')
		buffer[0] = '+';
	else if (buffer[0] == ' ')
	{
		while (buffer[i] == ' ')
			i++;
		buffer[i - 1] = '+';
	}
	else
	{
		str = ft_strnew(ft_strlen(buffer) + 1);
		ft_strcpy(str + 1, buffer);
		freemalloc(buffer, active, 1);
		str[0] = '+';
		return (str);
	}
	return (buffer);
}

char	*apply_width(char *buffer, t_flag *active)
{
	int		i;
	char	*str;
	int		len;

	i = 0;
	len = ft_strlen(buffer);
	if (active->type == 'c')
		len = 1;
	if (len >= active->width)
		return (buffer);
	str = ft_strnew(active->width + 1);
	while (i < (active->width - len))
		str[i++] = ' ';
	ft_strcpy(str + i, buffer);
	freemalloc(buffer, active, 1);
	return (str);
}

char	*apply_minus(char *buffer, t_flag *active)
{
	size_t	i;
	size_t	j;
	char	*str;
	size_t	width;

	i = 0;
	j = 0;
	width = active->width;
	if (active->diese && ft_strchr("xXp", active->type))
		width -= 2;
	else if (active->diese && !ft_strchr("bdiD", active->type))
		width -= 1;
	if (active->plus && ft_strchr("bdiD", active->type) && ft_atoi(buffer) >= 0)
		width -= 1;
	if (ft_strlen(buffer) >= width)
		return (buffer);
	str = ft_strnew(width + 1);
	while (j < ft_strlen(buffer))
		str[i++] = buffer[j++];
	j = 0;
	while (j++ < (width - ft_strlen(buffer)))
		str[i++] = ' ';
	str[i] = '\0';
	freemalloc(buffer, active, 1);
	return (str);
}
