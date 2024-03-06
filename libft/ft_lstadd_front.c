/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:30:58 by gsims             #+#    #+#             */
/*   Updated: 2023/10/17 15:44:10 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//adds node to the front of linked list 
//returns Void 
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	t_list *lst = ft_lstnew("World"); // Create a new node with content "World"
	if (!lst)
		return (1); // Handle allocation failure if needed

	// Add nodes to the front of the list
	ft_lstadd_front(&lst, ft_lstnew("Hello"));
	ft_lstadd_front(&lst, ft_lstnew("Goodbye"));

	// Print the contents of the list
	printf("Contents of the list:\n");
	while (lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}

	// Don't forget to free the list when you're done
	ft_lstclear(&lst, &free);

	return (0);
}*/
