/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 09:32:29 by rseki             #+#    #+#             */
/*   Updated: 2024/05/26 12:21:57 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
/*
#include <stdio.h>
#include <stdlib.h>

// Function to print the contents of a linked list
void print_list(t_list *lst)
{
    while (lst)
    {
        printf("%d -> ", *(int *)(lst->content));
        lst = lst->next;
    }
    printf("NULL\n");
}
*/
void	ft_lstadd_front(t_list **lst, t_list *new);

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
int main()
{
    // Create a linked list with two nodes
    int num1 = 10;
    int num2 = 20;
    t_list *node1 = ft_lstnew(&num1);
    t_list *node2 = ft_lstnew(&num2);
    node1->next = node2; // Link the nodes

    printf("Original list:\n");
    print_list(node1); // Print the original list

    // Add a new node to the front of the list
    int num3 = 30;
    t_list *new_node = ft_lstnew(&num3);
    ft_lstadd_front(&node1, new_node);

    printf("\nList after adding a node to the front:\n");
    print_list(node1); // Print the modified list

    // Free memory
    while (node1)
    {
        t_list *tmp = node1->next;
        free(node1);
        node1 = tmp;
    }

    return 0;
}
*/
