/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 11:32:48 by evlad             #+#    #+#             */
/*   Updated: 2017/03/30 12:22:20 by evlad            ###   ########.fr       */
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
	nbr = -1337;

/*
	ft_printf("FT_PRINTF:'%14.3d' '%7.15s' '%10%' lol wtf", 1337, str2);
	printf("\n   PRINTF:'%14.3d' '%7.15s' '%+10%' lol wtf\n", 1337, str2);
	ft_printf("\nFT_PRINTF:'%+-15.9d' '%10s' %+10% lol wtf\n", nbr, str2);
	printf("   PRINTF:'%+-15.9d' '%10s' %+10% lol wtf\n", nbr, str2);
*/
	ft_printf("FT_PRINTF:'%14.3llX'", (long long int)13370000000000);
	printf("\n   PRINTF:'%14.3llX'", (long long int)13370000000000);

	return (0);
}
