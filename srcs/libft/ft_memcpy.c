/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:54:16 by rseki             #+#    #+#             */
/*   Updated: 2024/06/08 13:14:01 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (dst == NULL && src == NULL)
		return (NULL);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h> // for memcpy

int main() {
    char src[] = "Hello, world!";
    char dest1[20];
    char dest2[20];

    // Using memcpy
    memcpy(dest1, src, strlen(src) + 1); // Copy src to dest1
    printf("After memcpy: %s\n", dest1);
    // Using ft_memcpy
    ft_memcpy(dest2, src, strlen(src) + 1); // Copy src to dest2
    printf("After ft_memcpy: %s\n", dest2);
    return 0;
}
*/
