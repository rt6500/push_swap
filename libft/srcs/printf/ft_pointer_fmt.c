/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_fmt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:02:32 by rseki             #+#    #+#             */
/*   Updated: 2024/08/11 16:07:41 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_prefix(char *str)
{
	int	i;

	i = ft_string_fmt(str);
	return (i);
}

int	ft_pointer_fmt(void *ptr_address)
{
	int				i;
	char			*str;
	unsigned long	address;

	if (ptr_address == NULL)
		i = ft_string_fmt("(nil)");
	else
	{
		address = (unsigned long)ptr_address;
		i = ft_print_prefix("0x");
		str = ft_itoa_base(address, "0123456789abcdef");
		i = i + ft_string_fmt(str);
		free(str);
	}
	return (i);
}
