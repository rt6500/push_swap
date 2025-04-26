/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:52:02 by rseki             #+#    #+#             */
/*   Updated: 2024/06/02 18:33:03 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strchr(const char *s, size_t c)
{
	size_t	i;
	char	cc;

	cc = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *) &s[i]);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main() {
    char input_string[100];
    char input_char;
    char *result_ft_strchr, *result_strchr;

    printf("Enter a string: ");
    scanf("%s", input_string);
    printf("Enter a character to search for: ");
    scanf(" %c", &input_char);

    result_ft_strchr = ft_strchr(input_string, input_char);
    result_strchr = strchr(input_string, input_char);
    printf("Custom fit_strchr result: %s\n", //
	result_ft_strchr ? result_ft_strchr : "NULL");
    printf("Standard strchr result: %s\n", //
	result_strchr ? result_strchr : "NULL");
    return 0;
}
*/
