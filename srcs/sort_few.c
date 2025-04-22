/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:28:13 by rseki             #+#    #+#             */
/*   Updated: 2025/04/13 11:54:13 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	get_normalized_ranks(t_node **stack_a, t_node **stack_b, int r[3])
{
	int	size;

	if (!*stack_b)
		size = get_stack_size(*stack_a);
	else
		size = get_stack_size(*stack_a) + get_stack_size(*stack_b);
	r[0] = (*stack_a)->rank - size + 3;
	r[1] = (*stack_a)->next->rank - size + 3;
	r[2] = (*stack_a)->prev->rank - size + 3;
}

int	sort_four(t_node **stack_a, t_node **stack_b)
{
	int	pos;

	pos = get_pos_of_rank(*stack_a, 0);
	if (pos == 0)
		pb(stack_a, stack_b);
	else if (pos == 1)
	{
		sa(stack_a);
		pb(stack_a, stack_b);
	}
	else if (pos == 2)
	{
		rra(stack_a);
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (pos == 3)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	sort_three(stack_a, stack_b);
	pa(stack_a, stack_b);
	return (0);
}

int	sort_three(t_node **stack_a, t_node **stack_b)
{
	int	r[3];

	get_normalized_ranks(stack_a, stack_b, r);
	if (r[0] < r[2] && r[2] < r[1])
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (r[1] < r[0] && r[0] < r[2])
		sa(stack_a);
	else if (r[2] < r[0] && r[0] < r[1])
		rra(stack_a);
	else if (r[1] < r[2] && r[2] < r[0])
		ra(stack_a);
	else if (r[2] < r[1] && r[1] < r[0])
	{
		sa(stack_a);
		rra(stack_a);
	}
	return (0);
}

int	sort_two(t_node **stack)
{
	if ((*stack)->rank > (*stack)->next->rank)
		ra(stack);
	return (0);
}

int	do_sort(t_node **stack_a, t_node **stack_b)
{
	int	size;

	size = get_stack_size(*stack_a);
	if (size <= 1)
		return (1);
	if (is_sorted(*stack_a))
		return (1);
	if (size == 2)
	{
		sort_two(stack_a);
	}
	else if (size == 3)
		sort_three(stack_a, stack_b);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else if (size > 5)
		binary_radix_sort(stack_a, stack_b);
	return (0);
}
