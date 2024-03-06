/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:17:57 by gsims             #+#    #+#             */
/*   Updated: 2023/10/17 16:27:44 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns the last node of the list
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*curr;

	if (!lst)
		return (NULL);
	curr = lst;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = NULL;
	return (curr);
}
/*
int	main()
{
	t_list	*lst = ft_lstnew("Bollocks");
	t_list	*result;
	char	*str;

	ft_lstadd_back(&lst, ft_lstnew(NULL));
	ft_lstadd_back(&lst, ft_lstnew("dddd"));
	result = ft_lstlast(lst);
	str = (char*)result->content;
	printf("result : %s\n", str);
	return (0);
}*/
