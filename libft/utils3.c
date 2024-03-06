/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:46:52 by gsims             #+#    #+#             */
/*   Updated: 2023/11/15 10:31:21 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countint(int num)
{
	int	i;

	i = 1;
	if (num < 0)
	{
		i++;
		num *= -1;
	}
	while (num > 9)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int	ft_printptr(unsigned long long num)
{
	int	res;

	res = write(1, "0x", 2);
	res += ft_countint_hex((unsigned long long)num);
	ft_putptr(num);
	return (res);
}

void	ft_putptr(unsigned long long num)
{
	if (num < 16)
		ft_printchar_hex((unsigned int)num);
	if (num >= 16)
	{
		ft_putptr(num / 16);
		ft_putptr(num % 16);
	}
}

int	ft_countint_hex(unsigned long long num)
{
	int	i;

	i = 1;
	while (num >= 16)
	{
		num /= 16;
		i++;
	}
	return (i);
}
