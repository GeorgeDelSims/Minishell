/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:57:29 by georgesims        #+#    #+#             */
/*   Updated: 2024/03/11 17:55:17 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Fonction pour creer nouveau node ou nouvelle liste chainee de commandes
t_token	*ft_token_new(char *content)
{
	t_token	*new;
	
	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->content = content;
	new->in = 0;
	new->out = 1;
	new->cmd_path = NULL;
	new->args = NULL;
	new->type = 0;
	new->next = NULL;
	return (new);
}

// Ajouter node a la fin de la liste de tokens 
void	ft_add_back(t_token **token, t_token *new)
{
	t_token	*curr;
	
	if (!token || !new)
		return ;
	if (*token = NULL)
	{
		*token = new;
		return ;
	}
	curr = *token;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}

// Ajouter node au debut de la liste de tokens
void	ft_add_front(t_token **token, t_token *new)
{
	if (!token || !new)
		return ;
	new->next = *token;
	*token = new;
}

