/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:28:13 by rseki             #+#    #+#             */
/*   Updated: 2025/04/11 13:28:14 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int    sort_two(t_node *stack)
{
    if (stack->num > stack->next->num)
        swap(stack);
    return (0);
}

int count_nodes(t_node *stack)
{
    t_node  *cur;
    int     count;

    count = 1;
    if (!stack)
        return (0);
    cur = stack->next;
    while (cur != stack)
    {
        cur = cur->next;
        count++;
    }
    ft_printf("The number of nodes: %d\n", count);
    return (count);
}

int sort_few(t_node *stack)
{
    int count;
    count = count_nodes(stack);
    if (count <= 1)
        return (1);
    else if (count == 2)
        sort_two(stack);
    return (0);
}
