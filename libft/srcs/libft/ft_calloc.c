/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:54:26 by rseki             #+#    #+#             */
/*   Updated: 2024/06/02 14:51:49 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stddef.h>
#include <stdlib.h>
#include <limits.h>
*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (size != 0 && count > (SIZE_MAX / size))
		return (NULL);
	tmp = (void *)malloc(count * size);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, count * size);
	return (tmp);
}
/*
#include <stdio.h>
int main() {
    size_t count = 0; // Number of elements
    size_t size = 0; // Size of each element

    // Allocate memory using ft_calloc
    int *ft_array = (int *)ft_calloc(count, size);
    if (!ft_array) {
        printf("ft_calloc failed to allocate memory.\n");
        return 1;
    }

    // Allocate memory using calloc
    int *std_array = (int *)calloc(count, size);
    if (!std_array) {
        printf("calloc failed to allocate memory.\n");
        free(ft_array); // Free the memory allocated by ft_calloc
        return 1;
    }

    // Check if the memory allocated by ft_calloc is initialized to zero
    int ft_all_zero = 1;
    for (size_t i = 0; i < count; i++) {
        if (ft_array[i] != 0) {
            ft_all_zero = 0;
            break;
        }
    }

    // Check if the memory allocated by calloc is initialized to zero
    int std_all_zero = 1;
    for (size_t i = 0; i < count; i++) {
        if (std_array[i] != 0) {
            std_all_zero = 0;
            break;
        }
    }

    // Compare the results
    if (ft_all_zero && std_all_zero) {
        printf("Both ft_calloc and calloc successfully allocated");
		printf("and initialized memory to zero.\n");
    } else {
        printf("Memory initialization failed.\n");
    }

    // Free the allocated memory
    free(ft_array);
    free(std_array);

    return 0;
}
*/
