/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:57:29 by georgesims        #+#    #+#             */
/*   Updated: 2024/03/18 14:09:33 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Fonction pour creer nouvelle list (ou subline de tokens)
t_liste	*ft_list_new(char *subline)
{
	t_liste	*new;

	new = (t_liste *)malloc(sizeof(t_liste));
	if (!new)
		return (NULL);
	new->subline = malloc(ft_strlen(subline) + 1);
	if (new->subline)
		new->subline = ft_strdup(subline);
	else
	{
		ft_free(new);
		return (NULL);
	}
	new->cmd = NULL;
	new->token = NULL;
	new->next = NULL;
	return (new);
}

// fonction pour ajouter un deuxieme node a la liste de sublines
void	ft_add_back_list(t_liste **list, t_liste *new)
{
	t_liste		*curr;

	if (!list || !new)
		return ;
	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	curr = *list;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}

// Fonction pour creer nouveau node ou nouvelle liste chainee de commandes
t_token	*ft_token_new(char *content)
{
	t_token	*new;
	
	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->content = ft_strdup(content);
	new->type = 0;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

// Ajouter node a la fin de la liste de tokens 
void	ft_add_back(t_token **token, t_token *new)
{
	t_token	*curr;
	
	if (!token || !new)
		return ;
	if (*token == NULL)
	{
		*token = new;
		return ;
	}
	curr = *token;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
	new->prev = curr;
}

// Ajouter node au debut de la liste de tokens
void	ft_add_front(t_token **token, t_token *new)
{
	if (!token || !new)
		return ;
	new->next = *token;
	if (*token)
		(*token)->prev = new;
	*token = new;
}
