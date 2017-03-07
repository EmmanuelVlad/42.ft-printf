/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:25:51 by evlad             #+#    #+#             */
/*   Updated: 2016/11/11 15:05:11 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*retour;
	int		i;

	if (!(s))
		return (NULL);
	i = 0;
	retour = (char*)malloc(sizeof(char) * (len + 1));
	if (retour == NULL)
		return (NULL);
	while (len > 0)
	{
		retour[i] = s[start];
		len--;
		i++;
		start++;
	}
	retour[i] = '\0';
	return (retour);
}
