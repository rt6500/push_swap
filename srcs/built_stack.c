/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:49:04 by rseki             #+#    #+#             */
/*   Updated: 2025/04/11 13:49:06 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*ft_node_new(long num, int i)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (ft_printf("Error\nAllocation failed.\n"), NULL);
	new->num = num;
	new->index = i;
	new->rank = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_node_add_back(t_node **stack, t_node *new)
{
	t_node	*last;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	last = (*stack)->prev;
	last->next = new;
	new->prev = last;
	new->next = *stack;
	(*stack)->prev = new;
}

t_node	*build_stack(int argc, char **argv)
{
	t_node	*stack;
	t_node	*new_node;
	int		i;

	stack = NULL;
	i = 1;
	(void)argc;
	while (i < argc)
	{
		new_node = ft_node_new(ft_atoi_ps(argv[i]), i);
		if (!new_node)
			return (NULL);
		ft_node_add_back(&stack, new_node);
		i++;
	}
	// printf("stack->index: %d, stack->num: %d\n", stack->index, stack->num);
	// printf("stack->next->index: %d, stack->next->num: %d\n", \
	// 	stack->next->index, stack->next->num);
	// printf("stack->prev->index: %d, stack->prev->num: %d\n", \
	// 		stack->prev->index, stack->prev->num);
	return (stack);
}

