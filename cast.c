/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 18:12:39 by evlad             #+#    #+#             */
/*   Updated: 2017/03/27 18:24:34 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

intmax_t	signed_cast(va_list args, t_flag *active)
{
	intmax_t nb;

	if (active->l)
		nb = (short)va_arg(args, int);
	if (active->ll)
		nb = (char)va_arg(args, int);
	if (active->h)
		nb = va_arg(args, long int);
	if (active->hh)
		nb = va_arg(args, long long int);
	if (active->j)
		nb = va_arg(args, intmax_t);
	if (active->z)
		nb = va_arg(args, size_t);
	return (nb);
}

uintmax_t	unsigned_cast(va_list args, t_flag *active)
{
	uintmax_t nb;

	if (active->l)
		nb = (unsigned short)va_arg(args, unsigned int);
	if (active->ll)
		nb = (unsigned char)va_arg(args, unsigned int);
	if (active->h)
		nb = va_arg(args, unsigned long int);
	if (active->hh)
		nb = va_arg(args, unsigned long long int);
	if (active->j)
		nb = va_arg(args, uintmax_t);
	if (active->z)
		nb = va_arg(args, ssize_t);
	return (nb);
}
