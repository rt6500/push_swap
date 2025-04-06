/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_fmt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:57:14 by rseki             #+#    #+#             */
/*   Updated: 2024/07/18 15:46:56 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_negative(int *value)
{
	int	i;

	i = 0;
	if (*value == INT_MIN)
	{
		i = 1;
		ft_putchar_fd('-', 1);
		ft_putchar_fd('2', 1);
		*value = 147483648;
		i++;
	}
	else if (*value < 0)
	{
		ft_putchar_fd('-', 1);
		*value *= -1;
		i++;
	}
	return (i);
}

int	ft_decimal_fmt(int value)
{
	int		i;
	char	*str;

	i = ft_is_negative(&value);
	str = ft_itoa_base(value, "0123456789");
	i = i + ft_string_fmt(str);
	free(str);
	return (i);
}
