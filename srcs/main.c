/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:03:09 by rseki             #+#    #+#             */
/*   Updated: 2025/04/11 10:20:49 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


// t_node	*rank_node(t_node **stack, int argc)
// {
// 	int		i;
// 	int		j;
// 	t_node	**node_array;
// 	t_node	*cur;
	
// 	i = 0;
// 	cur = *stack;
// 	node_array = (t_node**)ft_calloc(sizeof(t_node *)* (argc - 1));
// 	while (cur != *stack)
// 	{
// 		node_array[i] = cur;
// 		cur = cur->next;
// 		i++;
// 	}
// 	i = 0;
// 	j = 0;
// 	while ()
// 	{
// 		if (no)
// 	}
// 	return (stack);
// }
void	free_stack(t_stack **stack)
{
	t_node	*cur;
	t_node	*next;

	if (!stack || !*stack)
		return ;
	cur = (*stack)->top;
	next = cur->next;
	while (next != (*stack)->top)
	{
		free(cur);
		cur = next;
		next = next->next;
	}
	free(cur);
	*stack = NULL;
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (process_input(argc, argv) == 0)
		stack_a = build_stack(argc, argv);
	// add_index(stack_a);
	sort_few(&stack_a);
	free_stack(&stack_a);
	return (0);
}
