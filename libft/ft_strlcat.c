/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:12:07 by gsims             #+#    #+#             */
/*   Updated: 2023/10/12 08:48:09 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *restrict	dst, const char	*src, size_t	dstsize)
{
	size_t	i;
	size_t	j;
	size_t	srcsize;
	size_t	d_size;

	i = 0;
	srcsize = ft_strlen(src);
	d_size = ft_strlen(dst);
	if (dstsize > d_size)
	{
		while (dst[i] != '\0' && i < dstsize)
			i++;
		j = 0;
		while (src[j] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[j];
			j++;
			i++;
		}
		dst[i] = '\0';
		return (srcsize + d_size);
	}
	else
		return (srcsize + dstsize);
}

/*
int	main()
{
	const char	*src = "AA";
	char		dst[54] = "BB";
	size_t		dstsize = 4;

	printf("source string: %s\n", src);
	printf("dest string: %s\n", dst);
	printf("ft_strlcat result: %zu\n", ft_strlcat(dst, src, dstsize));
	printf("dest string after strlcat function: %s\n", dst);
	return (0);
}*/
