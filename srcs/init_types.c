/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_types.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathieu <mathieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:05:02 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/03/28 14:29:34 by mathieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	what_is_this(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		if (tmp->content[0] == 45 && tmp->prev && tmp->prev->type != OPTION)
			tmp->type = OPTION;
		else if (ft_strncmp(tmp->content, "<<", 2) == 0)
			tmp->type = HEREDOC;
		else if (tmp->content[0] == 60 || tmp->content[0] == 62)
			tmp->type = MET;
		else
			tmp->type = TXT;
		tmp = tmp->next;
	}
}

int	is_builtin(char *content)
{
	if (!(ft_strcmp(content, "echo")) || !(ft_strcmp(content, "env"))
		|| !(ft_strcmp(content, "pwd")) || !(ft_strcmp(content, "cd"))
		|| !(ft_strcmp(content, "unset"))
		|| !(ft_strcmp(content, "export"))
		|| !(ft_strcmp(content, "exit")))
		return (BUILTIN);
	else
		return (CMD);
}

void	init_types_utils(t_token *token)
{
	t_token	*tmp;
	int		i;

	i = 0;
	token->size = token_size(token);
	tmp = token;
	what_is_this(tmp);
	while (tmp)
	{
		if (i == 0 && tmp->type == TXT)
			tmp->type = is_builtin(tmp->content);
		else if (i > 0 && tmp->prev->type == MET && tmp->type != MET)
			tmp->type = FILENAME;
		tmp = tmp->next;
		i++;
	}
}

void	init_types(t_data *d)
{
	t_liste	*tmp;
	t_token	*tmp_t;

	tmp = d->list;
	if (!tmp)
		tmp = NULL ;
	else
	{
		while (tmp)
		{
			if (tmp_t)
			{
				tmp_t = tmp->token;
				init_types_utils(tmp_t);
			}
			tmp = tmp->next;
		}
	}
}
