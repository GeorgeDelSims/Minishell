/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:30:44 by gsims             #+#    #+#             */
/*   Updated: 2023/11/15 10:25:05 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"

int	ft_strlen(const char *s)
{
	int	res;

	res = 0;
	while (s[res] != '\0')
		res++;
	return (res);
}

/*
size_t	ft_strlcpy(char	*dst, const char	*src, size_t	dstsize)
{
	size_t	i;
	size_t	srcsize;

	srcsize = ft_strlen(src);
	if (dstsize > 0)
	{
		i = 0;
		while (i < dstsize && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
		return (srcsize);
	}
	else
		return (0);
}

size_t	ft_strlcat(char *restrict	dst, const char	*src, size_t	dstsize)
{
	size_t	i;
	size_t	j;

	if (dstsize > 0)
	{
		i = 0;
		while (dst[i] != '\0' && i < dstsize)
			i++;
		j = 0;
		while (src[j] != '\0' && i < dstsize)
		{
			dst[i] = src[j];
			j++;
			i++;
		}
		dst[i] = '\0';
		return (ft_strlen(dst) + ft_strlen(src));
	}
	else
		return (0);
}

int	main()
{
	const char	*src = "Hello this is the source string12345";
	char		dst[41] = "424242";
	size_t		value = 13;

	printf("source string: %s\n", src);
	printf("dest string: %s\n", dst);
//	ft_strlcpy(dst, src, value);
//	printf("dest string after strlcpy function: %s\n", dst);
	ft_strlcat(dst, src, value);
	printf("dest string after strlcat function: %s\n", dst);
//	printf("ft_strlcpy result: %zu\n", ft_strlcpy(dst, src, value));
	printf("ft_strlcat result: %zu\n", ft_strlcat(dst, src, value));
	return (0);
}*/
