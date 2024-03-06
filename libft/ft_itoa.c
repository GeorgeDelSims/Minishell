/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:22:50 by gsims             #+#    #+#             */
/*   Updated: 2023/10/13 13:02:44 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_size(int n)
{
	int	size;

	size = 1;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	size--;
	return (size);
}
/*
char	*ft_itoa(int n)
{
	int			len;
	char		*res;
	const char	*digits = "0123456789";

	len = ft_get_size(n);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res[len] = 0;
	if (n == 0)
		res[0] = '0';
	if (n < 0)
		res[0] = '-';
	while (n)
	{
		if (n > 0)
			res[--len] = digits[n % 10];
		else
			res[--len] = digits[n % 10 * -1];
		n /= 10;
	}
	return (res);
}

int	main()
{
	printf("%s\n", ft_itoa(-423983));
	return (0);
}
*/

char	*ft_loop(char *res, int size, long int num)
{
	while (size--)
	{
		res[size] = (num % 10) + '0';
		num = num / 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	int			size;
	long int	num;
	char		*res;

	num = n;
	size = ft_get_size(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		size++;
		num *= -1;
	}
	res = (char *)malloc(size + 1);
	if (res == NULL)
		return (NULL);
	res[size] = '\0';
	res = ft_loop(res, size, num);
	if (n < 0)
		*res = '-';
	return (res);
}
/*
int	main()
{
	int	i = -54378;

	printf("%s\n", ft_itoa(i));
	return (0);
}*/
