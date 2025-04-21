/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:24:42 by rseki             #+#    #+#             */
/*   Updated: 2025/04/16 13:48:03 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*detach_from_source(t_node **stack_srs)
{
	t_node	*top;

	if (!stack_srs || !*stack_srs)
		return (NULL);
	top = *stack_srs;
	if (top->next == top)
		*stack_srs = NULL;
	else
	{
		*stack_srs = top->next;
		(*stack_srs)->prev = top->prev;
		top->prev->next = *stack_srs;
	}
	top->next = top;
	top->prev = top;
	return (top);
}

void	attach_to_dest(t_node **stack_des, t_node *node)
{
	if (!stack_des || !node)
		return ;
	if (!*stack_des)
	{
		node->next = node;
		node->prev = node;
		*stack_des = node;
		return ;
	}
	else
	{
		node->next = *stack_des;
		node->prev = (*stack_des)->prev;
		(*stack_des)->prev->next = node;
		(*stack_des)->prev = node;
		*stack_des = node;
	}
}

int	push(t_node **stack_srs, t_node **stack_des)
{
	t_node	*node;

	node = detach_from_source(stack_srs);
	if (!node)
		return (1);
	attach_to_dest(stack_des, node);
	return (0);
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	if (!push(stack_b, stack_a))
		printf("pa\n");
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	if (!push(stack_a, stack_b))
		printf("pb\n");
}
