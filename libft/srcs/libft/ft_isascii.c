/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:22:59 by rseki             #+#    #+#             */
/*   Updated: 2024/05/05 17:50:28 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	else
		return (0);
}

/*
#include <ctype.h>
#include <stdio.h>

int     main()
{
    char test_chars[] = {'1', 'a', ' ', '!', '@', '\n', '\xFF'};
    int num_test_chars = sizeof(test_chars) / sizeof(test_chars[0]);

    printf("Character\tft_isascii\tisascii\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < num_test_chars; ++i) {
        printf("%c\t\t%d\t\t%d\n", test_chars[i], //
        ft_isascii(test_chars[i]), isascii(test_chars[i]));
    }
    return (0);
}
*/
