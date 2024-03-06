/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:07:21 by gsims             #+#    #+#             */
/*   Updated: 2023/10/18 13:49:40 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const void	*src, size_t	n)
{
	unsigned char			*d;
	unsigned const char		*s;
	size_t					i;

	if (!dst && !src)
		return (0);
	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned const char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
/*
int	main()
{
	char	*dst = "";
	const char	*src = "";
	size_t	i = 4;

	ft_memcpy(dst, src, i);
	printf("%s\n", dst);
	return (0);
}*/
