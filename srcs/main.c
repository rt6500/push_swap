/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:03:09 by rseki             #+#    #+#             */
/*   Updated: 2025/04/10 12:20:53 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


// t_node	*build_stack(int argc, char **argv)
// {
// 	t_node	*stack;
//     t_stack *top_stack;

// 	int     i;

//     i = 1;
// 	while (i < argc)
// 	{
//         stack->index = i;
// 		stack->num = ft_atoi_long(argv[i]);
//         if (i == 1)
//         {
//             top_stack->top = stack;
//             stack->prev = NULL;
//         }
//         ft_node_add_back(*stack, ft_node_new(argv[]))
// 	}

// 	i = 1;
// 	ft_node_new(ft_atoi(argv[i]));
// }

int	main(int argc, char **argv)
{
	// t_node	*stack;

    ft_printf("check_input: %d\n", check_input(argc, argv));
	// if (check_input(argc, argv) == 0)
	// 	stack = build_stack(argc, argv);
	// if (!stack)
	// 	return (ft_printf("Error\nFaild to build stack.\n"), 1);
	// while (i < n)
	// {
	// 	array[i] = ft_atoi(argv[i + 1]); 
	// 	ft_printf("array[%d]: %d\n", i, array[i]);
	// 	i++;
	// }
	// write(1, "\n", 1);
	// if (argc == 3)
	// 	command_three(n, array);
	// free_stack(stack);
	return (0);
}
