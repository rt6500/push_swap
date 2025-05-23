/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:55:29 by rseki             #+#    #+#             */
/*   Updated: 2025/04/15 09:58:20 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// code for debugging. This was not included to the submission.
void	print_nodes(t_node *stack_a, t_node *stack_b)
{
	t_node	*cur;
	t_node	*start;

	if (stack_a)
	{
		cur = stack_a;
		start = cur;
		ft_printf("\nstack_a:[");
		while (cur)
		{
			ft_printf("%d(%d) -> ", cur->num, cur->rank);
			cur = cur->next;
			if (cur == start)
				break ;
		}
		ft_printf(" (top)]\n");
	}
	else
		ft_printf("stack_a:NULL\n");
	if (stack_b)
	{
		cur = stack_b;
		start = cur;
		ft_printf("stack:b: [", stack_b->num);
		while (cur)
		{
			ft_printf("%d(%d) -> ", cur->num, cur->rank);
			cur = cur->next;
			if (cur == start)
				break ;
		}
		ft_printf(" (top)]\n");
	}
	else
		ft_printf("stack_b:NULL\n");
}
