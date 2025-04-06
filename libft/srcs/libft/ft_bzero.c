/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:31:07 by rseki             #+#    #+#             */
/*   Updated: 2024/06/01 16:00:44 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*
#include <stdio.h>
#include <string.h> // for bzero

int main() {
    char buffer1[10];
    char buffer2[10];

    // Using bzero
    printf("Before bzero: ");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", buffer1[i]);
    }
    printf("\n");
    bzero(buffer1, sizeof(buffer1));
    printf("After bzero: ");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", buffer1[i]);
    }
    printf("\n");

    // Using ft_bzero
    printf("Before ft_bzero: ");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", buffer2[i]);
    }
    printf("\n");
    ft_bzero(buffer2, sizeof(buffer2));
    printf("After ft_bzero: ");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", buffer2[i]);
    }
    printf("\n");

    return 0;
}
*/
