/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:58:00 by gsims             #+#    #+#             */
/*   Updated: 2023/10/17 14:05:19 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Gets length of linked list 
//returns size / length (integer)
int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		counter;

	counter = 0;
	current = lst;
	while (current != NULL)
	{
		current = current->next;
		counter++;
	}
	return (counter);
}

/*
int	main()
{
	t_list	lst;

	lst.content = (void*)2;
	lst.next = malloc(sizeof(lst));
	lst.next->content = (void*)4;
	lst.next->next = malloc(sizeof(lst));
	lst.next->next->content = (void*)8;
	lst.next->next->next = NULL;
	
	printf("%d\n", ft_lstsize(&lst));
	return (0);
}*/
