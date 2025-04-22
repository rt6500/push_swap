/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:27:56 by rseki             #+#    #+#             */
/*   Updated: 2025/04/22 13:25:52 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

#define OVERFLOW_ERROR -1
#define UNDERFLOW_ERROR -2

static int	parse_sign_and_skip(char **str_ptr)
{
	int		sign;
	char	*str;

	sign = 1;
	str = *str_ptr;
	while (*str == '\n' || *str == '\t' || *str == '\r' || *str == '\f'
		|| *str == '\v' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	*str_ptr = str;
	return (sign);
}

int	ft_atoi_long(const char *str)
{
	int			sign;
	long long	result;
	char		*ptr;

	result = 0;
	sign = parse_sign_and_skip(&ptr);
	ptr = (char *)str;
	while (*ptr)
	{
		if (sign == 1)
		{
			if (result > (LONG_MAX - (*ptr - '0')) / 10)
				return (OVERFLOW_ERROR);
		}
		else
		{
			if (result > -(LONG_MIN / 10) || (result == -(LONG_MIN / 10)
					&& (*ptr - '0') > -(LONG_MIN % 10)))
				return (UNDERFLOW_ERROR);
		}
		result = result * 10 + *ptr - '0';
		ptr++;
	}
	return (result * sign);
}
