/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:33:47 by gsims             #+#    #+#             */
/*   Updated: 2023/10/12 09:20:13 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char)c;
	ptr = b;
	while (i < len)
	{
		ptr[i] = uc;
		i++;
	}
	return (ptr);
}
/*
int main() 
{ 
	unsigned char	b[] = "blablabla 42424242 blablabla"; 

   	printf("\nBefore memset(): %s\n", b); 
    // Fill 8 characters starting from str[13] with '.' 
	ft_memset(b + 3, 'A', 8*sizeof(char)); 
    printf("After memset():  %s\n", b); 
    return 0; 
}*/
