/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 11:32:48 by evlad             #+#    #+#             */
/*   Updated: 2017/04/06 22:21:03 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
	
	ft_printf("FT_PRINTF: '%   %'");
	printf("\n   PRINTF: '%   %'\n\n");

	ft_printf("FT_PRINTF: '%010x'", 542);
	printf("\n   PRINTF: '%010x'\n\n", 542);

	ft_printf("FT_PRINTF: '%#x'", 0);
	printf("\n   PRINTF: '%#x'\n\n", 0);

	ft_printf("FT_PRINTF: '%s'", NULL);
	printf("\n   PRINTF: '%s'\n\n", NULL);
	
	ft_printf("FT_PRINTF: '%5.o' '%5.0o'", 0, 0);
	printf("\n   PRINTF: '%5.o' '%5.0o'\n\n", 0, 0);
	
	ft_printf("FT_PRINTF: '%#08x'", 42);
	printf("\n   PRINTF: '%#08x'\n\n", 42);

	ft_printf("FT_PRINTF: '%+10.5d'", 4242);
	printf("\n   PRINTF: '%+10.5d'\n\n", 4242);

	ft_printf("FT_PRINTF: '%#-8x'", 42);
	printf("\n   PRINTF: '%#-8x'\n\n", 42);

	ft_printf("FT_PRINTF: '%#6o'", 2500);
	printf("\n   PRINTF: '%#6o'\n\n", 2500);

	ft_printf("FT_PRINTF: '%#o'", 2500);
	printf("\n   PRINTF: '%#o'\n\n", 2500);

	ft_printf("FT_PRINTF: '%#08x'", 42);
	printf("\n   PRINTF: '%#08x'\n\n", 42);

	ft_printf("FT_PRINTF: '%00d'", -42);
	printf("\n   PRINTF: '%00d'\n\n", -42);

	ft_printf("FT_PRINTF: '%5x'", 5427);
	printf("\n   PRINTF: '%5x'\n\n", 5427);

	ft_printf("FT_PRINTF: '%5.2x'", 5427);
	printf("\n   PRINTF: '%5.2x'\n\n", 5427);

	ft_printf("FT_PRINTF: '%0+5d'", 42);
	printf("\n   PRINTF: '%0+5d'\n\n", 42);

	ft_printf("FT_PRINTF: '%5.x' '%5.0x'", 0, 0);
	printf("\n   PRINTF: '%5.x' '%5.0x'\n\n", 0, 0);

	ft_printf("FT_PRINTF: '%03.2d'", 0);
	printf("\n   PRINTF: '%03.2d'\n\n", 0);

	ft_printf("FT_PRINTF: '%-+10.5d'", 4242);
	printf("\n   PRINTF: '%-+10.5d'\n\n", 4242);

	ft_printf("FT_PRINTF: '%015u'", (unsigned int)4294967295);
	printf("\n   PRINTF: '%015u'\n\n", (unsigned int)4294967295);

	ft_printf("FT_PRINTF: '% u'", (unsigned int)4294967295);
	printf("\n   PRINTF: '%u'\n\n", (unsigned int)4294967295);

	ft_printf("FT_PRINTF: '%lU'", (unsigned long)4294967296);
	printf("\n   PRINTF: '%lU'\n\n", (unsigned long)4294967296);

	ft_printf("FT_PRINTF: '%3c'", 0);
	printf("\n   PRINTF: '%3c'\n\n", 0);

	ft_printf("FT_PRINTF: '%hU'", 4294967296);
	printf("\n   PRINTF: '%hU'\n\n", 4294967296);

	ft_printf("FT_PRINTF: '%U'", 4294967296);
	printf("\n   PRINTF: '%U'\n\n", 4294967296);

	ft_printf("FT_PRINTF: '%-#6o'", 2500);
	printf("\n   PRINTF: '%-#6o'\n\n", 2500);

	ft_printf("FT_PRINTF: '%.0%'");
	printf("\n   PRINTF: '%.0%'\n\n");

	ft_printf("FT_PRINTF: '%'");
	printf("\n   PRINTF: '%'\n\n");

	ft_printf("FT_PRINTF: '%0 d'", 42);
	printf("\n   PRINTF: '%0 d'\n\n", 42);

	ft_printf("FT_PRINTF: '%lhh'", "2147483647");
	printf("\n   PRINTF: '%lhh'\n\n", "2147483647");

	ft_printf("FT_PRINTF: '%-0+5d'", -42);
	printf("\n   PRINTF: '%-0+5d'\n\n", -42);

	ft_printf("FT_PRINTF: '% Z'", 42);
	printf("\n   PRINTF: '% Z'\n\n", 42);

	ft_printf("FT_PRINTF: '%jhd'", "9223372036854775807");
	printf("\n   PRINTF: '%jhd'\n\n", "9223372036854775807");

	ft_printf("FT_PRINTF: '% Z'", 42);
	printf("\n   PRINTF: '% Z'\n\n", 42);

	printf("FT_PRINT: '%d'", ft_printf("%zj", "9223372036854775807"));
	printf("\n   PRINT: '%d'\n\n", printf("%zj", "9223372036854775807"));

	printf("FT_PRINT: '{%d}'", ft_printf("@main_ftprintf: %#-08+...d", 256));
	printf("\n   PRINT: '{%d}'\n\n", printf("@main_ftprintf: %#-08+...d", 256));
	printf("@main_ftprintf: %#-+08.d", 256);

	//ft_printf("BONUS (BINARY): '%b'", 1337);
	return (0);
}
