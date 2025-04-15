/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:52:01 by rseki             #+#    #+#             */
/*   Updated: 2025/04/15 14:43:17 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	rotate_two(t_stack **stack)
// {
// 	swap(stack);
// }

int	rotate(t_stack **stack)
{
	t_node	*first;
	t_node	*second;

	first = (*stack)->top;
	second = first->next;
	(*stack)->top = second;
	return (0);
}

void	ra(t_stack **stack_a)
{
	if (!rotate(stack_a))
		printf("ra\n");
}

void	rb(t_stack **stack_b)
{
	if (!rotate(stack_b))
		printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (!rotate(stack_a) && !rotate(stack_b))
		printf("rr\n");
}
