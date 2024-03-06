/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:39:47 by gsims             #+#    #+#             */
/*   Updated: 2023/10/17 14:42:26 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Clears a linked list by deleting all nodes with del function
// returns void
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*current;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current != NULL)
	{
		tmp = current->next;
		(*del)(current->content);
		free(current);
		current = tmp;
	}
	*lst = NULL;
}
