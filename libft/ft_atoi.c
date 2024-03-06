/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 08:57:10 by gsims             #+#    #+#             */
/*   Updated: 2023/10/12 13:04:51 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	conditions(const char c)
{
	if (c == '-' || c == '+')
		return (2);
	else if (c >= 9 && c <= 13)
		return (1);
	else if (c == 32)
		return (1);
	else if (ft_isdigit(c) == 1)
		return (3);
	else
		return (0);
}

int	ft_atoi(const char	*str)
{
	int		result;
	int		sign;

	result = 0;
	sign = 1;
	if (conditions(*str) == 0)
		return (0);
	while (conditions(*str) == 1)
			str++;
	if (conditions(*str) == 2)
	{
		if (conditions(*(str + 1)) != 3)
			return (0);
		else
			if (*str == '-')
				sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
/*
int	main()
{
	const char	*str = "-475";

	printf("result : %d\n", ft_atoi(str));
	return (0);
}*/
