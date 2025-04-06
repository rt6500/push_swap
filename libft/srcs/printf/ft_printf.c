/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 09:36:31 by rseki             #+#    #+#             */
/*   Updated: 2024/08/12 15:37:39 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *fmt, ...);
void	ft_print_str(const char **start, const char **fmt, int *count);
void	ft_input_parser(const char **fmt, va_list *args, int *count);

int	ft_printf(const char *fmt, ...)
{
	va_list		args;
	int			count;
	const char	*start;

	count = 0;
	va_start(args, fmt);
	if (fmt == NULL)
	{
		count = -1;
		return (-1);
	}
	while (*fmt)
	{
		if (*fmt != '%')
		{
			start = fmt;
			ft_print_str(&start, &fmt, &count);
		}
		else if (*(fmt + 1))
			ft_input_parser(&fmt, &args, &count);
	}
	va_end(args);
	return (count);
}

void	ft_print_str(const char **start, const char **fmt, int *count)
{
	while (**fmt != '%' && **fmt)
		(*fmt)++;
	write(1, *start, *fmt - *start);
	*count += *fmt - *start;
}

void	ft_input_parser(const char **fmt, va_list *args, int *count)
{
	int	k;

	k = 0;
	(*fmt)++;
	if (**fmt == 'c')
		k = ft_char_fmt(va_arg(*args, int));
	else if (**fmt == 's')
		k = ft_string_fmt(va_arg(*args, char *));
	else if (**fmt == 'p')
		k = ft_pointer_fmt(va_arg(*args, void *));
	else if (**fmt == 'd' || **fmt == 'i')
		k = ft_decimal_fmt(va_arg(*args, int));
	else if (**fmt == 'u')
		k = ft_unsigned_decimal_fmt(va_arg(*args, unsigned int));
	else if (**fmt == 'x')
		k = ft_hexadecimal_fmt(va_arg(*args, unsigned int));
	else if (**fmt == 'X')
		k = ft_uppercase_hexadecimal_fmt(va_arg(*args, unsigned int));
	else if (**fmt == '%')
		k = ft_percent_fmt('%');
	(*fmt)++;
	*count += k;
}
