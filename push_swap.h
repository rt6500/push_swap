/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:07:57 by rseki             #+#    #+#             */
/*   Updated: 2025/04/10 12:10:35 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //malloc
#include <unistd.h> //write
#include <stdio.h> //printf
#include <limits.h> //LONG_MIN LONG_MAX
#include "libft/libft.h"
#include "libft/srcs/gnl/get_next_line.h"
#include "libft/srcs/printf/ft_printf.h"

// typedef struct s_node
// {
// 	long		index;
// 	long		num;
// 	struct s_node	*prev;
// 	struct s_node	*next;
// }	t_node;

// typedef struct s_stack
// {
// 	t_node	*top;
// }	t_stack;

//main.c
int	main(int argc, char **argv);

//store_input.c
int	check_input(int argc, char **argv);
