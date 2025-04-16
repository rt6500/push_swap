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

int	get_pos_of_rank(t_node *stack, int rank)
{
	t_node	*cur;
	int		pos;

	cur = stack;
	pos = 1;
	while (cur)
	{
		if (cur->rank == rank)
			return (pos);
		cur = cur->next;
		pos++;
	}
	return (-1);
}

int	sort_five(t_node **stack_a, t_node **stack_b)
{
	while ((*stack_a)->count > 3)
	{
		if ((*stack_a)->rank == 1 || (*stack_a)->rank == 2)
			pb(stack_a, stack_b);
		else
		{
			if((get_pos_of_rank(*stack_a, 1) <= (*stack_a)->count /2) ||
				get_pos_of_rank(*stack_a, 2) <= (*stack_a)->count /2)
				ra(stack_a);
			else
				rra(stack_a);
		}
		// if (pos1 == 2 || pos2 == 2)
		// 	sa(stack_a);
		// else if (pos1 == 3 || pos2 == 3)
		// {
		// 	sa(stack_a);
		// 	sa(stack_a);
		// }
		// else if (pos1 == 4 || pos2 == 4)
		// {
		// 	rra(stack_a);
		// 	rra(stack_a);
		// }
		// else if (pos1 == 5 || pos2 == 5)
		// 	rra(stack_a);
		// pb(stack_a, stack_b);
	}
	// sort_three(stack_a, stack_b);
	return (0);
}

int	sort_four(t_node **stack_a, t_node **stack_b)
{
	int	pos;

	pos = get_pos_of_rank(*stack_a, 1);
	ft_printf("pos: %d\n", pos);
	if (pos == 1) // 1, X, X, X
		pb(stack_a, stack_b);
	else if (pos == 2)
	{
		sa(stack_a);
		pb(stack_a, stack_b);
	}
	else if (pos == 3)
	{
		rra(stack_a);
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	// assign_ranks(stack_a);
	sort_three(stack_a, stack_b);
	pa(stack_b, stack_a);
	return (0);
}

// int	sort_three(t_node **stack)
// {
// 	t_node	*first;
// 	t_node	*second;
// 	t_node	*third;

// 	first = *stack;
// 	second = first->next;
// 	third = second->next;
// 	if (first->rank == 2 && second->rank == 1 && third->rank == 3)
// 		sa(stack);
// 	else if (first->rank == 3 && second->rank == 1 && third->rank == 2)
// 		ra(stack);

// 	else if (first->rank == 2 && second->rank == 3 && third->rank == 1)
// 		rra(stack);
// 	else if (first->rank == 1 && second->rank == 3 && third->rank == 2)
// 	{
// 		rra(stack);
// 		sa(stack);
// 	}
// 	else if (first->rank == 3 && second->rank == 2 && third->rank == 1)
// 	{
// 		ra(stack);
// 		sa(stack);
// 	}
// 	return (0);
// }
static void	get_normalized_ranks(t_node **stack_a, t_node **stack_b, int r[3])
{
	int	size;

	if (!*stack_b)
		size = (*stack_a)->count;
	else
		size = (*stack_a)->count + (*stack_b)->count;
	r[0] = (*stack_a)->rank - size + 3;
	r[1] = (*stack_a)->next->rank - size + 3;
	r[2] = (*stack_a)->prev->rank - size + 3;
}

int	sort_three(t_node **stack_a, t_node **stack_b)
{
	int r[3];

	get_normalized_ranks(stack_a, stack_b, r);
	if (r[0] < r[2] && r[2] < r[1]) // 1 3 2
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (r[1] < r[0] && r[0] < r[2]) // 2 1 3
		sa(stack_a);
	else if (r[2] < r[0] && r[0] < r[1]) // 2 3 1
		rra(stack_a);
	else if (r[1] < r[2] && r[2] < r[0])// 3 1 2
		ra(stack_a);
	else if (r[2] < r[1] && r[1] < r[0])// 3 2 1 ->2 1 3
	{
		ra(stack_a);
		sa(stack_a);
	}
	return (0);
}

int	sort_two(t_node **stack)
{
	if ((*stack)->rank > (*stack)->next->rank)
		ra(stack);
	return (0);
}

int	sort_few(t_node **stack_a, t_node **stack_b)
{
	if ((*stack_a)->count <= 1)
		return (1);
	else if ((*stack_a)->count == 2)
		sort_two(stack_a);
	else if ((*stack_a)->count == 3)
		sort_three(stack_a, stack_b);
	else if ((*stack_a)->count == 4)
		sort_four(stack_a, stack_b);
	else if ((*stack_a)->count == 5)
		sort_five(stack_a, stack_b);
	return (0);
}
