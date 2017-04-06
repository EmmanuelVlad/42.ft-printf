/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:09:34 by evlad             #+#    #+#             */
/*   Updated: 2017/04/06 22:38:16 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		conv_dou(char type, t_flag *active, va_list args, t_length *len)
{
	if (type == 'D')
		type = 'd';
	else if (type == 'O')
		type = 'o';
	else if (type == 'U')
		type = 'u';
	active->l = 1;
	return (conv_int(type, active, args, len));
}

int		conv_c(char type, t_flag *active, va_list args, t_length *len)
{
	char	*str;

	str = ft_strnew(2);
	active->first_malloc = 1;
	str[0] = (unsigned char)va_arg(args, int);
	str[1] = '\0';
	active->converter = type;
	apply_flags(str, 1, active, len);
	return (1);
}

int		conv_ws(char type, t_flag *active, va_list args, t_length *len)
{
	if (type && active && args && len)
		return (1);
	return (0);
}

int		conv_p(char type, t_flag *active, va_list args, t_length *len)
{
	void		*ptr;
	uintptr_t	ptrint;
	char		*address;
	char		*str;

	ptr = va_arg(args, void*);
	ptrint = (uintptr_t)ptr;
	address = ft_itoa_base_uint(ptrint, 16);
	str = ft_strnew(ft_strlen(address) + 3);
	ft_strcpy(str, "0x");
	ft_strcat(str, address);
	free(address);
	active->converter = type;
	active->first_malloc = 1;
	apply_flags(str, ft_strlen(str), active, len);
	return (1);
}

int		conv_pct(char type, t_flag *active, va_list args, t_length *len)
{
	(void)type;
	(void)args;
	active->converter = '%';
	apply_flags("%\0", 1, active, len);
	return (1);
}
