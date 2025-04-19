/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_than_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:37:59 by rseki             #+#    #+#             */
/*   Updated: 2025/04/18 14:54:10 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_all_smaller(t_node *stack_b, int value)
{
	t_node	*cur;
	t_node	*start;

	if (!stack_b)
		return (1);
	cur = stack_b->next;
	start = stack_b;
	while (cur->next != start)
	{
		if (value < cur->rank)
			return (0);
		cur = cur->next;
	}
	if (value < stack_b->rank)
		return (0);
	return (1);
}

t_node	*find_max_under_value(t_node *stack_b, int value)
{
	t_node	*cur;
	t_node	*max_under;

	cur = stack_b->next;
	max_under = NULL;
	while (cur != stack_b)
	{
		if (cur->rank <= value)
		{
			if (!max_under || max_under->rank < cur->rank)
				max_under = cur;
		}
		cur = cur->next;
	}
	return (max_under);
}

int	get_rotation_index(t_node *stack, t_node *target)
{
	int		i;
	t_node	*cur;

	i = 0;
	cur = stack;
	while (cur != target)
	{
		cur = cur->next;
		i++;
	}
	return (i);
}

int	calculate_cost(t_node *a, t_node *b, t_node *to_push, t_node *insert_after)
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;

	ra = get_rotation_index(a, to_push);
	rb = get_rotation_index(b, insert_after);
	rra = get_stack_size(a) - ra;
	rrb = get_stack_size(b) - rb;
	// Use simple cost model: min of rotate or reverse rotate for each
	return ((ra < rra ? ra : rra) + (rb < rrb ? rb : rrb));
}

void	ft_find_best_move(t_node *a, t_node *b, t_node **best_a,
		t_node **best_b)
{
	t_node	*cur;
	t_node	*insert;
	int		min_cost;
	int		cost;

	cur = a;
	min_cost = 2147483647;
	while (cur)
	{
		if (is_all_smaller(b, cur->num) || is_all_bigger(b, cur->num))
			insert = find_max_node(b)->next; // place after max
		else
			insert = find_insert_after(b, cur->num);
		cost = calculate_cost(a, b, cur, insert);
		if (cost < min_cost)
		{
			min_cost = cost;
			*best_a = cur;
			*best_b = insert;
		}
		cur = cur->next;
	}
}

// int	is_ideal_spot(t_node *prev, t_node *current, int value)
// {
// 	return (value < prev->rank && current->rank < value);
// }

// int	find_max_position(t_node *stack)
// {
// 	t_node	*cur;
// 	t_node	*max;
// 	int		rot;
// 	int		i;

// 	max = stack;
// 	cur = stack->next;
// 	rot = 0;
// 	i = 0;
// 	while (cur != stack)
// 	{
// 		i++;
// 		if (max->num < cur->rank)
// 		{
// 			max = cur;
// 			rot = i;
// 		}
// 		cur = cur->next;
// 	}
// 	return (rot);
// }

// if all the ranks in stack_b are smaller than a specific value, it returns 1.

// int	find_place_b(t_node *stack_b, int rank)
// {
// 	int		rot;
// 	t_node	*cur;
// 	t_node	*prev;

// 	rot = 0;
// 	cur = stack_b;
// 	prev = stack_b->prev;
// 	if (!stack_b || stack_b->next == stack_b)
// 		return (0);
// 	if (is_all_smaller(stack_b, rank))
// 	{
// 		return (find_max_position(stack_b));
// 	}
// 	while (!(is_ideal_spot(prev, cur, rank)))
// 	{
// 		write(1, "here\n", 5);
// 		prev = cur;
// 		cur = cur->next;
// 		rot++;
// 		ft_printf("rot: %d\n", rot);
// 		if (cur == stack_b)
// 			break ;
// 	}
// 	return (rot);
// }

// int case_rarb(t_node *stack_a, t_node *stack_b, int rank)
// {
//     int i;

//     i = find_rank_in_b(stack_b, rank);
// }

// void	rotate_ab(t_node *stack_a, t_node *stack_b)
// {
//     int     i;
//     t_node  *tmp;

//     tmp = stack_a;
//     i = case_rarb(stack_a, stack_b, stack_a->rank)
// }

// void	sort_push_to_b_till_3(t_node **stack_a, t_node **stack_b)
// {
// 	int	i;
// 	// t_node	*cur;

//     // ft_printf("check_sorted: %d\n", check_sorted(*stack_a));
//     // ft_printf("check_sorted: %d\n", check_sorted(*stack_b));
//     // while (3 < get_stack_size(*stack_a) && !check_sorted(*stack_a))
//     // {
//     // // cur = *stack_a;
// 	// i = rotate_ab(*stack_a, *stack_b);
// 	// ft_printf("i: %d\n", i);
// 	// }
// }

int	sort_more_than_five(t_node **stack_a, t_node **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	ft_printf("\nAFTER TWO PUSH TO B\n");
	print_nodes(*stack_a, *stack_b);
	ft_printf("find_place_b: %d\n", find_place_b(*stack_b, 40));
	// sort_push_to_b_till_3(stack_a, stack_b);
	// sort_three(stack_a, stack_b);
	return (0);
}
