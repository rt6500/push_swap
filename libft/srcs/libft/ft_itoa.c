/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:52:14 by rseki             #+#    #+#             */
/*   Updated: 2024/06/02 16:05:17 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n);
static int	len_nb(int n);
static void	convert_to_str(char *str, unsigned int nbr, int len, int neg);

static int	len_nb(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	convert_to_str(char *str, unsigned int nbr, int len, int neg)
{
	if (neg)
		str[0] = '-';
	str[len] = '\0';
	while (nbr > 0)
	{
		str[--len] = '0' + (nbr % 10);
		nbr = nbr / 10;
	}
}

char	*ft_itoa(int n)
{
	int				len;
	char			*str;
	unsigned int	nbr;

	len = len_nb(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (n < 0)
		nbr = (unsigned int)(-n);
	else
		nbr = (unsigned int)n;
	convert_to_str(str, nbr, len, n < 0);
	return (str);
}
/*
#include <stdio.h>
#include <stdlib.h>
static int  len_nb(int n)
{
    int len;

    len = 0;
    if (n <= 0)
        len++;
    while (n != 0)
    {
        n = n / 10;
        len++;
    }
    return (len);
}

char    *ft_itoa(int n)
{
    char    *str;
    int     i;

    i = len_nb(n);
    str = (char *)malloc(sizeof(char) * (i + 1));
    if (!str)
        return (NULL);
    str[i--] = '\0';
    if (n == 0)
    {
        str[0] = '0';
        return (str);
    }
    if (n < 0)
        str[0] = '-';
    while (0 != n)
    {
        if (str[0] == '-')
            str[i--] = '0' + -(n % 10);
        else
            str[i--] = '0' + (n % 10);
        n = n / 10;
    }
    return (str);
}int main()
{
    int numbers[] = {123, -456, 0, 789, 42};
    for (unsigned int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++)
    {
        char *str = ft_itoa(numbers[i]);
        if (str)
        {
            printf("Number: %d, String: %s\n", numbers[i], str);
            free(str);
        }
        else
        {
            printf("Memory allocation failed.\n");
        }
    }
    return 0;
}
*/
