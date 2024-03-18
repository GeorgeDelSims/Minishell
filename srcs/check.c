/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 08:26:05 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/03/18 11:11:29 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_error_syntax(char *msg, int i)
{
	if (i == 0)
		printf("minishell: syntax error near unexpected token `%s'\n", msg);
	else if (i == 1)
		printf("minishell: %s\n", msg);
	return (1);
}

void	check_syntax(t_data *d)
{
	t_liste	*tmp;
	t_token	*tmp_t;

	tmp = d->list;
	while (tmp)
	{
		tmp_t = tmp->token;
		while (tmp_t)
		{
			if ((tmp_t->type == MET || tmp_t->type == HEREDOC) && tmp_t->next
				&& (tmp_t->next->type == MET || tmp_t->next->type == HEREDOC))
			{
				ft_error_syntax(tmp_t->next->content, 0);
				break ;
			}
			else if (tmp_t->type == MET && !tmp_t->next)
				ft_error_syntax("newline", 0);
			tmp_t = tmp_t->next;
		}
		tmp = tmp->next;
	}
	here_doc(d);
}