/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 08:21:45 by evlad             #+#    #+#             */
/*   Updated: 2017/03/27 18:37:43 by evlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

/*
** --------------------------------------------------------------------------
**								   INCLUDES
** --------------------------------------------------------------------------
*/

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

/*
** --------------------------------------------------------------------------
**								   STRUCTURES
** --------------------------------------------------------------------------
*/

typedef struct		s_flag
{
	int				diese;
	int				zero;
	int				minus;
	int				plus;
	int				width;
	int				precision;
	int				space;
	int				l;
	int				ll;
	int				h;
	int				hh;
	int				j;
	int				z;
	char			converter;

	int				malloc;
}					t_flag;

typedef struct		s_conv
{
	char			*type;
	int				(*function)(char type, t_flag *active, va_list args);
}					t_conv;

/*
** --------------------------------------------------------------------------
**								    BASICS
** --------------------------------------------------------------------------
*/

int					ft_printf(const char *format, ...);
int					formating(const char *format, va_list args);

int					check_size(t_flag *active);
intmax_t			signed_cast(va_list args, t_flag *active);
uintmax_t			unsigned_cast(va_list args, t_flag *active);

/*
** --------------------------------------------------------------------------
**								    FLAGS
** --------------------------------------------------------------------------
*/

t_flag				*init_flag(void);
int					check_flags(const char *flag, t_flag *active);
char				*apply_flags(char *buffer, int length, t_flag *active);

int					apply_diese(t_flag *active);
int					apply_zero(t_flag *active);
char				*apply_plus(char *buffer, t_flag *active);
char				*apply_width(char *buffer, t_flag *active);
char				*apply_space(char *buffer, t_flag *active);
char				*apply_last_flags(char *buffer, int length, t_flag *active);
char				*apply_precision(char *buffer, int length, t_flag *active);
char				*apply_minus(char *buffer, t_flag *active);

/*
** --------------------------------------------------------------------------
**								   CONVERSIONS
** --------------------------------------------------------------------------
*/

int					conv(char type, t_flag *active, va_list args);
int					conv_int(char type, t_flag *active, va_list args);
int					conv_dou(char type, t_flag *active, va_list args);
int					conv_c(char type, t_flag *active, va_list args);
int					conv_s(char type, t_flag *active, va_list args);
int					conv_ws(char type, t_flag *active, va_list args);
int					conv_p(char type, t_flag *active, va_list args);
int					conv_pct(char type, t_flag *active, va_list args);

#endif
