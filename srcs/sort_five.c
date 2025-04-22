/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 08:33:37 by rseki             #+#    #+#             */
/*   Updated: 2025/04/17 11:25:43 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_two_to_b(t_node **a, t_node **b)
{
	int	pos;

	while (get_stack_size(*a) > 3)
	{
		pos = get_pos_of_rank(*a, 0);
		while ((*a)->rank != 0 && (*a)->rank != 1)
		{
			pos = get_pos_of_rank(*a, 0);
			if (pos <= get_stack_size(*a) / 2)
				ra(a);
			else
				rra(a);
		}
		pb(a, b);
	}
}

int	sort_five(t_node **stack_a, t_node **stack_b)
{
	push_two_to_b(stack_a, stack_b);
	sort_three(stack_a, stack_b);
	if (get_stack_size(*stack_b) == 2
		&& (*stack_b)->rank < (*stack_b)->next->rank)
		sb(stack_b);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
	return (0);
}
