/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:59:31 by rseki             #+#    #+#             */
/*   Updated: 2024/06/02 14:53:03 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*str == '\n' || *str == '\t' || *str == '\r' || \
*str == '\f' || *str == '\v' || *str == ' ')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return ((int)(result * sign));
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main() {
    const char *test_cases[] = {
        "9223372036854775807",       
        "9223372036854775808",       
	"9223372036854775809",
	"9223372036854775810",
        "-9223372036854775809",    
        "18446744073709551616",    
        "18446744073709551616",       
        "18446744073709551614",       
        "18446744073709551614",    
        "   -123a45",   
        "-2147483648",       // INT_MIN
        "--12345",      // Leading negative sign
        "+-12345",      // Leading positive and negative signs
        "-+12345",      // Leading negative and positive signs
    };

    size_t num_test_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    for (size_t i = 0; i < num_test_cases; i++) {
        int result_ft_atoi = ft_atoi(test_cases[i]);
        int result_atoi = atoi(test_cases[i]);

        printf("Input *strng: \"%s\"\n", test_cases[i]);
        printf("Custom ft_atoi result: %d\n", result_ft_atoi);
        printf("Standard atoi result: %d\n", result_atoi);

        if (result_ft_atoi == result_atoi)
            printf("Results match!\n\n");
        else
            printf("Results don't match!\n\n");
    }

    return 0;
}
*/
