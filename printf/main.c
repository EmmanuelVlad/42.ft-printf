/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 11:32:48 by evlad             #+#    #+#             */
/*   Updated: 2017/04/07 21:49:18 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WARNING 0
#include "printf.h"
#include <locale.h>

int		main(void)
{
	char	str[] = "printf from scrap!";
	setlocale(LC_ALL, "");

	ft_printf("FT_PRINTF: '%.0p' '%.p' '%p'", 0, 0, 0);
	printf("\n   PRINTF: '%.0p' '%.p' '%p'\n\n", 0, 0, 0);

	ft_printf("FT_PRINTF: '%o'", 9223372036854775807);
	printf("\n   PRINTF: '%o'\n\n", 9223372036854775807);

	ft_printf("FT_PRINTF: '%+C'", 0);
	printf("\n   PRINTF: '%+C'\n\n", 0);

	ft_printf("FT_PRINTF: '%C'", L'😀');
	printf("\n   PRINTF: '%C'\n\n", L'😀');

	ft_printf("FT_PRINTF: '%ls'", L"ظعغػؼ");
	printf("\n   PRINTF: '%ls'\n\n", L"ظعغػؼ");

	printf("FT_PRINTF: {%d}", ft_printf("%C", L'😀'));
	printf("\n  PRINTF:{%d}\n\n", printf("%C", L'😀'));

	printf("FT_PRINTF: {%d}", ft_printf("%ls", L"ظعغػؼ"));
	printf("\n  PRINTF: {%d}\n\n", printf("%ls", L"ظعغػؼ"));

	ft_printf("FT_PRINTF: '%3c'", 0);
	printf("\n   PRINTF: '%3c'\n\n", 0);

	ft_printf("{%d}", ft_printf("%3c", 0));
	printf("{%d}", printf("%3c", 0));

	ft_printf("FT_PRINTF: '% Zoooo'");
	printf("\n   PRINTF: '% Zoooo'\n\n");

	ft_printf("FT_PRINTF: '% c'", 0);
	printf("\n   PRINTF: '% c'\n\n", 0);

	printf("FT_PRINTF: {%d}", ft_printf("% c", 0));
	printf("\n  PRINTF: {%d}\n\n", printf("% c", 0));

	ft_printf("FT_PRINTF: %hhC, %hhC", 0, L'米');
	printf("\n   PRINTF: %hhC, %hhC\n\n", 0, L'米');

	printf("FT_PRINTF: {%d}", ft_printf("%hhC, %hhC", 0, L'米'));
	printf("\n  PRINTF: {%d}\n\n", printf("%hhC, %hhC", 0, L'米'));

	ft_printf("FT_PRINTF: '{%-30S}'", L"我是一只猫。");
	printf("\n   PRINTF: '{%-30S}'\n\n", L"我是一只猫。");

	printf("FT_PRINTF: {%d}", ft_printf("%-30S", L"我是一只猫。"));
	printf("\n   PRINTF: {%d}\n\n", printf("%-30S", L"我是一只猫。"));

	ft_printf("FT_PRINTF: '%S'", NULL);
	printf("\n   PRINTF: '%S'\n\n", NULL);

	ft_printf("FT_PRINTF: '%.5p'", 0);
	printf("\n   PRINTF: '%.5p'\n\n", 0);

	ft_printf("FT_PRINTF: '%2.9p'", 1234);
	printf("\n   PRINTF: '%2.9p'\n\n", 1234);
	
	ft_printf("FT_PRINTF: '%05.c'", 0);
	printf("\n   PRINTF: '%05.c'\n\n", 0);

	ft_printf("FT_PRINTF: '%*d'", 0);
	printf("\n   PRINTF: '%*d'\n\n", 0);

	ft_printf("BONUS (BINARY): '%b'", 7);
	return (0);
}
