/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 09:40:25 by gsims             #+#    #+#             */
/*   Updated: 2023/11/15 10:30:50 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printchar(unsigned int num)
{
	char	c;

	c = (char)num;
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char	*s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_printint(int num)
{
	char	*str;
	int		charcount;

	if (num == -2147483648)
	{
		ft_printstr("-2147483648");
		return (11);
	}
	else
	{
		str = ft_itoa(num);
		charcount = ft_printstr(str);
		free(str);
		return (charcount);
	}
}

int	ft_printunsigned(unsigned int num)
{
	int	counter;

	counter = 0;
	if (num == 0)
		return (ft_putchar('0'));
	if (num > 9)
		counter += ft_printunsigned(num / 10);
	ft_putchar((char)(num % 10 + 48));
	counter++;
	return (counter);
}
