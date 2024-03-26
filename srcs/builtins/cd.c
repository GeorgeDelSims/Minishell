/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:38:29 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/03/26 14:47:31 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	cd_cmd(t_data *d)
{
	char	*path;

	path = NULL;
	init_args(d);
	if (d->list->args)
	{
		if (d->list->args[1])
			path = ft_strdup(d->list->args[1]);
		else
			path = ft_strdup(getenv("HOME"));
		if (chdir(path) == -1 && d->list->token->next->type != MET)
			ft_error_syntax("No such file or directory", d->list->token->next->content, 3);
	}
	free(path);
}
