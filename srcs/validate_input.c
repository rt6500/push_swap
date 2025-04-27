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

char	**process_two_args(char **argv)
{
	char	**array;
	int		i;

	i = 0;
	array = ft_split(argv[1], ' ');
	if (!array)
	{
		return (NULL);
	}
	if (is_no_elememt(array))
		return (ft_free_char_array(array, -1), NULL);
	while (array[i])
	{
		if (is_invalid_number(array[i]))
			return (ft_free_char_array(array, -1), NULL);
		i++;
	}
	if (has_duplicate(i, array))
		return (ft_free_char_array(array, -1), NULL);
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
