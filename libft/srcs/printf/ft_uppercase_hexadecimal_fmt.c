/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uppercase_hexadecimal_fmt.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:07:36 by rseki             #+#    #+#             */
/*   Updated: 2024/08/03 16:25:03 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uppercase_hexadecimal_fmt(unsigned int value)
{
	int		i;
	char	*str;

	str = ft_itoa_base(value, "0123456789ABCDEF");
	i = ft_string_fmt(str);
	free(str);
	return (i);
}
