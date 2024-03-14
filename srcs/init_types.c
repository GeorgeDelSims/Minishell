/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_types.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathieu <mathieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:05:02 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/03/14 14:43:44 by mathieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_meta(char content)
{
	if(content == 45)
		return (OPTION);
	if(content == 60 || content == 62)
		return (MET);
	return (ARG);
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
	int		size;

	i = 0;
	size = token_size(token) - 1;
	tmp = token;
	while(tmp)
	{
		if (is_meta(tmp->content[0]) == MET)
			tmp->type = MET;
		else if (i == 0 && is_meta(tmp->content[0]) == ARG)
			tmp->type = is_builtin(tmp->content);
		else if (i == size && is_meta(tmp->content[0]) == ARG)
			tmp->type = FILENAME;
		else if (i != 0 && is_meta(tmp->content[0]) != MET)
			tmp->type = is_meta(tmp->content[0]);
		if (i == 0 && (!ft_strncmp(tmp->content, "echo"
			, ft_strlen(tmp->content)) || !ft_strncmp(tmp->content, "printf"
				, ft_strlen(tmp->content))) && size == 1)
		{
			tmp->next->type = ARG;
			break ;
		}
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
