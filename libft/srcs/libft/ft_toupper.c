/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:21:55 by rseki             #+#    #+#             */
/*   Updated: 2024/05/05 18:12:36 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c -32);
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>
int main()
{
	char input_char;
	int result_ft_toupper, result_toupper;

	printf("Enter a character: ");
	scanf("%c", &input_char);

	result_ft_toupper = ft_toupper(input_char);
	result_toupper = toupper(input_char);
    
	printf("Custom ft_toupper result: %c\n", result_ft_toupper);
	printf("Standard toupper result: %c\n", result_toupper);

	return 0;
}
*/
