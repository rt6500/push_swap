/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ternary_radix_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:09:44 by rseki             #+#    #+#             */
/*   Updated: 2025/04/21 13:09:45 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_trit(int rank, int pos)
{
	while (pos-- > 0)
		rank /= 3;
	return (rank % 3);
}

int	get_max_digit_ternary(t_node *stack)
{
	int		max;
	int		trits;
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
	trits = 0;
	while (max)
	{
		max /= 3;
		trits++;
	}
	return (trits);
}

void	sort_one_trit(t_node **a, t_node **b, int trit)
{
	int	i;
	int	size;
	int	d;

	// int	d_top_b;
	i = 0;
	size = get_stack_size(*a);
	while (i++ < size)
	{
		d = get_trit((*a)->rank, trit);
		if (d == 0)
		{
			pb(a, b);
			rb(b);
		}
		else if (d == 1)
			pb(a, b);
		else
			ra(a);
	}
}

int	ternary_radix_sort(t_node **a, t_node **b)
{
	int max_digits;

	max_digits = get_max_digit_ternary(*a);
	// ft_printf("max_digits: %d\n", max_digits);
	// ft_printf("bits: %d\n", bits);
	while (0 <= max_digits)
	{
		// print_nodes(*a, *b);
		while (get_stack_size(*b) > 0)
			pa(a, b);
		sort_one_trit(a, b, max_digits);
		// ft_printf("after sort_one_trit:\n");
		// print_nodes(*a, *b);
		// push_back_one_trit(a, b, i);
		while (get_stack_size(*b) > 0)
			pa(a, b);
		// ft_printf("after pushing back:\n");
		// print_nodes(*a, *b);
		max_digits--;
	}
	return (0);
}