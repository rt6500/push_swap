/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:16:26 by rseki             #+#    #+#             */
/*   Updated: 2024/06/08 17:31:31 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		while (i + j < len && haystack[i + j] == needle[j] && haystack[i + j])
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)haystack + i);
		}
		i++;
		j = 0;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
#include <stddef.h>

// Assuming ft_strnstr is defined as previously described

int main() {
    // Test case 1: Needle is found within the haystack
    const char *haystack1 = "Hello, World!";
    const char *needle1 = "World";
    size_t len1 = strlen(haystack1);
    char *result1 = ft_strnstr(haystack1, needle1, len1);
    char *result2 = strnstr(haystack1, needle1, len1);
    printf("Test 1: ft_strnstr = %s, strnstr = %s\n", result1, result2);

    // Test case 2: Needle is not found within the haystack
    const char *haystack2 = "Hello, World!";
    const char *needle2 = "Universe";
    size_t len2 = strlen(haystack2);
    char *result3 = ft_strnstr(haystack2, needle2, len2);
    char *result4 = strnstr(haystack2, needle2, len2);
    printf("Test 2: ft_strnstr = %s, strnstr = %s\n", result3, result4);

    // Test case 3: Needle is at the beginning of the haystack
    const char *haystack3 = "Hello, World!";
    const char *needle3 = "Hello";
    size_t len3 = strlen(haystack3);
    char *result5 = ft_strnstr(haystack3, needle3, len3);
    char *result6 = strnstr(haystack3, needle3, len3);
    printf("Test 3: ft_strnstr = %s, strnstr = %s\n", result5, result6);

    // Test case 4: Needle is empty
    const char *haystack4 = "Hello, World!";
    const char *needle4 = "";
    size_t len4 = strlen(haystack4);
    char *result7 = ft_strnstr(haystack4, needle4, len4);
    char *result8 = strnstr(haystack4, needle4, len4);
    printf("Test 4: ft_strnstr = %s, strnstr = %s\n", result7, result8);

    return 0;
}
*/
