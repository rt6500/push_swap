/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:49:34 by rseki             #+#    #+#             */
/*   Updated: 2024/05/26 10:35:56 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
*/
t_list	*ft_lstnew(void *content);

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*
void test_ft_lstnew()
{
    // Test case 1: Create a node with a simple integer content
    int num = 42;
    t_list *node = ft_lstnew(&num);
    assert(node != NULL);
    assert(node->content == &num);
    assert(*(int *)(node->content) == 42);
    assert(node->next == NULL);
    free(node);

    // Test case 2: Create a node with a string content
    char *str = "Hello, world!";
    node = ft_lstnew(str);
    assert(node != NULL);
    assert(node->content == str);
    assert(strcmp((char *)(node->content), "Hello, world!") == 0);
    assert(node->next == NULL);
    free(node);

    // Test case 3: Create a node with NULL content
    node = ft_lstnew(NULL);
    assert(node != NULL);
    assert(node->content == NULL);
    assert(node->next == NULL);
    free(node);

    printf("All tests passed!\n");
}
int main()
{
    test_ft_lstnew();
    return 0;
}
*/
