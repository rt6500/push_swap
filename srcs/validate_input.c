/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:17:25 by rseki             #+#    #+#             */
/*   Updated: 2025/04/15 11:12:24 by rseki            ###   ########.fr       */
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

int	is_invalid_number(char *str)
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

char	**process_two_args(char **argv)
{
	char	**array;
	int		i;

	i = 0;
	array = ft_split(argv[1], ' ');
	if (!array)
		return (NULL);
	while (array[i])
	{
		if (is_invalid_number(array[i]))
			return (NULL);
		i++;
	}
	if (has_duplicate(i, array))
		return (NULL);
	return (array);
}

int	validate_input(int argc, char **argv)
{
	char	**array;
	int		i;

	i = 1;
	if (argc < 2)
		return (1);
	else if (argc == 2)
	{
		array = process_two_args(argv);
		if (!array)
			return (ft_printf("Error\n"), 1);
		ft_free_char_array(array, -1);
	}
	else
	{
		while (i < argc)
		{
			if (is_invalid_number(argv[i]))
				return (ft_printf("Error\nInvalid input\n"), 1);
			i++;
		}
		if (has_duplicate(argc - 1, argv + 1))
			return (ft_printf("Error\nDuplicated number\n"), 1);
	}
	return (0);
}
