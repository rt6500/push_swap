/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:23:19 by rseki             #+#    #+#             */
/*   Updated: 2024/05/26 12:40:51 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
*/
int	ft_lstsize(t_list *lst);

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
/*
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

int main()
{
    // Create a linked list with 5 nodes
    t_list *head = create_list(5);

    // Get the size of the list
    int size = ft_lstsize(head);

    // Print the size of the list
    printf("Size of the list: %d\n", size);

    // Free the memory allocated for the list
    free_list(head);

    return 0;
}
*/
