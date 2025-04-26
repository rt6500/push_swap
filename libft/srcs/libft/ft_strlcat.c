/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:12:09 by rseki             #+#    #+#             */
/*   Updated: 2024/06/02 10:05:16 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h" 

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	i = 0;
	if (dstsize <= dst_len)
		return (dstsize + ft_strlen(src));
	while (dst_len + i < dstsize - 1 && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + ft_strlen(src));
}
/*
#include <stdio.h>
#include <string.h>
int main() {
    char dst1[20] = "12345";
    char dst2[20] = "12345";
    char src[] = "12345";
//    size_t size = sizeof(dst1) / sizeof(dst1[0]);
	size_t size = 10;
    int result1 = ft_strlcat(dst1, src, size);
    int result2 = strlcat(dst2, src, size);

    printf("Result of ft_strlcat: %s, Length: %d\n", dst1, result1);
    printf("Result of strlcat: %s, Length: %d\n", dst2, result2);

    if (strcmp(dst1, dst2) == 0 && result1 == result2) {
        printf("Results are the same.\n");
    } else {
        printf("Results are different.\n");
    }

    return 0;
}
*/
