/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 11:32:48 by evlad             #+#    #+#             */
/*   Updated: 2017/04/01 04:15:57 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(void)
{
	char	str[] = "printf from scrap!";
	ft_printf("FT_PRINTF: '%#hhX'", (unsigned char)50);
	printf("\n   PRINTF: '%#hhX'\n\n", (unsigned char)50);
	
	ft_printf("FT_PRINTF: '%0.8x'", 1337);
	printf("\n   PRINTF: '%0.8x\n\n", 1337);

	ft_printf("FT_PRINTF: '%p'", (void*)str);
	printf("\n   PRINTF: '%p'\n\n", (void*)str);

	ft_printf("FT_PRINTF: '%lld'", (long long int)-9223372036854775807 - 1);
	printf("\n   PRINTF: '%lld'\n\n", (long long int)-9223372036854775807 - 1);

	ft_printf("FT_PRINTF: '%14.8s'", "\0\0\0\0\0");
	printf("\n   PRINTF: '%14.8s'\n\n", "\0\0\0\0\0");

	ft_printf("FT_PRINTF: '%O'", -1337);
	printf("\n   PRINTF: '%O'\n\n", -1337);

	ft_printf("BONUS (BINARY): '%b'", 1337);
	return (0);
}
