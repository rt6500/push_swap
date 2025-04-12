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


t_node *array_to_stack(int *argc, char **argv)
{
	t_node	*stack;
	char	**array;
	int		i;
	int		value;

	i = 0;
	stack = NULL;
	array = process_two_args(argc, argv);
	while (i < *argc)
	{
		value = ft_atoi_ps(array[i]);
		ft_node_add_back(&stack, ft_node_new(value, -1));
		i++;
	}
	return (stack);
}

t_node	*build_stack(int argc, char **argv)
{
	t_node	*a_stack;
	t_node	*new_node;
	int		i;

	a_stack = NULL;
	if (argc > 2)
	{
		i = 1;
		(void)argc;
		while (i < argc)
		{
			new_node = ft_node_new(ft_atoi_ps(argv[i]), i);
			if (!new_node)
				return (NULL);
			ft_node_add_back(&a_stack, new_node);
			i++;
		}
		return (a_stack);
	}
	else if (argc == 2)
		a_stack = array_to_stack(&argc, argv);
	printf("a_stack->index: %d, a_stack->num: %d\n", a_stack->index, a_stack->num);
	printf("a_stack->next->index: %d, a_stack->next->num: %d\n", \
		a_stack->next->index, a_stack->next->num);
	printf("a_stack->prev->index: %d, a_stack->prev->num: %d\n", \
			a_stack->prev->index, a_stack->prev->num);
	return (a_stack);
}

