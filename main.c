/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 11:32:48 by evlad             #+#    #+#             */
/*   Updated: 2017/03/30 21:43:37 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(void)
{
	char	str[] = "printf from scrap!";
	ft_printf("FT_PRINTF:'%#14.3hhX'", (unsigned char)50);
	printf("\n   PRINTF:'%#14.3hhX'\n\n", (unsigned char)50);
	
	ft_printf("FT_PRINTF:'%0.8x'", 67);
	printf("\n   PRINTF:'%0.8x\n\n", 67);

	ft_printf("FT_PRINTF:'%p'", (void*)str);
	printf("\n   PRINTF:'%p'\n\n", (void*)str);

	ft_printf("FT_PRINTF:'%18p'", (void*)str);
	printf("\n   PRINTF:'%18p'\n\n", (void*)str);

	ft_printf("FT_PRINTF:'%lld'", (long long int)-9223372036854775807 - 1);
	printf("\n   PRINTF:'%lld'\n\n", (long long int)-9223372036854775807 - 1);
	return (0);
}
