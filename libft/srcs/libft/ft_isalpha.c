/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:07:00 by rseki             #+#    #+#             */
/*   Updated: 2024/05/07 21:40:04 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
		return (1);
	else
		return (0);
}

/*
#include <ctype.h>
#include <stdio.h>

int     main()
{
    char test_chars[] = {'1', 'a', ' ', 'A', '!', '5', '@'};
    int num_test_chars = sizeof(test_chars) / sizeof(test_chars[0]);

    printf("Character\tft_isalpha\tisalpha\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < num_test_chars; ++i) {
        printf("%c\t\t%d\t\t%d\n", test_chars[i], //
        ft_isalpha(test_chars[i]), isalpha(test_chars[i]));
    }
    return (0);
}
*/
