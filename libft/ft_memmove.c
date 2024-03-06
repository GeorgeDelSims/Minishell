/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:07:37 by gsims             #+#    #+#             */
/*   Updated: 2023/10/18 08:30:06 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//copies len bytes from src to dst
//returns void
void	*ft_memmove(void *dst, const void	*src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	if (!dst && !src)
		return (NULL);
	d = (char *)dst;
	s = (char *)src;
	if (s < d && s + len > d)
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
/*
int	main()
{
	char		*dst = "";
	const char	*src = "";
	size_t		i = 4;

	ft_memcpy(dst, src, i);
	printf("%s\n", dst);
	return (0);
}*/
