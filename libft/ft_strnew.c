/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:46:54 by evlad             #+#    #+#             */
/*   Updated: 2016/11/09 14:21:51 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*retour;

	if (!(retour = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(retour, size + 1);
	return (retour);
}
