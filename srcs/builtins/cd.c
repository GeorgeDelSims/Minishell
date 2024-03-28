/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathieu <mathieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:38:29 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/03/28 08:08:50 by mathieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	set_pwd(t_data *d)
{
	
}

void	cd_cmd(t_data *d)
{
	char		*path;

	path = NULL;
	if (d->list->args)
	{
		if (ft_strcmp(d->list->args[1], "-") == 0)
			path = ft_strdup(d->oldpwd);
		else if (d->list->args[1])
			path = ft_strdup(d->list->args[1]);
	}
	else
		path = ft_strdup(getenv("HOME"));
	if (chdir(path) == -1 && d->list->token->next->type != MET)
		ft_error_syntax("No such file or directory", d->list->token->next->content, 3);
	free(path);
}
