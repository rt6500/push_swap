/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 10:59:35 by rseki             #+#    #+#             */
/*   Updated: 2024/06/02 10:39:59 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h" 

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if ((unsigned char) s1[i] != (unsigned char) s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    size_t n;
    int result_ft_strncmp, result_strncmp;

    printf("Enter the first string: ");
    scanf("%s", str1);
    
    printf("Enter the second string: ");
    scanf("%s", str2);

    printf("Enter the number of characters to compare: ");
    scanf("%zu", &n);

    // Using custom ft_strncmp
    result_ft_strncmp = ft_strncmp(str1, str2, n);

    // Using standard strncmp
    result_strncmp = strncmp(str1, str2, n);

    // Output the results
    printf("Custom ft_strncmp result: %d\n", result_ft_strncmp);
    printf("Standard strncmp result: %d\n", result_strncmp);

    return 0;
}
*/
