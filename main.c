/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 11:32:48 by evlad             #+#    #+#             */
/*   Updated: 2017/03/16 18:28:18 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(void)
{
	char	*str;
	char	*str2;
	int		nbr;

	str = "J'adore tester printf";
	str2 = "test";
	nbr = 1337;

	ft_printf("FT_PRINTF:%14.12d %-7.3s", nbr, str2);
	printf("\n   PRINTF:%14.12d %-7.3s\n", nbr, str2);
	return (0);
}
