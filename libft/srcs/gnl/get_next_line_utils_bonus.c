/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:17:10 by rseki             #+#    #+#             */
/*   Updated: 2024/09/09 18:18:52 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// size_t	ft_strlen(const char *str)
// {
// 	int	count;

// 	count = 0;
// 	while (*str)
// 	{
// 		count++;
// 		str++;
// 	}
// 	return (count);
// }

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ans;

	i = 0;
	ans = (unsigned char *)s;
	while (i < n)
	{
		ans[i] = 0;
		i++;
	}
}

// void	*ft_calloc(size_t count, size_t size)
// {
// 	void		*tmp;

// 	if (count == 0 || size == 0)
// 		return (malloc(0));
// 	if (size != 0 && count > (SIZE_MAX / size))
// 		return (NULL);
// 	tmp = (void *)malloc(count * size);
// 	if (!tmp)
// 		return (NULL);
// 	ft_bzero(tmp, count * size);
// 	return (tmp);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	size_t	i;

// 	i = 0;
// 	while (1)
// 	{
// 		if (s[i] == (char)c)
// 			return ((char *)(s + i));
// 		if (s[i] == '\0')
// 			break ;
// 		i++;
// 	}
// 	return (NULL);
// }

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = 0;
	return (str);
}
