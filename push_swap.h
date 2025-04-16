/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:07:57 by rseki             #+#    #+#             */
/*   Updated: 2025/04/13 15:31:18 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //malloc
#include <unistd.h> //write
#include <stdio.h> //printf
#include <limits.h> //LONG_MIN LONG_MAX
#include "libft/libft.h"
#include "libft/srcs/gnl/get_next_line.h"
#include "libft/srcs/printf/ft_printf.h"

typedef struct s_node
{
	int		num;
	int		rank;
	struct s_node	*prev;
	struct s_node	*next;
	int		count;
}	t_node;

//main.c
int		main(int argc, char **argv);
void	free_stack(t_node **stack);

//validate_input.c
int		has_duplicate(int argc, char **argv);
int		is_invalid_number(char *str);
char	**process_two_args(char **argv);
int		validate_input(int argc, char **argv);

//ft_atoi_ps.c
int		ft_atoi_ps(const char *str);

//build_stack.c
t_node	*ft_node_new(long num);
void	ft_node_add_back(t_node **stack, t_node *new);
t_node	*array_to_stack(char **argv, t_node *stack);
int		build_stack_a(int argc, char **argv, t_node **stack_a);

// //assing_ranks.c
int		assign_ranks(t_node **stack);

// //sort_few.c
int		get_pos_of_rank(t_node *stack, int rank);
int	sort_five(t_node **stack_a, t_node **stack_b);
int		sort_four(t_node **stack_a, t_node **stack_b);
int		sort_three(t_node **stack_a, t_node **stack_b);
int		sort_two(t_node **stack);
int		sort_few(t_node **stack_a, t_node **stack_b);

// //operations_wap.c
void	swap_two(t_node **stack);
void	swap_more_than_two(t_node **stack);
int		swap(t_node **stack);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);

// //operations_rotate.c
int		rotate(t_node **stack);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);

// //operations_rev_rotate.c
int		rev_rotate(t_node **stack);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

// //operations_push.c
t_node	*detach_from_source(t_node **stack_srs);
void	attach_to_dest(t_node **stack_des, t_node *node);

int		push(t_node **stack_srs, t_node **stack_des);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_b, t_node **stack_a);

//ft_error.c
void	print_error_and_exit(const char *message);

// //ft_debug.c
void	print_nodes(t_node *stack_a, t_node *stack_b);

