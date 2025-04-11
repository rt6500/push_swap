/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:49:48 by rseki             #+#    #+#             */
/*   Updated: 2025/04/11 14:49:49 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void swap(t_node *stack)
{
    int t_num;
    int t_index;

    if (!stack || stack->next == stack)
        return ;
    t_num = stack->num;
    t_index = stack->index;
    stack->num = stack->next->num;
    stack->index = stack->next->index;
    stack->next->num = t_num;
    stack->next->index = t_index;
}
