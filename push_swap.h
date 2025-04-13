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
	int		index;
	int		num;
	int		rank;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
}	t_stack;

//main.c
int		main(int argc, char **argv);
void	free_stack(t_stack **stack);

//store_input.c
int		has_duplicate(int argc, char **argv);
int		is_invalid_number(char *str);
char	**process_two_args(int *argc, char **argv);
int		process_input(int argc, char **argv);

//ft_atoi_ps.c
int		ft_atoi_ps(const char *str);

//build_stack.c
t_node	*ft_node_new(long num, int i);
void	ft_node_add_back(t_stack **stack, t_node *new);
t_stack	*array_to_stack(int *argc, char **argv);
t_stack	*build_stack(int argc, char **argv);

//add_index.c
// int		add_index(t_stack *stack_a);S

//sort_few.c
int		sort_two(t_stack **stack);
int		count_nodes(t_stack *stack);
int		sort_few(t_stack **stack);

//operations.c
void	swap(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

//ft_error.c
void	print_error_and_exit(const char *message);
