/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:33:44 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/03/19 13:36:40 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*find_path(const char *envp[])
{
	int		i;
	char	*path;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	path = ft_substr(ft_strdup(envp[i]), 5, ft_strlen(envp[i]));
	return (path);
}

void	init_paths(t_data *d, const char *envp[])
{
	int	i;
	char	*tmp;
	
	i = 0;
	d->bin_paths = ft_split(find_path(envp), ':');
	if (d->list->cmd)
	{
		while (d->bin_paths[i])
		{
			tmp = ft_strjoin(d->bin_paths[i], ft_strjoin("/", d->list->cmd));
			if (access(tmp, X_OK) == 0)
			{
				d->list->cmd_path = ft_strdup(tmp);
				free(tmp);
				break ;
			}
			free(tmp);
			i++;
		}
		if (!d->list->cmd_path)
			ft_error_syntax("command not found", d->list->token->content, 2);
	}
}
