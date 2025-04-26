/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:55:53 by rseki             #+#    #+#             */
/*   Updated: 2024/05/26 14:04:08 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_node = *lst;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = new;
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
        int *value = malloc(sizeof(int));
        if (!value)
        {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
        *value = i;

        t_list *new_node = ft_lstnew(value);
        if (!new_node)
        {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
        if (prev)
            prev->next = new_node;
        if (!head)
            head = new_node;
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
		free(temp->content);
		free(temp);
    }
}
// Function to print the content of a linked list
void print_list(t_list *head)
{
    printf("List content: ");
    while (head)
    {
        printf("%d -> ", *(int	*)head->content);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    t_list *head = create_list(3);
	int *value = malloc(sizeof(int));
	if (!value)
	{
		perror("Memory allocationi failed");
		exit(EXIT_FAILURE);
	}
	*value = 4;
	t_list *new_node = ft_lstnew(value);
	if(!new_node)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
    ft_lstadd_back(&head, new_node);
    print_list(head);
	free_list(head);
	return 0;
}
*/
