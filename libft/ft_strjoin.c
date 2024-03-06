/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:07:17 by gsims             #+#    #+#             */
/*   Updated: 2023/11/15 10:24:10 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*newstr;
	int		i;
	int		j;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	newstr = (char *)malloc((len + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (i < len && s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (i < len && s2[j] != '\0')
	{
		newstr[i] = s2[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
	return (newstr);
}
/*
int	main()
{
	const char	*s1 = "";
	const char	*s2 = "";

	printf("%s\n", ft_strjoin(s1, s2));
	return (0);
}*/
