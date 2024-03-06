/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:13:37 by gsims             #+#    #+#             */
/*   Updated: 2023/10/17 14:02:48 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Creates new node of linked list with dynamically allocated content. 
//returns pointer to new node. 
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
/*
int	main()
{
	int		n;
	t_list	*new;

	n = 42;
	new = ft_lstnew(&n);
	printf("content of the new node: %d\n", *(int *)(new->content));
}*/
