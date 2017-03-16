/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:43:01 by evlad             #+#    #+#             */
/*   Updated: 2017/03/13 17:18:31 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_flag		*init_flag(void)
{
	t_flag	*flag;

	flag = (t_flag*)malloc(sizeof(t_flag));
	flag->diese = 0;
	flag->zero = 0;
	flag->minus = 0;
	flag->plus = 0;
	flag->min_size = 0;
	flag->precision = 0;
	flag->precision_size = 0;
	flag->l = 0;
	flag->ll = 0;
	flag->h = 0;
	flag->hh = 0;
	flag->j = 0;
	flag->z = 0;
	return (flag);
}
