/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utilis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 08:30:24 by rseki             #+#    #+#             */
/*   Updated: 2025/04/22 13:30:31 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_sorted(t_node *stack)
{
	t_node	*start;
	int		cur;

	if (!stack || stack->next == stack)
		return (1);
	start = stack;
	cur = stack->rank;
	stack = stack->next;
	while (stack != start)
	{
		if (stack->rank < cur)
			return (0);
		cur = stack->rank;
		stack = stack->next;
	}
	return (1);
}

int	get_stack_size(t_node *stack)
{
	size_t	i;
	t_node	*cur;

	if (!stack)
		return (0);
	i = 1;
	cur = stack;
	while (cur->next && cur->next != stack)
	{
		cur = cur->next;
		i++;
	}
	return (i);
}

int	get_pos_of_rank(t_node *stack, int rank)
{
	t_node	*cur;
	int		pos;

	if (!stack)
		return (-1);
	cur = stack;
	pos = 0;
	while (cur->next != stack)
	{
		if (cur->rank == rank)
			return (pos);
		cur = cur->next;
		pos++;
	}
	if (cur->rank == rank)
		return (pos);
	return (-1);
}

int	is_sorted(t_node *stack)
{
	t_node	*start;

	start = stack;
	if (!stack || !stack->next)
		return (1);
	while ((start != stack->next))
	{
		if (stack->next->rank < stack->rank)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	assign_ranks(t_node **stack)
{
	t_node	*cur;
	t_node	*compare;
	int		rank;

	if (!stack || !*stack)
		return (1);
	cur = *stack;
	while (1)
	{
		rank = 0;
		compare = *stack;
		while (1)
		{
			if (compare->num < cur->num)
				rank++;
			compare = compare->next;
			if (compare == *stack)
				break ;
		}
		cur->rank = rank;
		cur = cur->next;
		if (cur == *stack)
			break ;
	}
	return (0);
}
