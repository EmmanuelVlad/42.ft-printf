/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 15:06:27 by evlad             #+#    #+#             */
/*   Updated: 2017/01/30 16:44:47 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	check_flags(const char *flag, t_flag *active)
{
	if (flag[0] == '+')
		active->plus = 1;
	if (flag[0] == ' ')
		active->space = 1;
	if (flag[0] == '#')
		active->diese = 1;
	if (flag[0] == '0')
		active->zero = 1;
	if (flag[0] == '-')
		active->minus = 1;
	if (flag[0] == 'l' && flag[1] != 'l')
		active->l = 1;
	if (flag[0] == 'l' && flag[1] == 'l')
		active->ll = 1;
	if (flag[0] == 'h' && flag[1] != 'h')
		active->h = 1;
	if (flag[0] == 'h' && flag[1] == 'h')
		active->hh = 1;
	if (flag[0] == 'j')
		active->j = 1;
	if (flag[0] == 'z')
		active->z = 1;
}
