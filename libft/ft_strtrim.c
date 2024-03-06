/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:23:10 by gsims             #+#    #+#             */
/*   Updated: 2023/10/13 08:08:08 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isin(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		len;
	int		i;
	int		j;
	char	*newstr;

	len = ft_strlen(s1);
	i = 0;
	while (i < len && ft_isin(s1[i], set) == 1)
		i++;
	while (len > 0 && ft_isin(s1[len - 1], set) == 1 && len > i)
		len--;
	newstr = (char *)malloc((len - i) + 1);
	if (newstr == NULL)
		return (NULL);
	j = 0;
	while (i < len)
	{
		newstr[j] = s1[i];
		i++;
		j++;
	}
	newstr[j] = '\0';
	return (newstr);
}
/*
int	main()
{
	const char	*s1 = "          ";
	const char	*set = " ";
	
	printf("%s\n", ft_strtrim(s1, set));
	return (0);
}*/
