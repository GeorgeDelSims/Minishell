/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathieu <mathieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:59:36 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/03/18 21:40:28 by mathieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	update_standards(t_data *data, t_token *token)
{
	t_token	*t;
	t_data	*d;

	t = token;
	d = data;
	if (ft_strncmp(t->content, "<", 1) == 0)
	{
		d->list->in = open(t->next->content, O_RDONLY);
		if (d->list->in == -1)
			ft_error_syntax("No such file or directory", t->next->content, 2);
	}
	else if (ft_strncmp(t->content, ">", 1) == 0)
	{
		d->list->out = open(t->next->content, O_WRONLY
				| O_CREAT | O_TRUNC, 0644);
		if (d->list->out == -1)
			ft_error_syntax("No such file or directory", t->next->content, 2);
	}
	else if (ft_strncmp(t->content, ">>", 2) == 0)
	{
		d->list->in = open(t->next->content, O_WRONLY
				| O_CREAT | O_APPEND, 0644);
		if (d->list->in == -1)
			ft_error_syntax("No such file or directory", t->next->content, 2);
	}
}	

void	update_list(t_data *d)
{
	t_liste	*tmp;
	t_token	*t;
	int		i;

	tmp = d->list;
	while (tmp)
	{
		t = d->list->token;
		i = 0;
		while (t)
		{
			if (i == 0 && t->type != MET && t)
				d->list->cmd = ft_strdup(t->content);
			else if (t->type == MET && t && t->next)
				update_standards(d, t);
			t = t->next;
			i++;
		}
		tmp = tmp->next;
	}
	here_doc(d);
}
