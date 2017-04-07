/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:09:34 by evlad             #+#    #+#             */
/*   Updated: 2017/04/07 21:53:30 by evlad            ###   ########.fr       */
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
	int		length;

	str = NULL;
	active->type = type;
	active->first_malloc = 1;
	if (!check_size(active) && active->type == 'c')
	{
		str = ft_strnew(2);
		str[0] = va_arg(args, int);
		str[1] = '\0';
		length = 1;
	}
	else if (check_size(active) || active->type == 'C')
	{
		str = ft_putwchar(va_arg(args, wchar_t));
		length = ft_strlen(str);
		if (length)
			len->len += length - 1;
		else
			len->len += length;
	}
	apply_flags(str, length, active, len);
	return (length);
}

int		conv_ws(char type, t_flag *active, va_list args, t_length *len)
{
	wchar_t	*wstr;
	char	*str;
	char	*tmp;

	wstr = va_arg(args, wchar_t*);
	str = NULL;
	active->type = type;
	if (wstr == NULL)
	{
		str = "(null)";
		apply_flags(str, 6, active, len);
	}
	else
	{
		str = ft_strnew(ft_wstrlen(wstr) + 1);
		active->first_malloc = 1;
		while (*wstr)
		{
			tmp = ft_putwchar(*wstr++);
			str = ft_strcat(str, tmp);
			free(tmp);
		}
		apply_flags(str, ft_wstrlen(wstr), active, len);
	}
	return (1);
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
	str = ft_strnew(ft_strlen(address) + 2);
	ft_strcpy(str, "0x");
	if (!(ptrint == 0 && active->precision == 0))
		ft_strcat(str, address);
	free(address);
	active->type = type;
	active->first_malloc = 1;
	apply_flags(str, ft_strlen(str), active, len);
	return (1);
}

int		conv_pct(char type, t_flag *active, va_list args, t_length *len)
{
	char	str[2];

	(void)args;
	str[0] = (unsigned char)type;
	str[1] = '\0';
	active->type = type;
	apply_flags(str, 1, active, len);
	return (1);
}
