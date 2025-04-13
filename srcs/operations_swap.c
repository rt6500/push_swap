/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:52:20 by rseki             #+#    #+#             */
/*   Updated: 2025/04/13 12:52:24 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	swap(t_node **stack)
// {
// 	t_node	*first;
// }

void	swap(t_stack **stack)
{
	int	t_num;
	int	t_index;

	if (!*stack || (*stack)->top->next == (*stack)->top)
		return ;
	t_num = (*stack)->top->num;
	t_index = (*stack)->top->index;
	(*stack)->top->num = (*stack)->top->next->num;
	(*stack)->top->index = (*stack)->top->next->index;
	(*stack)->top->next->num = t_num;
	(*stack)->top->next->index = t_index;
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	printf("ss\n");
}
