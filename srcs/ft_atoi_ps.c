/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 09:22:49 by rseki             #+#    #+#             */
/*   Updated: 2025/04/11 10:18:53 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi_ps(const char *str)
{
	int		sign;
	long long int	result;

	sign = 1;
	result = 0;
	while (*str == '\n' || *str == '\t' || *str == '\r' || \
*str == '\f' || *str == '\v' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		result = result * 10 + *str - '0';
		str++;
	}
	if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
		print_error_and_exit("Invalid input: must be an integer\n");
	return ((int)(result * sign));
}
