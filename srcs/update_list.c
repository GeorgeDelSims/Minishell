/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:59:36 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/03/18 14:45:00 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	update_standards(t_data *d)
{
	t_token	*t;

	t = d->list->token;
	if (ft_strncmp(t->content, "<", 1) && t && t->next)
	{
		d->list->in = open(t->next->content, O_RDONLY);
		if (d->list->in == -1)
			read_error("Erreur lors de l'ouverture du fichier");
	}
	else if (ft_strncmp(t->content, ">", 1) && t && t->next)
	{
		d->list->out = open(t->next->content, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (d->list->in == -1)
			read_error("Erreur lors de l'ouverture du fichier");
	}
	else if (ft_strncmp(t->content, ">>", 2) && t && t->next)
	{
		d->list->in = open(t->next->content, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (d->list->in == -1)
			read_error("Erreur lors de l'ouverture du fichier");
	}
}	

void	update_list(t_data *d)
{
	t_liste	*tmp;
	t_token	*tmp_t;
	int		i;

	tmp = d->list;
	while (tmp)
	{
		tmp_t = d->list->token;
		i = 0;
		while (tmp_t)
		{
			if (i == 0 && tmp_t->type != MET && tmp_t)
				d->list->cmd = ft_strdup(tmp_t->content);
			else if (tmp_t->type == MET && tmp_t && tmp_t->next)
				update_standards(d);
		}
	}
	printf("CMD = %s\nIN = %d\nOUT = %d\n", d->list->cmd, d->list->in, d->list->out);
}
