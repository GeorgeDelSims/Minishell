/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 07:55:29 by gsims             #+#    #+#             */
/*   Updated: 2023/10/11 15:54:57 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
char	basic_func(unsigned int index, char c)
{
	if (index % 2 == 0)
		c = '0';
	return (c);
}
*/

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*res;

	if (s == NULL || f == NULL)
		return (NULL);
	res = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*
int	main()
{
	const char *s = "Hello This sentence won't make any sense in a second";

	printf("%s\n", ft_strmapi(s, basic_func));
	return (0);
}*/
