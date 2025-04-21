/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:49:04 by rseki             #+#    #+#             */
/*   Updated: 2025/04/11 13:49:06 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*array_to_stack(char **argv, t_node *stack)
{
	char	**array;
	int		i;
	int		value;

	i = 0;
	array = process_two_args(argv);
	if (!array)
		return (NULL);
	while (array[i])
	{
		value = ft_atoi_ps(array[i]);
		ft_node_add_back(&stack, ft_node_new(value));
		i++;
	}
	if (!stack)
		write(1, "stack is NULL\n", 15);
	ft_free_char_array(array, -1);
	return (stack);
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

t_node	*ft_node_new(long num)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (ft_printf("Error\nAllocation failed.\n"), NULL);
	new->num = num;
	new->rank = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int	build_stack_a(int argc, char **argv, t_node **stack_a)
{
	t_node	*new_node;
	int		i;

	if (argc > 2)
	{
		i = 1;
		while (i < argc)
		{
			new_node = ft_node_new(ft_atoi_ps(argv[i]));
			if (!new_node)
				return (1);
			ft_node_add_back(stack_a, new_node);
			i++;
		}
	}
	else if (argc == 2)
		*stack_a = array_to_stack(argv, *stack_a);
	return (0);
}
