/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listutils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathieu <mathieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:19:11 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/03/18 16:37:52 by mathieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	token_size(t_token *token)
{
	t_token	*current;
	int		counter;

	counter = 0;
	current = token;
	while (current != NULL)
	{
		current = current->next;
		counter++;
	}
	return (counter);
}

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
			dst[i] = ft_tolower(src[i]);
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

char	*ft_strdup_lower(const char *s)
{
	char	*dest;
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	dest = (char *)malloc((i + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s, i + 1);
	return (dest);
}
