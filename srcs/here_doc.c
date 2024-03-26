/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:57:24 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/03/26 11:08:51 by gsims            ###   ########.fr       */
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
		// printf("content :         %s\nline :             %s\n", tmp->next->content, line);
		if (tmp->next && ft_strcmp(line, tmp->next->content) == 0)
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
	int		hd_count;

	hd_count = 0;
	tmp = d->list->token;
	while (tmp)
	{
		if (tmp->type == HEREDOC)
			hd_count++;
		tmp = tmp->next;
	}
	tmp = d->list->token;
	while (tmp)
	{
		if (tmp->type == HEREDOC && hd_count > 1)
			hd_count--;
		else if (tmp->type == HEREDOC && hd_count == 1)
			here_doc_init(tmp, d);
		tmp = tmp->next;
	}
}
