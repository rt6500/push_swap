/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_ranks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:05:24 by rseki             #+#    #+#             */
/*   Updated: 2025/04/15 11:09:36 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	assign_ranks(t_stack **stack)
{
	t_node	*cur;
	t_node	*compare;
	int		rank;

	if (!stack || !(*stack)->top)
		return (1);
	cur = (*stack)->top;
	while (1)
	{
		rank = 1;
		compare = (*stack)->top;
		while (1)
		{
			if (compare->num < cur->num)
				rank++;
			compare = compare->next;
			if (compare == (*stack)->top)
				break ;
		}
		cur->rank = rank;
		cur = cur->next;
		if (cur == (*stack)->top)
			break ;
	}
	return (0);
}
