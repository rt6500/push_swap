/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:52:20 by rseki             #+#    #+#             */
/*   Updated: 2025/04/15 11:20:05 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_more_than_two(t_node **stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;
	t_node	*last;

	first = *stack;
	second = first->next;
	third = second->next;
	last = first->prev;
	*stack = second;
	second->next = first;
	second->prev = last;
	first->prev = second;
	first->next = third;
	last->next = second;
	third->prev = first;
}

void	swap_two(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	first = *stack;
	second = (*stack)->next;
	*stack = second;
	second->next = first;
	second->prev = first;
	first->next = second;
	first->prev = second;
}

int	swap(t_node **stack)
{
	if (!stack || !(*stack) || !(*stack)->next)
		return (1);
	if ((*stack)->count == 2)
		swap_two(stack);
	else
		swap_more_than_two(stack);
	return (0);
}

void	sa(t_node **stack_a)
{
	if (!swap(stack_a))
		printf("sa\n");
}

void	sb(t_node **stack_b)
{
	if (!swap(stack_b))
		printf("sb\n");
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	if (!swap(stack_a) && !swap(stack_b))
		printf("ss\n");
}
