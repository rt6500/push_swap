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

static int	is_top_rank_1_or_2(t_node *stack)
{
	return (stack->rank == 1 || stack->rank == 2);
}

static void	rotate_to_top(t_node **stack_a, int target_rank)
{
	int	pos;

	pos = get_pos_of_rank(*stack_a, target_rank);
	if (pos == 1)
		return ;
	if (pos <= (*stack_a)->count / 2)
		ra(stack_a);
	else
		rra(stack_a);
}

static void	push_two_to_b(t_node **stack_a, t_node **stack_b)
{
	int	pos_1;
	int	pos_2;

	while ((*stack_a)->count > 3)
	{
		if (is_top_rank_1_or_2(*stack_a))
			pb(stack_a, stack_b);
		else
		{
			pos_1 = get_pos_of_rank(*stack_a, 1);
			pos_2 = get_pos_of_rank(*stack_a, 2);
			if (pos_1 > 0)
				rotate_to_top(stack_a, 1);
			else if (pos_2 > 0)
				rotate_to_top(stack_a, 2);
			else
				break ;
			print_nodes(*stack_a, *stack_b);
		}
	}
}

int	sort_five(t_node **stack_a, t_node **stack_b)
{
	push_two_to_b(stack_a, stack_b);
	sort_three(stack_a, stack_b);
	if ((*stack_b)->count == 2 && (*stack_b)->rank < (*stack_b)->next->rank)
		sb(stack_b);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
	return (0);
}
