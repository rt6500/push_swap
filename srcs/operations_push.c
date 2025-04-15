/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:24:42 by rseki             #+#    #+#             */
/*   Updated: 2025/04/15 16:24:43 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// int push(t_stack **stack_srs, t_stack **stack_des)
// {
//     // t_node  *des_next;
//     // t_node  *des_last;
//     t_node  *srs_next;
//     t_node  *srs_last;

//     srs_next = (*stack_srs)->top->next;
//     srs_last = (*stack_srs)->top->prev;
//     if ((*stack_des))
//     (*stack_des)->top = (*stack_srs)->top;
//     write(1, "asdf\n", 5);
//     (*stack_srs)->top = srs_next;

//     // des_last = (*stack_des)->top->prev;
//     srs_next = (*stack_srs)->top->next;
//     srs_last = (*stack_srs)->top->prev;
    
//     // (*stack_des)->top->next = des_next;
//     // (*stack_des)->top->next = des_last;
//     (*stack_srs)->top = srs_next;
//     (*stack_srs)->top->prev = srs_last;
//     return (0);
// }