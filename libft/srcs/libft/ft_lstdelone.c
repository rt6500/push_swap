/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:13:52 by rseki             #+#    #+#             */
/*   Updated: 2024/05/26 14:35:02 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}
/*
#include <stdlib.h>
#include <stdio.h>

// Sample delete function
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
void print_list(t_list *head) {
    printf("List content: ");
    while (head) {
        printf("%d -> ", *(int *)head->content);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Create a sample node
    int *value = malloc(sizeof(int));
    *value = 42;

    t_list *node = ft_lstnew(value);
    if (!node) {
        perror("Failed to create list node");
        free(value);
        return EXIT_FAILURE;
    }

    printf("List before deletion: ");
    print_list(node);

    // Delete the node using ft_lstdelone
    printf("Deleting the node...\n");
    ft_lstdelone(node, delete_content);

    printf("List after deletion: ");
    print_list(node);

    // After this, node is freed and its content is also freed
    return 0;
}
*/
