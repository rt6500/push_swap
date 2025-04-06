/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_decimal_fmt.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:04:02 by rseki             #+#    #+#             */
/*   Updated: 2024/08/03 16:25:52 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_decimal_fmt(unsigned int value)
{
	size_t	i;
	char	*str;

	str = ft_itoa_base(value, "0123456789");
	i = ft_string_fmt(str);
	free(str);
	return (i);
}
