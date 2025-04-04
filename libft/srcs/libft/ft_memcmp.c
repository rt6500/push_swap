/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:56:34 by rseki             #+#    #+#             */
/*   Updated: 2024/06/01 16:41:13 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*ss1;
	const unsigned char	*ss2;

	i = 0;
	ss1 = (const unsigned char *) s1;
	ss2 = (const unsigned char *) s2;
	while (i < n)
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "street";
    char str2[] = "straat";
    size_t n = 5;

    int result_memcmp = memcmp(str1, str2, n);
    int result_ft_memcmp = ft_memcmp(str1, str2, n);

    printf("Custom ft_memcmp result: %d\n", result_ft_memcmp);
    printf("Standard memcmp result: %d\n", result_memcmp);

    return 0;
}
*/
