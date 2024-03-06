/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:05:15 by gsims             #+#    #+#             */
/*   Updated: 2023/10/11 16:00:59 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
/*
int	ft_isalpha(int c)
{
	if (c >= 65 && c <= 90 || c >= 97 && c <= 122)
		return (1);
	else
		return (0);
}

int	ft_isdigit(unsigned char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
*/
#include "libft.h"

int	ft_isalnum(int c)
{
	if ((ft_isalpha(c) == 1) || (ft_isdigit(c) == 1))
		return (1);
	else
		return (0);
}
/*
int	ft_toupper(unsigned char c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}

int	ft_tolower(unsigned char c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}

int	main()
{
	int ex;

	ex = 67;
	printf("%d", ft_isalpha(ex));
	return (0);
}*/
