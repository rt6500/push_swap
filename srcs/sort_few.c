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

int	sort_three(t_stack **stack)
{
	if ((*stack)->top->num > (*stack)->top->next->num)
		sa(stack);
	return (0);
}

int	sort_two(t_stack **stack)
{
	if ((*stack)->top->num > (*stack)->top->next->num)
		sa(stack);
	return (0);
}

int	count_nodes(t_stack *stack)
{
	t_node	*cur;
	int	count;

	count = 1;
	cur = NULL;
	if (!stack)
		return (0);
	cur = stack->top->next;
	while (cur != stack->top)
	{
		cur = cur->next;
		count++;
	}
	ft_printf("The number of nodes: %d\n", count);
	return (count);
}

int	sort_few(t_stack **stack)
{
	int	count;

	count = count_nodes(*stack);
	if (count <= 1)
		return (1);
	else if (count == 2)
		sort_two(stack);
	return (0);
}
