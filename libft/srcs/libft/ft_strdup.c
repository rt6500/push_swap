/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 10:34:24 by rseki             #+#    #+#             */
/*   Updated: 2024/06/02 16:29:33 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	size_t	i;

	tmp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (*s1)
	{
		tmp[i] = *s1;
		s1++;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char *test_string = "Hello, World!";
    char *ft_dup_result = ft_strdup(test_string);
	char *std_dup_result = strdup(test_string);

    printf("Original string: %s\n", test_string);
    printf("ft_strdup result: %s\n", ft_dup_result);
    printf("strdup result: %s\n", std_dup_result);

    // Free the allocated memory
    free(ft_dup_result);
    free(std_dup_result);

    return 0;
}
*/
