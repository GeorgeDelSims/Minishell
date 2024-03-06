/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:18:57 by gsims             #+#    #+#             */
/*   Updated: 2023/10/18 11:52:43 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Iterates over linked list, copies it to a new one 
// Returns the copied list. 
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*newnode;
	void	*content_new;

	if (!lst || !f || !del)
		return (NULL);
	result = NULL;
	while (lst)
	{
		content_new = f(lst->content);
		newnode = ft_lstnew(content_new);
		if (newnode == NULL)
		{
			if (content_new)
				del(content_new);
			ft_lstclear(&result, del);
			return (NULL);
		}
		if (!result)
			result = newnode;
		else
			ft_lstadd_back(&result, newnode);
		lst = lst->next;
	}
	return (result);
}
