/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:05:11 by gsims             #+#    #+#             */
/*   Updated: 2023/10/17 19:02:24 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	dest = (char *)malloc((i + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s1, i + 1);
	return (dest);
}
/*
int	main()
{
	char	*src = "hello tings";

	printf("source address : %p\n", &src);
	printf("dest address : %p\n", ft_strdup(src));	
	return (0);	
}*/
