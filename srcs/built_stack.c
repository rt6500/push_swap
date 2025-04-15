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

void	ft_node_add_back(t_stack **stack, t_node *new)
{
	t_node	*last;

	if (!stack || !new || !(*stack))
		return ;
	if (!(*stack)->top)
	{
		(*stack)->top = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	last = (*stack)->top->prev;
	last->next = new;
	new->prev = last;
	new->next = (*stack)->top;
	(*stack)->top->prev = new;
}

t_stack	*array_to_stack(char **argv, t_stack *stack)
{
	char	**array;
	int		i;
	int		value;
	int		count;

	i = 0;
	array = process_two_args(&count, argv);
	if (!array)
		return (NULL);
	while (i < count)
	{
		value = ft_atoi_ps(array[i]);
		ft_node_add_back(&stack, ft_node_new(value, -1));
		i++;
	}
	if (!stack)
		write(1, "stack is NULL\n", 15);
	free(array);
	return (stack);
}

int	build_stack(int argc, char **argv, t_stack **stack_a, t_stack **stack_b)
{
	// t_stack	*stack_a;
	// t_stack *stack_b;
	t_node	*new_node;
	int		i;

	*stack_a = ft_calloc(1, sizeof(t_stack));
	*stack_b = ft_calloc(1, sizeof(t_stack));
	if (!stack_a || !stack_b)
		return (1);
	write(1, "asdf\n", 5);
	(*stack_a)->top = NULL;
	write(1, "asdf\n", 5);
	(*stack_b)->top = NULL;
	if (argc > 2)
	{
		i = 1;
		while (i < argc)
		{
			new_node = ft_node_new(ft_atoi_ps(argv[i]), i);
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
