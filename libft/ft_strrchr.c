/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:16:53 by gsims             #+#    #+#             */
/*   Updated: 2023/10/12 09:02:22 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (c == '\0')
	{
		return ((char *)&s[i]);
	}
	else
	{	
		while (i >= 0)
		{
			if (s[i] == (char)c)
			{
				return ((char *)&s[i]);
			}
			i--;
		}
	}
	return (NULL);
}
/*
int main()
{
	const char	*str = "bonjour";
	int	c = 'b' ;
	char	*ptr;

	ptr = ft_strrchr(str, c);
	printf("%c\n", *ptr);

	return (0);
}*/
