/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:28:13 by rseki             #+#    #+#             */
/*   Updated: 2025/04/13 11:54:13 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_pos_of_rank(t_stack *stack, int rank)
{
	t_node	*cur;
	int		pos;

	cur = stack->top;
	pos = 1;
	while (cur)
	{
		if (cur->rank == rank)
			return (pos);
		cur = cur->next;
		pos++;
	}
	return (-1);
}

int	sort_five(t_stack **stack)
{
	int pos;

	pos = get_pos_of_rank(*stack, 5);
	ft_printf("pos: %d\n", pos);
	if (pos == 1)
		ra(stack);
	else if (pos == 2)
	{
		sa(stack);
		ra(stack);
	}
	else if (pos == 3)
	{
		rra(stack);
		rra(stack);
	}
	else if (pos == 4)
		rra(stack);
	sort_four(stack);
	return (0);
}

int	sort_four(t_stack **stack)
{
	int	pos;

	pos = get_pos_of_rank(*stack, 4);
	ft_printf("pos: %d\n", pos);
	if (pos == 1)
		ra(stack);
	else if (pos == 2)
	{
		sa(stack);
		ra(stack);
	}
	else if (pos == 3)
		rra(stack);
	sort_three(stack);
	return (0);
}

// int	sort_four(t_stack **stack)
// {
// 	t_node	*first;
// 	t_node	*second;
// 	t_node	*third;
// 	t_node	*fourth;

// 	first = (*stack)->top;
// 	second = first->next;
// 	third = second->next;
// 	fourth = third->next;
// 	if (fourth->rank == 4)
// 		sort_three(stack);
// 	else if (first->rank == 4)
// 	{
// 		ra(stack);
// 		sort_three(stack);
// 	}
// 	return (0);
// }

int	sort_three(t_stack **stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = (*stack)->top;
	second = first->next;
	third = second->next;
	if (first->rank == 2 && second->rank == 1 && third->rank == 3)
		sa(stack);
	else if (first->rank == 3 && second->rank == 1 && third->rank == 2)
		ra(stack);

	else if (first->rank == 2 && second->rank == 3 && third->rank == 1)
		rra(stack);
	else if (first->rank == 1 && second->rank == 3 && third->rank == 2)
	{
		rra(stack);
		sa(stack);
	}
	else if (first->rank == 3 && second->rank == 2 && third->rank == 1)
	{
		ra(stack);
		sa(stack);
	}
	return (0);
}

int	sort_two(t_stack **stack)
{
	if ((*stack)->top->rank > (*stack)->top->next->rank)
		sa(stack);
	return (0);
}

int	count_nodes(t_stack *stack)
{
	t_node	*cur;
	int		count;

	count = 1;
	cur = NULL;
	if (!stack)
		return (0);
	cur = stack->top->next;
	while (cur != stack->top)
	{
		cur = cur->next;
		count++;
	}
	return (count);
}

int	sort_few(t_stack **stack)
{
	(*stack)->count = count_nodes(*stack);
	if ((*stack)->count <= 1)
		return (1);
	else if ((*stack)->count == 2)
		sort_two(stack);
	else if ((*stack)->count == 3)
		sort_three(stack);
	else if ((*stack)->count == 4)
		sort_four(stack);
	else if ((*stack)->count == 5)
		sort_five(stack);
	return (0);
}
