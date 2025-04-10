/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:17:25 by rseki             #+#    #+#             */
/*   Updated: 2025/04/10 12:19:51 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


// t_node	*ft_node_new(long num)
// {
// 	t_node	*new;

// 	new = malloc(sizeof(t_node));
// 	if (!new)
// 		return (ft_printf("Error\nAllocation failed.\n"), 1);
// 	new->num = num;
// 	new->index = -1;
// 	new->next = NULL;
// 	new->prev = NULL;
// 	return (new);
// }

// void	ft_node_add_back(t_node **stack, t_node *new)
// {
// 	t_node	*last;

// 	if (!stack || !new)
// 		return ;
// 	if (!*stack)
// 	{
// 		*stack = new;
// 		new->next = new;
// 		new->prev = new;
// 		return ;
// 	}
// 	last = (*stack)->prev;
// 	last->next = new;
// 	new->prev = last;
// 	new->next = *stack;
// 	(*stack)->prev = new;
// }

// void	free_stack(t_node **stack)
// {
// 	t_node	*cur;
// 	t_node	*next;

// 	if (!stack || !*stack)
// 		return ;
// 	cur = *stack;
// 	next = cur->next;
// 	while (next != *stack)
// 	{
// 		free(cur);
// 		cur = next;
// 		next = next->next;
// 	}
// 	free(cur);
// 	*stack = NULL;
// }

int	is_number(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (1);
	while (*str)
	{
		if (*str < '0' || '9' < *str)
			return (1);
		str++;
	}
	return (0);
}

int	check_input(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
		return (ft_printf("Usage: %s num1 num2 ...\n", argv[0]), 1);
	while (i < argc)
	{
		if (is_number(argv[i]) == 1)
			return (ft_printf("Error: Invalid input: %s\n", argv[i]), 1);
		i++;
	}
	return (0);
}
