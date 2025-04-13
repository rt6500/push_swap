/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:52:01 by rseki             #+#    #+#             */
/*   Updated: 2025/04/13 12:52:03 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

// void	rotate(t_node **stack)
// {
// 	int	t_num;
// 	int	t_index;

// 	if (!*stack || (*stack)->prev == *stack)
// 		return ;
// 	t_num = (*stack)->num;
// 	t_index = (*stack)->index;
// 	(*stack)->num = (*stack)->next->num;
// 	(*stack)->index = (*stack)->next->index;

// 	(*stack)->prev->num = t_num;
// 	(*stack)->prev->index = t_index;
// }

// void	ra(t_node **stack_a)
// {
// 	rotate(stack_a);
// 	printf("sa\n");
// }

// void	rb(t_node **stack_b)
// {
// 	rotate(stack_b);
// 	printf("sb\n");
// }

// void	rr(t_node **stack_a, t_node **stack_b)
// {
// 	rotate(stack_a);
// 	rotate(stack_b);
// 	printf("ss\n");
// }