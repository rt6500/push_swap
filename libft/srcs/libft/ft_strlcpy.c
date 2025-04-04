/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:06:23 by rseki             #+#    #+#             */
/*   Updated: 2024/06/01 18:05:13 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (src[len] != '\0')
		len++;
	if (dstsize > 0)
	{
		i = 0;
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			++i;
		}
		dst[i] = '\0';
	}
	return (len);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char src[] = "Hello,";
	char dst[] = "1234567890";	
    
	unsigned int len_ft = ft_strlcpy(dst, src, 10);
    unsigned int len_std = strlcpy(dst, src, 10);
    printf("ft_strlcpy result: %s\n", dst);
    printf("ft_strlcpy length: %u\n", len_ft);
    printf("strlcpy result: %s\n", dst);
    printf("strlcpy length: %u\n", len_std);
}
*/
