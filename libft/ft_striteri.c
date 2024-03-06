/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 08:25:05 by gsims             #+#    #+#             */
/*   Updated: 2023/10/13 13:52:15 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	basic_func(unsigned int index, char *s)
{
	if (index % 2 == 0)
		s[index] = s[index] + 1;
	else
		s[index] = s[index] + 5;
}
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	if (s && *s && f)
	{
		i = 0;
		while (s[i] != '\0')
		{
			f(i, &s[i]);
			i++;
		}
	}
}
/*
int	main()
{
	char s[] = "1212121212121";

	ft_striteri(s, basic_func);
	printf("%s\n", s);
	return (0);
}*/
