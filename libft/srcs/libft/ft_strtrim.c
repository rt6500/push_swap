/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:34:30 by rseki             #+#    #+#             */
/*   Updated: 2024/06/02 19:03:25 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) && start <= end)
		start++;
	if (start > end)
		return (ft_strdup(s1 + end + 1));
	while (ft_strchr(set, s1[end]) && end >= 0)
		end--;
	str = malloc(end - start + 2);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[start], end - start + 2);
	return (str);
}
/*
#include <stdio.h>
#include <string.h>

void test_ft_strtrim(const char *s1, const char *set) {
    char *trimmed_str = ft_strtrim(s1, set);
    printf("Original string: '%s'\n", s1);
    printf("Set: '%s'\n", set);
    printf("Trimmed string: '%s'\n\n", trimmed_str);
    free(trimmed_str);
}

int main(void) {
    // Test case : string with leading and trailing characters to be trimmed
    test_ft_strtrim("abcHello World!   ", "abc ");

    // Test case : string with no characters to be trimmed
    test_ft_strtrim("Hello World!", "abc");

    return 0;
}
*/
