/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:38:29 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/03/28 12:02:44 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	cd_cmd(t_data *d)
{
	if (ft_strcmp(d->list->args[1], "-") == 0 && !d->oldpwd[0])
	{
		ft_error_syntax("OLDPWD not set", d->list->token->content, 2);
		return ;
	}
	if (d->list->args)
	{
		if (ft_strcmp(d->list->args[1], "-") == 0)
		{
			d->pwd = ft_strdup(d->oldpwd);
			getcwd(d->oldpwd, 2000);
		}
		else if (d->list->args[1])
		{
			getcwd(d->oldpwd, 2000);
			d->pwd = ft_strdup(d->list->args[1]);
		}
	}
	else
		d->pwd = ft_strdup(getenv("HOME"));
	if (chdir(d->pwd) == -1 && d->list->token->next->type != MET)
		ft_error_syntax("No such file or directory", d->list->token->next->content, 3);

	free(d->pwd);
}
