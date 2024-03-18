/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:57:24 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/03/18 11:35:20 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	here_doc_init(t_token *tmp, t_data *d)
{
	t_list	*tmp_hdoc;
	char	*line;
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (tmp->next && ft_strncmp(line, tmp->next->content, ft_strlen(line)) == 0)
		{
			free(line);
			break ;
		}
		tmp_hdoc = ft_lstnew(ft_strdup(line));
		ft_lstadd_back(&(d->hdoc), tmp_hdoc);
		free(line);
	}
}

void	here_doc(t_data *d)
{
	t_token	*tmp;

	tmp = d->list->token;
	while (tmp)
	{
		if (tmp->type == HEREDOC)
			here_doc_init(tmp, d);
		tmp = tmp->next;
	}
}
