/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:12:39 by rseki             #+#    #+#             */
/*   Updated: 2025/04/15 15:28:51 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array(void **array, int count)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	if (count == -1)
	{
		while (array[i])
			free(array[i++]);
	}
	else
	{
		while (i < count)
			free(array[i]);
	}
	free(array);
}
