/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:11:42 by rseki             #+#    #+#             */
/*   Updated: 2024/06/01 15:48:45 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

/*
#include <stdio.h>
#include <string.h> // for memset

int main() {
    char str1[] = "Hello, world!";
    char str2[] = "Hello, world!";
    size_t len = 4;
    int value = 'z';

    printf("Original string: %s\n", str1);
    // Using memset
    memset(str1, value, len);
    printf("After memset:\n%s\n", str1);
    // Using ft_memset
    ft_memset(str2, value, len);
    printf("After ft_memset:\n%s\n", str2);
    return 0;
}
*/
