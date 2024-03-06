/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:06:57 by gsims             #+#    #+#             */
/*   Updated: 2023/11/15 10:31:07 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_printchar_rec(unsigned int num)
{
	unsigned char	c;

	c = num + '0';
	write(1, &c, 1);
}

void	ft_printchar_hex(unsigned int num)
{
	unsigned char	c;

	if (num <= 9)
		ft_printchar_rec((unsigned int)num);
	else if (num > 9)
	{
		c = num - 10 + 'a';
		write(1, &c, 1);
	}	
}

int	ft_printhexa(unsigned int num, char c)
{
	int		counter;
	char	*base;

	counter = 0;
	if (c == 'X')
		base = "0123456789ABCDEF";
	else if (c == 'x')
		base = "0123456789abcdef";
	if (num == 0)
		return (ft_putchar('0'));
	if (num > 15)
		counter += ft_printhexa(num / 16, c);
	counter += ft_putchar((char)base[num % 16]);
	return (counter);
}
