/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:03:09 by rseki             #+#    #+#             */
/*   Updated: 2025/04/11 10:20:49 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_node **stack)
{
	t_node	*cur;
	t_node	*next;

	if (!*stack || !stack)
		return ;
	cur = *stack;
	next = cur->next;
	while (next != *stack)
	{
		free(cur);
		cur = next;
		next = next->next;
	}
	free(cur);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = 0;
	stack_b = 0;
	if (validate_input(argc, argv))
		return (0);
	if (build_stack_a(argc, argv, &stack_a))
		return (0);
	assign_ranks(&stack_a);
	do_sort(&stack_a, &stack_b);
	free_stack(&stack_b);
	free_stack(&stack_a);
	return (0);
}
