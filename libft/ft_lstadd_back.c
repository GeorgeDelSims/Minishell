/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:23:39 by gsims             #+#    #+#             */
/*   Updated: 2023/10/18 08:40:17 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	curr = *lst;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}
/*
int	main()
{
	t_list	*lst = ft_lstnew("First One");
	
	if (!lst)
		return (1);

	ft_lstadd_back(&lst, ft_lstnew("Second"));
	ft_lstadd_back(&lst, ft_lstnew("Third"));

	while (lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
	ft_lstclear(&lst, &free);
	return (0);
}*/
