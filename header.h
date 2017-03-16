/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 08:21:45 by evlad             #+#    #+#             */
/*   Updated: 2017/03/16 18:36:34 by evlad            ###   ########.fr       */
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
	int				min_size;
	int				precision;
	int				precision_size;
	int				l;
	int				ll;
	int				h;
	int				hh;
	int				j;
	int				z;
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

/*
** --------------------------------------------------------------------------
**								    FLAGS
** --------------------------------------------------------------------------
*/

t_flag				*init_flag(void);
int					check_flags(const char *flag, t_flag *active);
void				apply_flags(char converter, char *buffer, int length,
						t_flag *active);


/* First flags */
void				apply_first_flags(char converter, char *buffer, int length,
						t_flag *active);
int					apply_flag_diese(char converter);
int					apply_flag_zero(char converter);
int					apply_flag_plus(char converter, char *buffer);
int					apply_flag_min_size(char converter, int length, 
						t_flag *active);
int					apply_flag_l(char converter);
int					apply_flag_ll(char converter);
int					apply_flag_h(char converter);
int					apply_flag_hh(char converter);
int					apply_flag_j(char converter);
int					apply_flag_z(char converter);

/* Last flags */
void				apply_last_flags(char converter, char *buffer, int length,
						t_flag *active);
int					apply_flag_minus(char converter, int length,
						t_flag *active);
int					apply_flag_precision(char converter);
char				*apply_flag_precision_size(char converter, char *buffer,
						t_flag *active);

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
