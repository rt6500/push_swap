/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:17:25 by rseki             #+#    #+#             */
/*   Updated: 2025/04/10 12:19:51 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	has_duplicate(int argc, char **argv)
{
	int	i;
	int	j;
	long	ni;
	long	nj;

	i = 1;
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

int	is_number(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (1);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (1);
		str++;
	}
	return (0);
}

int	check_input(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
		return (ft_printf("Error\nUsage: %s num1 num2 ...\n", argv[0]), 1);
	while (i < argc)
	{
		if (is_number(argv[i]))
			return (ft_printf("Error\nInvalid input: %s\n", argv[i]), 1);
		i++;
	}
	if (has_duplicate(argc, argv))
		return (ft_printf("Error\nDuplicated number\n"), 1);
	return (0);
}
