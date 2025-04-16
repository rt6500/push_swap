/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:10:52 by rseki             #+#    #+#             */
/*   Updated: 2024/05/19 12:18:11 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_array(char **array, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (array[i])
			free(array[i]);
		i++;
	}
	free(array);
}

static size_t	ft_def_word_len(char const *s, char c)
{
	size_t	word_len;

	if (!ft_strchr(s, c))
		word_len = ft_strlen(s);
	else
		word_len = ft_strchr(s, c) - s;
	return (word_len);
}

static char	**ft_split_copy(char const *s, char c, char **array)
{
	int		i;
	size_t	word_len;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			word_len = ft_def_word_len(s, c);
			array[i] = ft_substr(s, 0, word_len);
			if (!array[i])
			{
				ft_free_array((void*)array, i);
				return (NULL);
			}
			i++;
			s += word_len;
		}
	}
	array[i] = NULL;
	return (array);
}

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s!= c)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (0);
	array = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!array)
		return (0);
	return (ft_split_copy(s, c, array));
}