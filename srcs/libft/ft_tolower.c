/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:45:44 by rseki             #+#    #+#             */
/*   Updated: 2024/06/02 13:48:42 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + 32);
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>
int main() {
    char input_char;
    int result_ft_tolower, result_tolower;

    printf("Enter a character: ");
    scanf("%c", &input_char);

    result_ft_tolower = ft_tolower(input_char);
    result_tolower = tolower(input_char);

    printf("Custom ft_tolower result: %c\n", result_ft_tolower);
    printf("Standard tolower result: %c\n", result_tolower);

    return 0;
}
*/
