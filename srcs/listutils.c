/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:57:29 by georgesims        #+#    #+#             */
/*   Updated: 2024/03/11 15:40:26 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Fonction pour creer nouveau node ou nouvelle liste chainee de commandes
// il faudra surement les arguments de la commande en args de la fonction
t_cmd	*ft_cmd_new(char *cmd, char **args)
{
	t_cmd	*new;
	
	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->cmd = cmd;
	new->args = args;
	new->next = NULL;
	return (new);
}