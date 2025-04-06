/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rseki <rseki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 08:16:07 by rseki             #+#    #+#             */
/*   Updated: 2024/06/08 17:14:21 by rseki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr_intmin(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (1);
	}
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	char			buffer[12];
	unsigned int	i;

	i = 0;
	if (ft_putnbr_intmin(n, fd))
		return ;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i > 0)
		ft_putchar_fd(buffer[--i], fd);
}
/*
int main()
{
    int fd = 1; // Standard output
    ft_putnbr_fd(12345, fd);
    ft_putchar_fd('\n', fd);
    ft_putnbr_fd(-12345, fd);
    ft_putchar_fd('\n', fd);
    ft_putnbr_fd(0, fd);
    ft_putchar_fd('\n', fd);
    ft_putnbr_fd(-2147483648, fd);
    ft_putchar_fd('\n', fd);
    return 0;
}
*/
