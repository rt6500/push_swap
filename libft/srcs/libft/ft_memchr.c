/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:10:04 by rseki             #+#    #+#             */
/*   Updated: 2024/06/01 16:26:42 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		cc;
	const unsigned char	*ss;

	i = 0;
	cc = (unsigned char) c;
	ss = (const unsigned char *) s;
	while (i < n)
	{
		if (ss[i] == cc)
			return ((void *)&ss[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

// ft_memchr 関数のプロトタイプ宣言
void *ft_memchr(const void *s, int c, size_t n);

int main()
{
    const char str[] = "Hello, world!";
    char c = 'o';
    size_t len = strlen(str);

    // 標準ライブラリの memchr を使ったテスト
    char *std_result = memchr(str, c, len);
    if (std_result != NULL)
        printf("Standard memchr: Found '%c' at position %ld\n", \
		c, std_result - str);
    else
        printf("Standard memchr: Character '%c' not found\n", c);
    // 自作の ft_memchr を使ったテスト
    char *ft_result = ft_memchr(str, c, len);
    if (ft_result != NULL)
        printf("Custom ft_memchr: Found '%c' at position %ld\n", \
		c, ft_result - str);
    else
        printf("Custom ft_memchr: Character '%c' not found\n", c);
    // 文字が見つからなかった場合のテスト
    c = 'x';
    std_result = memchr(str, c, len);
    if (std_result != NULL)
        printf("Standard memchr: Found '%c' at position %ld\n", \
		c, std_result - str);
    else
        printf("Standard memchr: Character '%c' not found\n", c);

    ft_result = ft_memchr(str, c, len);
    if (ft_result != NULL)
        printf("Custom ft_memchr: Found '%c' at position %ld\n", \
		c, ft_result - str);
    else
        printf("Custom ft_memchr: Character '%c' not found\n", c);
    return 0;
}
*/
