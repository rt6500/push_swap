/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utilis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 08:30:24 by rseki             #+#    #+#             */
/*   Updated: 2025/04/17 14:52:57 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_pos_of_rank(t_node *stack, int rank)
{
	t_node	*cur;
	int		pos;

	if (!stack)
		return (-1);
	cur = stack;
	pos = 1;
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

int	find_min(t_node *stack)
{
	int	min;
	t_node	*cur;

	min = stack->num;
	cur = stack;
	while (cur->next != stack)
	{
	if (stack->num < min)
		min = stack->num;
	stack = stack->next;
	}
	return (min);
}

int	find_max(t_node *stack)
{
	int	max;
	t_node	*cur;

	max = stack->num;
	cur = stack;
	while (cur->next != stack)
	{
		if (max < stack->num)
		max = stack->num;
		stack = stack->next;
	}
	return (max);
}
