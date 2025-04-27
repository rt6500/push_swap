/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_radix_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:37:59 by rseki             #+#    #+#             */
/*   Updated: 2025/04/18 14:54:10 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_one_bit(t_node **a, t_node **b, int bit)
{
	int	size;
	int	i;
	int	num;
	int	bit_val;

	i = 0;
	size = get_stack_size(*a);
	while (i < size)
	{
		num = (*a)->rank;
		bit_val = (num >> bit) & 1;
		if (((num >> bit) & 1) == 0)
			pb(a, b);
		else
			ra(a);
		i++;
	}
}

int	get_max_digit(t_node *stack)
{
	int		max;
	int		digit;
	t_node	*cur;

	if (!stack)
		return (0);
	max = stack->rank;
	cur = stack->next;
	while (cur != stack)
	{
		if (max < cur->rank)
			max = cur->rank;
		cur = cur->next;
	}
	digit = 0;
	while ((max >> digit) != 0)
		digit++;
	return (digit);
}

void	binary_radix_sort(t_node **a, t_node **b)
{
	int	i;
	int	bits;

	bits = get_max_digit(*a);
	i = 0;
	while (i < bits)
	{
		sort_one_bit(a, b, i);
		while (get_stack_size(*b) > 0)
			pa(a, b);
		i++;
	}
}
