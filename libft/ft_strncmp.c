/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 08:51:39 by gsims             #+#    #+#             */
/*   Updated: 2023/10/12 12:00:24 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char	*s1, const char	*s2, size_t	n)
{
	size_t		i;

	i = 0;
	if (n > 0)
	{
		while (i < n - 1 && s1[i] == s2[i])
		{
			if (s1[i] != '\0')
				i++;
			else
				return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	else
		return (0);
}
/*
int	main()
{
	const char	*s1 = "";
	const char	*s2 = "";
	size_t		n = 2;

	printf("result : %d\n", ft_strncmp(s1, s2, n));
	return (0);
}*/
