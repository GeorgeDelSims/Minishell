/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:56:12 by gsims             #+#    #+#             */
/*   Updated: 2023/10/12 11:19:15 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*str1;
	const char	*str2;
	size_t		i;

	i = 0;
	str1 = (const char *)s1;
	str2 = (const char *)s2;
	if (n > 0)
	{
		while (i < n - 1 && str1[i] == str2[i])
			i++;
		return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	}
	else
		return (0);
}
/*
int	main()
{
	const char *str1 = "igfdkj";
	const char *str2 = "asda";
	size_t n = 1;

	printf("%d\n", ft_memcmp(str1, str2, n));
	return (0);
}*/
