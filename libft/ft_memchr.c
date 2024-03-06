/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:12:50 by gsims             #+#    #+#             */
/*   Updated: 2023/10/12 09:50:01 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*us;

	us = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (us[i] == (unsigned char)c)
			return ((void *)&us[i]);
		i++;
	}
	return (0);
}
/*
int	main()
{
	const char *s = "abcd";
	int	c = 0;
	size_t n = 15;
	void	*ptr;
	
	ptr = ft_memchr(s, c, n);
	printf("%c\n", *(char *)ptr);	
	printf("%p\n", &*(char *)ptr);
	return(0);
}*/
