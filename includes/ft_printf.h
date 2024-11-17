/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:04:18 by procha-r          #+#    #+#             */
/*   Updated: 2024/11/17 17:00:09 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# include "libft.h"

typedef struct s_format
{
	int		flag_minus;
	int		flag_zero;
	int		width;
	int		precision;
	char	length_modifier;
	char	specifier;
}	t_format;

int			ft_printf(const char *format, ...);

t_format	parse_format(const char **format);
void		parse_flag(const char **format, t_format *fmt);
void		parse_width(const char **format, t_format *fmt);
void		parse_precision(const char **format, t_format *fmt);
void		parse_specifier(const char **format, t_format *fmt);

int			print_char(char c, t_format *fmt);
int			print_string(const char *str, t_format *fmt);
int			print_int(int n, t_format *fmt);
int			print_long_int(long n, t_format *fmt);
int			print_hex(unsigned int num, int uppercase, t_format *fmt);
int			print_percent(t_format *fmt);
int			print_pointer(void *ptr, t_format *fmt);
int			print_unsigned(unsigned int n, t_format *fmt);

t_format	init_format(void);
void		apply_flags(char **str, t_format *fmt);

#endif
