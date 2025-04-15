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

void	swap_two(t_stack **stack)
{
	t_node	*first;
	t_node	*second;

	first = (*stack)->top;
	second = (*stack)->top->next;
	(*stack)->top = second;
	second->next = first;
	second->prev = first;
	first->next = second;
	first->prev = second;
}

void	swap_more_than_two(t_stack **stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;
	t_node	*last;

	first = (*stack)->top;
	second = first->next;
	third = second->next;
	last = first->prev;
	(*stack)->top = second;
	second->next = first;
	second->prev = last;
	first->prev = second;
	first->next = third;
	last->next = second;
	third->prev = first;
}

int	swap(t_stack **stack)
{
	if (!stack || !(*stack) || !(*stack)->top || !(*stack)->top->next)
		return (1);
	if ((*stack)->count == 2)
		swap_two(stack);
	else
		swap_more_than_two(stack);
	return (0);
}

void	sa(t_stack **stack_a)
{
	if (!swap(stack_a))
		printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	if (!swap(stack_b))
		printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (!swap(stack_a) && !swap(stack_b))
		printf("ss\n");
}
