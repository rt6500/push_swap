/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 10:26:47 by rseki             #+#    #+#             */
/*   Updated: 2024/06/08 19:58:55 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strrchr(const char *s, size_t c)
{
	char	*str;

	str = (char *)s + ft_strlen(s);
	while (s < str && *str != (char)c)
		str--;
	if (*str == (char)c)
		return (str);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
#include <stddef.h>
int main() {
    char input_string[100];
    char input_char;
    char *result_ft_strrchr, *result_strrchr;

    printf("Enter a string: ");
    scanf("%s", input_string);

    printf("Enter a character to search for: ");
    scanf(" %c", &input_char);

    result_ft_strrchr = ft_strrchr(input_string, input_char);
    result_strrchr = strrchr(input_string, input_char);

    printf("Custom ft_strrchr result: %s\n", //
	result_ft_strrchr ? result_ft_strrchr : "NULL");
    printf("Standard strrchr result: %s\n", // 
	result_strrchr ? result_strrchr : "NULL");

    return 0;
}
*/
