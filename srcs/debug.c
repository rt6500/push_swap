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

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cur;
    t_node  *start;

	if (stack_a && stack_a->top)
	{
		cur = stack_a->top;
        start = cur;
		ft_printf("stack_a:\n");
		while (cur)
		{
			ft_printf("%d(%d) -> ", cur->num, cur->rank);
			cur = cur->next;
            if (cur == start)
                break ;
		}
        ft_printf(" (top)\n");
	}
	if (stack_b && stack_b->top)
	{
		cur = stack_b->top;
        start = cur;
		ft_printf("stack:b: \n", stack_b->top->num);
		while (cur)
		{
			ft_printf("%d(%d) -> ", cur->num, cur->rank);
			cur = cur -> next;
            if (cur == start)
                break ;
		}
        ft_printf(" (top)\n");
	}
}
