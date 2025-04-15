/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:33:37 by rseki             #+#    #+#             */
/*   Updated: 2025/04/15 14:37:05 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rev_rotate(t_stack **stack)
{
	t_node	*first;
	t_node	*last;

	first = (*stack)->top;
	last = first->prev;
	(*stack)->top = last;
	return (0);
}

void	rra(t_stack **stack_a)
{
	if (!rev_rotate(stack_a))
		printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	if (!rev_rotate(stack_b))
		printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (!rev_rotate(stack_a) && !rev_rotate(stack_b))
		printf("rrr\n");
}
