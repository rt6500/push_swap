/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input_utilis.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 08:02:32 by rseki             #+#    #+#             */
/*   Updated: 2025/04/27 08:02:34 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	has_duplicate(int argc, char **argv)
{
	int		i;
	int		j;
	long	ni;
	long	nj;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		ni = ft_atoi_ps(argv[i]);
		while (j < argc)
		{
			nj = ft_atoi_ps(argv[j]);
			if (ni == nj)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_over_long_long(char *str, int sign)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	i = 0;
	if (len > 19)
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	if (len == 19)
	{
		if ((sign == 1 && ft_strncmp(str, "9223372036854775807", 19) > 0)
			|| (sign == -1 && ft_strncmp(str, "9223372036854775808", 19) > 0))
			return (1);
	}
	return (0);
}

int	is_invalid_number(char *str)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!*str)
		return (1);
	if (is_over_long_long(str, sign))
		return (1);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (1);
		num = num * 10 + (*str - '0');
		str++;
	}
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	return (0);
}

int	is_no_elememt(char **array)
{
	if (!array || !array[0])
		return (1);
	return (0);
}
