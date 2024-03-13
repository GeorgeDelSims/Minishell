/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:11:02 by gsims             #+#    #+#             */
/*   Updated: 2024/03/13 15:43:17 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char	*dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srcsize;

	i = 0;
	srcsize = ft_strlen(src);
	if (dstsize != 0)
	{
		while (i < dstsize - 1)
		{
			dst[i] = src[i];
			if (dst[i] == '\0')
			{
				return (srcsize);
			}
			i++;
		}
		dst[i] = '\0';
	}
	return (srcsize);
}
/*
int	main()
{
	const char	*src = "lorem ipsum dolor sit amet";
	char		dst[8] = "BBBBB";
	size_t		dstsize  = 0;

	printf("source string: %s\n", src);
	printf("dest string: %s\n", dst);
	printf("dest string address: %p\n", &dst);
	ft_strlcpy(dst, src, dstsize);
	printf("dest string address after function: %p\n", &dst);
	printf("dest string after strlcpy function: %s\n", dst);
	printf("ft_strlcpy result: %zu\n", ft_strlcpy(dst, src, dstsize));
	return (0);
}*/
