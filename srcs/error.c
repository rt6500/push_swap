/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 09:34:08 by rseki             #+#    #+#             */
/*   Updated: 2025/04/11 09:48:55 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//For printing an error message to standard output.
void	print_error_and_exit(const char *message)
{
	write(2, "Error\n", 6);
	if (message)
		write(2, message, ft_strlen(message));
	exit (1);
}
