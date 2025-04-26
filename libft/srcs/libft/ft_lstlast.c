/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:41:03 by rseki             #+#    #+#             */
/*   Updated: 2024/05/26 12:55:39 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_list	*ft_lstlast(t_list *lst);

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
#include <stdio.h>
#include <stdlib.h>

t_list *create_list(int n)
{
    t_list *head = NULL;
    t_list *prev = NULL;

    for (int i = 1; i <= n; i++)
    {
        // Create a new node
        t_list *new_node = ft_lstnew(NULL);
        if (!new_node)
        {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
        // Link the new node to the previous node
        if (prev)
            prev->next = new_node;
        // Update the head of the list if it's the first node
        if (!head)
            head = new_node;
        // Update the previous node pointer
        prev = new_node;
    }
    return head;
}

// Function to free the memory allocated for a linked list
void free_list(t_list *head)
{
    while (head)
    {
        t_list *temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to check if a given node is the last node of the list
int is_last_node(t_list *node, t_list *last_node)
{
    while (node)
    {
        if (node == last_node)
            return 1; // Node is the last node
        node = node->next;
    }
    return 0; // Node is not the last node
}

int main()
{
    // Create a linked list with 5 nodes
    t_list *head = create_list(5);
    // Get the last node of the list
    t_list *last_node = ft_lstlast(head);
    // Check if the returned last node is indeed the last node of the list
    if (is_last_node(head, last_node))
        printf("the last node of the list.\n");
    else
        printf("not the last node of the list.\n");
    // Free the memory allocated for the list
    free_list(head);
    return 0;
}
*/
