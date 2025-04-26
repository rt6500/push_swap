/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:31:43 by rseki             #+#    #+#             */
/*   Updated: 2024/07/15 15:02:44 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static size_t	ft_len(unsigned long long n, char *base)
{
	size_t				len;
	unsigned long long	base_len;

	len = 1;
	base_len = ft_strlen(base);
	while (base_len <= n)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(unsigned long long n, char *base)
{
	char	*str;
	size_t	num_len;
	size_t	base_len;

	num_len = ft_len(n, base);
	base_len = ft_strlen(base);
	str = ft_calloc((num_len + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (num_len)
	{
		num_len = num_len - 1;
		str[num_len] = base[n % base_len];
		n /= base_len;
	}
	return (str);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    // Test cases
    unsigned long long num1 = 2024;
    unsigned long long num2 = 255;
    unsigned long long num3 = 1023;
    
    char *base2 = "01";                // Binary base
    char *base8 = "01234567";          // Octal base
    char *base10 = "0123456789";       // Decimal base
    char *base16 = "0123456789abcdef"; // Hexadecimal base

    // Testing ft_itoa_base with different bases
    char *result_bin = ft_itoa_base(num1, base2);
    char *result_oct = ft_itoa_base(num1, base8);
    char *result_dec = ft_itoa_base(num1, base10);
    char *result_hex = ft_itoa_base(num1, base16);

    // Printing results
    printf("Number: %llu in Binary: %s\n", num1, result_bin);
    printf("Number: %llu in Octal: %s\n", num1, result_oct);
    printf("Number: %llu in Decimal: %s\n", num1, result_dec);
    printf("Number: %llu in Hexadecimal: %s\n", num1, result_hex);

    // Freeing allocated memory
    free(result_bin);
    free(result_oct);
    free(result_dec);
    free(result_hex);

    // Additional test cases
    result_bin = ft_itoa_base(num2, base2);
    result_oct = ft_itoa_base(num2, base8);
    result_dec = ft_itoa_base(num2, base10);
    result_hex = ft_itoa_base(num2, base16);

    printf("Number: %llu in Binary: %s\n", num2, result_bin);
    printf("Number: %llu in Octal: %s\n", num2, result_oct);
    printf("Number: %llu in Decimal: %s\n", num2, result_dec);
    printf("Number: %llu in Hexadecimal: %s\n", num2, result_hex);

    free(result_bin);
    free(result_oct);
    free(result_dec);
    free(result_hex);

    result_bin = ft_itoa_base(num3, base2);
    result_oct = ft_itoa_base(num3, base8);
    result_dec = ft_itoa_base(num3, base10);
    result_hex = ft_itoa_base(num3, base16);

    printf("Number: %llu in Binary: %s\n", num3, result_bin);
    printf("Number: %llu in Octal: %s\n", num3, result_oct);
    printf("Number: %llu in Decimal: %s\n", num3, result_dec);
    printf("Number: %llu in Hexadecimal: %s\n", num3, result_hex);

    free(result_bin);
    free(result_oct);
    free(result_dec);
    free(result_hex);

    return 0;
}
*/
