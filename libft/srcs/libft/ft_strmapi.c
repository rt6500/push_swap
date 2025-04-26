/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:47:51 by rseki             #+#    #+#             */
/*   Updated: 2024/05/19 16:58:29 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
//#include <stdlib.h>
//
//char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
//size_t  ft_strlen(const char *s);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		len;
	char				*res;
	unsigned int		i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!res)
		return (NULL);
	while (s[i])
	{
		res[i] = f(i, (char)s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*
#include <stdio.h>

char test_func(unsigned int index, char c);

int	main()
{
	char	input[] = "";
	char	*result = ft_strmapi(input, &test_func);
	printf("Result: %s\n", result);
	free(result);
	return (0);
}

size_t  ft_strlen(const char *s)
{
        size_t  i;

        i = 0;
        while (s[i])
                i++;
        return (i);
}

char test_func(unsigned int index, char c)
{
	(void)index;
	if ('a' <= c && c <= 'z')
		return (c - 32);
	return (c);	
}
*/
