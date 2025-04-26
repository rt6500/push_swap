/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:35:21 by rseki             #+#    #+#             */
/*   Updated: 2024/05/26 14:56:05 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next;

	current = *lst;
	if (lst == NULL || del == NULL)
		return ;
	while (current != NULL)
	{
		next = current->next;
		del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}
/*
#include <stdio.h>
#include <stdlib.h>

void delete_content(void *content) {
    free(content);
}

// Sample function to create a new list node
t_list *ft_lstnew(void *content) {
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    if (new_node == NULL)
        return NULL;
    new_node->content = content;
    new_node->next = NULL;
    return new_node;
}

// Function to print the content of a linked list
void print_list(t_list *head) {
    printf("List content: ");
    while (head) {
        printf("%d -> ", *(int *)head->content);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Create a sample linked list
    t_list *node1 = ft_lstnew((void *)malloc(sizeof(int)));
    t_list *node2 = ft_lstnew((void *)malloc(sizeof(int)));
    t_list *node3 = ft_lstnew((void *)malloc(sizeof(int)));

    *(int *)node1->content = 1;
    *(int *)node2->content = 2;
    *(int *)node3->content = 3;

    node1->next = node2;
    node2->next = node3;

    // Print the list before clearing
    printf("List before clearing:\n");
    print_list(node1);

    // Clear the list
    ft_lstclear(&node1, delete_content);

    // Print the list after clearing
    printf("List after clearing:\n");
    print_list(node1); // This should print "List content: NULL"

    return 0;
}
*/
