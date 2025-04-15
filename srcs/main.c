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

void	free_stack(t_stack **stack)
{
	t_node	*cur;
	t_node	*next;

	if (!*stack || !stack)
		return ;
	if (!(*stack)->top)
	{
		free(*stack);
		*stack = NULL;
		return ;
	}
	cur = (*stack)->top;
	next = cur->next;
	while (next != (*stack)->top)
	{
		free(cur);
		cur = next;
		next = next->next;
	}
	free(cur);
	free(*stack);
	*stack = NULL;
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	// t_node	*stack_a;
	// t_node	*stack_b;

	stack_a = 0;
	stack_b = 0;

	// initial_stack_a(stack_a, argv); // initialization of stack a (filled with elements inserted in arguments)

	// t_node *new_node;
	// new_node = create_node(argv[2]);
	// link_stack(stack_a, new_node); // pointed last node and new node (prev, next)
	if (process_input(argc, argv) == 0)
		build_stack(argc, argv, &stack_a, &stack_b);
	assign_ranks(&stack_a);
	print_stacks(stack_a, stack_b);
	sort_few(&stack_a);
	print_stacks(stack_a, stack_b);
	// push(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);
	free_stack(&stack_b);
	free_stack(&stack_a);
	return (0);
}

// void link_stack(t_node *stack, t_node *new_node)
// {
// 	t_node *last_node;

// 	last_node = node_last(stack);

// 	last_node -> next = new_node;
// 	new_node -> prev = last_node;
// }
