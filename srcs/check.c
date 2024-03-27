/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 08:26:05 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/03/27 09:10:10 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


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
				ft_error_syntax(tmp_t->next->content, NULL, 0);
				break ;
			}
			else if (tmp_t->type == MET && !tmp_t->next)
				ft_error_syntax("newline", NULL, 0);
			tmp_t = tmp_t->next;
		}
		tmp = tmp->next;
	}
}
