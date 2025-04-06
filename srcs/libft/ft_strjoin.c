/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:30:48 by rseki             #+#    #+#             */
/*   Updated: 2024/06/08 21:38:59 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp_str;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	tmp_str = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (tmp_str);
}

/*
int main()
{
    // Test cases
    const char *s1 = "Hello";
    const char *s2 = "World";
    const char *expected = "HelloWorld";

    // Test 1: Basic test case
    printf("Test 1:\n");
    printf("Expected: %s\n", expected);
    char *result = ft_strjoin(s1, s2);
    printf("Result: %s\n", result);
    free(result);

    // Test 2: Empty strings
    printf("\nTest 2:\n");
    const char *empty = "";
    printf("Expected: %s\n", expected);
    result = ft_strjoin(empty, empty);
    printf("Result: %s\n", result);
    free(result);

    // Test 3: One empty string
    printf("\nTest 3:\n");
    printf("Expected: %s\n", s1);
    result = ft_strjoin(s1, empty);
    printf("Result: %s\n", result);
    free(result);

    // Test 4: Null strings
    printf("\nTest 4:\n");
    printf("Expected: (null)\n");
    result = ft_strjoin(NULL, NULL);
    printf("Result: %s\n", result);
    free(result);

    // Memory leak checking using valgrind
    // Compile your code with debug symbols: gcc -g your_code.c -o your_program
    // Run valgrind: valgrind --leak-check=full ./your_program

    return 0;
}
*/
