/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:41:28 by rseki             #+#    #+#             */
/*   Updated: 2024/08/04 14:49:15 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stddef.h>
# include "../../libft.h"

int		ft_printf(const char *fmt, ...);
void	ft_print_str(const char **start, const char **fmt, int *count);
void	ft_input_parser(const char **fmt, va_list *args, int *count);
int		ft_char_fmt(char c);
int		ft_string_fmt(char *str);
int		ft_pointer_fmt(void *str);
int		ft_decimal_fmt(int value);
int		ft_unsigned_decimal_fmt(unsigned int value);
int		ft_hexadecimal_fmt(unsigned int value);
int		ft_uppercase_hexadecimal_fmt(unsigned int value);
int		ft_percent_fmt(char c);

#endif
