/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:49:53 by gsims             #+#    #+#             */
/*   Updated: 2023/10/13 14:13:11 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = (-1) * n;
		}
		if (n < 10)
		{
			c = (char)n + '0';
			ft_putchar_fd(c, fd);
		}
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
	}
}
/*
int main()
{
	int n = 567;

	ft_putnbr_fd(n, 1);
	write(1, "\n", 1);
	return (0);
}*/
