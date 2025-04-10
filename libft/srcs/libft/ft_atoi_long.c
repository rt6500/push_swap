/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:27:56 by rseki             #+#    #+#             */
/*   Updated: 2025/04/10 15:14:25 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include "../../libft.h"

#define OVERFLOW_ERROR -1
#define UNDERFLOW_ERROR -2

const char	parse_sign_and_skip(char **str_ptr)
{
	int		sign;
	char	*str;

	sign = 1;
	str = *str_ptr;
	while (*str == '\n' || *str == '\t' || *str == '\r' || \
	*str == '\f' || *str == '\v' || *str == ' ')
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

long	ft_atoi_long(const char *str)
{
	int		sign;
	long	result;
	char	*ptr;

	result = 0;
	sign = parse_sign_and_skip(&ptr);
	ptr = (char *) str;
	while (*ptr)
	{
		if (sign == 1)
		{
			if (result > (LONG_MAX - (*ptr - '0')) / 10)
				return (OVERFLOW_ERROR);
		}
		else
		{
			if (result > -(LONG_MIN / 10) || (result == -(LONG_MIN / 10) && \
				(*ptr - '0') > - (LONG_MIN % 10)))
				return (UNDERFLOW_ERROR);
		}
		result = result * 10 + *ptr - '0';
		ptr++;
	}
	return (result * sign);
}

int main(void)

{
    char *str1 = "-9223372036854775809";
    // char *str2 = "123";
    printf("LONG_MIN = %ld\n", LONG_MIN);
    printf("LONG_MAX = %ld\n", LONG_MAX);
    printf("ft_atoi_long: %ld\n", ft_atoi_long(str1));
    return (0);
}
