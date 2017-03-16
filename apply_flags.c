/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:34:53 by evlad             #+#    #+#             */
/*   Updated: 2017/03/16 18:40:02 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	apply_flags(char type, char *buffer, int len, t_flag *active)
{
	apply_first_flags(type, buffer, len, active);
	apply_last_flags(type, buffer, len, active);
	free(buffer);
	free(active);
}
