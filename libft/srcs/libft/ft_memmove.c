/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:06:43 by rseki             #+#    #+#             */
/*   Updated: 2024/06/08 13:56:28 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t n);
static void	*ft_revmemcpy(void *dst, const void *src, size_t n);

static void	*ft_revmemcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dst + n - 1;
	s = src + n - 1;
	while (n-- > 0)
		*d-- = *s--;
	return (d);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (dst < src)
		ft_memcpy(dst, src, n);
	else if (src < dst)
		ft_revmemcpy(dst, src, n);
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>

int main() {
	char src[] = "Hello, World!";
	char dest_ft[10];
	char dest_std[10];

	ft_bzero(dest_ft, ft_strlen(dest_ft));
	ft_bzero(dest_std, ft_strlen(dest_std));
    ft_memmove(dest_ft, src, 5);
    memmove(dest_std, src, 5);
    printf("Source string: %s\n", src);
    printf("Copied string using ft_memmove: %s\n", dest_ft);
    printf("Copied string using memmove: %s\n", dest_std);
    return 0;
}
*/
