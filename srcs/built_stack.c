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

	if (!stack || !new)
		return ;
	// if (!stack)
	// 	write(1, "stack is NULL\n", 15);
	// else if (!*stack)
	// 	write(1, "*stack is NULL\n", 16);
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


t_stack *array_to_stack(int *argc, char **argv)
{
	t_stack	*stack;
	char	**array;
	int		i;
	int		value;
	
	i = 0;
	stack = NULL;
	array = process_two_args(argc, argv);
	write(1, "here_array_to\n", 14);

	while (i < *argc)
	{
		ft_printf("i: %d, array[i]: %d\n", i, array[i]);
		value = ft_atoi_ps(array[i]);
		ft_printf("value: %d\n");
		ft_node_add_back(&stack, ft_node_new(value, -1));
		i++;
	}
	if (!stack)
		write(1, "stack is NULL\n", 15);
	ft_printf("stack->top->num: %d\n", stack->top->num);
	return (stack);
}

t_stack	*build_stack(int argc, char **argv)
{
	t_stack	*stack_a;
	t_node	*new_node;
	int		i;

	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (NULL);
	stack_a->top = NULL;
	if (argc > 2)
	{
		i = 1;
		while (i < argc)
		{
			new_node = ft_node_new(ft_atoi_ps(argv[i]), i);
			if (!new_node)
				return (NULL);
			ft_node_add_back(&stack_a, new_node);
			i++;
		}
	}
	else if (argc == 2)
		stack_a = array_to_stack(&argc, argv);
	if (stack_a->top)
	{
		printf("top->index: %d, top->num: %d\n", stack_a->top->index, stack_a->top->num);
		printf("stack_a->next->index: %d, stack_a->next->num: %d\n", \
			stack_a->top->next->index, stack_a->top->next->num);
		printf("stack_a->prev->index: %d, stack_a->prev->num: %d\n", \
				stack_a->top->prev->index, stack_a->top->prev->num);
	}
	return (stack_a);
}

