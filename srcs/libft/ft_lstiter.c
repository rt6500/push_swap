/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:11:01 by rseki             #+#    #+#             */
/*   Updated: 2024/05/26 15:24:46 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
#include <stdio.h>

void print_content(void *content)
{
    printf("Content: %s\n", (char *)content);
}

int main()
{
    t_list *list = NULL;

    // Create a linked list with three elements
    t_list *node1 = ft_lstnew("Element 1");
    t_list *node2 = ft_lstnew("Element 2");
    t_list *node3 = ft_lstnew("Element 3");

    node1->next = node2;
    node2->next = node3;

    // Set the head of the list
    list = node1;

    // Iterate over the list and print the content of each element
    ft_lstiter(list, &print_content);

    return 0;
}
*/
