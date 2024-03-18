/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_types.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:05:02 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/03/18 10:09:53 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	what_is_this(t_token *token)
{
	int		res;
	t_token	*tmp;

	res = 0;
	tmp = token;
	while (tmp)
	{
		if (tmp->content[0] == 45 && tmp->prev && tmp->prev->type != OPTION)
			tmp->type = OPTION;
		else if (ft_strncmp(tmp->content, "<<", 2) == 0)
		{
			tmp->type = HEREDOC;
			res++;
		}
		else if (tmp->content[0] == 60 || tmp->content[0] == 62)
		{
			tmp->type = MET;
			res++;
		}
		else
			tmp->type = TXT;
		tmp = tmp->next;
	}
	return (res);
}

int	is_builtin(char *content)
{
	int	s;

	s = ft_strlen(content);
	if (!(ft_strncmp(content, "echo", s)) || !(ft_strncmp(content, "env", s))
		|| !(ft_strncmp(content, "pwd", s)) || !(ft_strncmp(content, "cd", s))
		|| !(ft_strncmp(content, "unset", s))
		|| !(ft_strncmp(content, "export", s))
		|| !(ft_strncmp(content, "exit", s)))
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
		if (i > 0 && tmp->prev->type == MET && tmp && tmp->next
			&& tmp->next->type == TXT)
			tmp->next->type = is_builtin(tmp->next->content);
		tmp = tmp->next;
		i++;
	}
}

void	init_types(t_data *d)
{
	t_liste	*tmp;
	t_token	*tmp_t;

	tmp = d->list;
	while (tmp)
	{
		tmp_t = tmp->token;
		init_types_utils(tmp_t);
		tmp = tmp->next;
	}
	ft_print_lists(d);
}
