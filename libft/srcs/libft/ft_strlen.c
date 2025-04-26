/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:59:27 by rseki             #+#    #+#             */
/*   Updated: 2024/06/01 16:43:36 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*
#include <stdio.h>
#include <string.h>

int	main() {
    char *test_strings[] = {
        "Hello",
        "World",
        "1234567"
    };
    int num_test_strings = sizeof(test_strings) / sizeof(test_strings[0]);
    printf("String\t\tft_strlen\tstrlen\n");
    printf("----------------------------------\n");
    for (int i = 0; i < num_test_strings; ++i) {
        size_t strlen_result = strlen(test_strings[i]);
        size_t ft_strlen_result = ft_strlen(test_strings[i]);
        printf("%s\t\t%zu\t\t%zu\n", test_strings[i], //
	ft_strlen_result, strlen_result);
    }
    return 0;
}
*/
