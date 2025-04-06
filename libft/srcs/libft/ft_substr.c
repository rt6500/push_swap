/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 11:58:45 by rseki             #+#    #+#             */
/*   Updated: 2024/05/12 13:34:14 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ss;
	size_t	i;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) <= start)
		return (ft_strdup(""));
	if ((unsigned int)ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	ss = (char *)malloc(sizeof(char) * (len + 1));
	if (!ss)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ss[i] = s[start + i];
		i++;
	}
	ss[i] = '\0';
	return (ss);
}
/*
char	*ft_strdup(const char *s1)
{
	char	*tmp;
	size_t	i;

	if (s1 == NULL)
		return (NULL);
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
*/
/*
#include <stdlib.h>
#include <stdio.h>
int main() {
    // Test case 1: Normal case with a valid start and length
    char *test1 = ft_substr("Hello, World!", 0, 5);
    printf("Test 1: %s\n", test1);
    free(test1); // Don't forget to free the allocated memory

    // Test case 2: Start index is at the end of the string
    char *test2 = ft_substr("Hello, World!", 13, 5);
    printf("Test 2: %s\n", test2);
    free(test2);

    // Test case 3: Start index is beyond the end of the string
    char *test3 = ft_substr("Hello, World!", 20, 5);
    printf("Test 3: %s\n", test3);
    free(test3);

    // Test case 4: Length is greater than the remaining string length
    char *test4 = ft_substr("Hello, World!", 7, 20);
    printf("Test 4: %s\n", test4);
    free(test4);

    // Test case 5: Start index is 0 and length is 0
    char *test5 = ft_substr("Hello, World!", 0, 0);
    printf("Test 5: %s\n", test5);
    free(test5);

    // Test case 6: Empty string
    char *test6 = ft_substr("", 0, 5);
    printf("Test 6: %s\n", test6);
    free(test6);

    // Test case 7: NULL string
    char *test7 = ft_substr(NULL, 0, 5);
    printf("Test 7: %s\n", test7);
    free(test7);

    return 0;
}
*/
