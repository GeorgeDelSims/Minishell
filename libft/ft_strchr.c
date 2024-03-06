/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:42:07 by gsims             #+#    #+#             */
/*   Updated: 2023/11/15 10:24:57 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// Locates character c in string s, returns c or NULL
char	*ft_strchr(const char *s, int c)
{
	char	uc;
	int		i;

	uc = (char)c;
	if (uc == '\0')
	{
		i = ft_strlen(s);
		return ((char *)&s[i]);
	}
	else
	{
		i = 0;
		while (s[i] != '\0')
		{
			if (s[i] == uc)
				return ((char *)&s[i]);
			i++;
		}
		return (NULL);
	}
}

/*
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i != 0)
	{
		if (s[i] == (char)c)
			return ((char *)s);
	}
}


int main()
{
	const char	*str = "Hell";
	int	c = 'l' ;
	char	*ptr;
	
	ptr = ft_strchr(str, c);
	printf("%c\n", *ptr);

	return (0);
}*/
