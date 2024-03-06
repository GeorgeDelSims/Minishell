/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:07:43 by gsims             #+#    #+#             */
/*   Updated: 2023/10/10 14:45:28 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n_len;

	i = 0;
	n_len = 0;
	while (needle[n_len] != '\0')
		n_len++;
	if (n_len == 0 || haystack == needle)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len
			&& haystack[i + j] != '\0' && needle[j] != '\0')
			j++;
		if (j == n_len)
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
