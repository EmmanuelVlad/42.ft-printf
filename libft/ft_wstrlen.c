/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 18:22:29 by evlad             #+#    #+#             */
/*   Updated: 2017/04/07 20:15:23 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wstrlen(wchar_t *str)
{
	size_t	length;

	length = 0;
	while (*str)
	{
		if (*str <= 0x70F)
			length++;
		else if (*str <= 0x7FF)
			length += 2;
		else if (*str <= 0xFFFF)
			length += 3;
		else if (*str <= 0x10FFFF)
			length += 4;
		str++;
	}
	return (length);
}
