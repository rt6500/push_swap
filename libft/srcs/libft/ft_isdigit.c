/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:08:06 by rseki             #+#    #+#             */
/*   Updated: 2024/05/07 21:41:20 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

/*
#include <ctype.h>
#include <stdio.h>

int     main()
{
    char test_chars[] = {'1', 'a', ' ', '9', '!', '5', '@'};
    int num_test_chars = sizeof(test_chars) / sizeof(test_chars[0]);

    printf("Character\tft_isdigit\tisdigit\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < num_test_chars; ++i) {
        printf("%c\t\t%d\t\t%d\n", test_chars[i], //
        ft_isdigit(test_chars[i]), isdigit(test_chars[i]));
    }
    return (0);
}
*/
