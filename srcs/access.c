/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathieu <mathieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:33:44 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/03/20 23:25:21 by mathieu          ###   ########.fr       */
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
char	*get_pwd(t_data *d)
{
	char	*pwd;
	char	*tmp;

	tmp = malloc(sizeof(char) * 2000);
	pwd = malloc(sizeof(char) * 2000);
	getcwd(tmp, 2000);
	pwd = ft_strjoin(tmp, ft_strjoin("/srcs/builtins/",
				ft_strjoin(d->list->cmd, ft_strjoin("/", d->list->cmd))));
	free(tmp);
	return (pwd);
}

void	init_paths_builtin(t_data *d)
{
	if (ft_strcmp(d->list->cmd, "echo") == 0)
		d->list->cmd_path = ft_strdup(get_pwd(d));
	else if (ft_strcmp(d->list->cmd, "env") == 0)
		d->list->cmd_path = ft_strdup(get_pwd(d));
	else if (ft_strcmp(d->list->cmd, "pwd") == 0)
		d->list->cmd_path = ft_strdup(get_pwd(d));
	else if (ft_strcmp(d->list->cmd, "cd") == 0)
		d->list->cmd_path = ft_strdup(get_pwd(d));
	else if (ft_strcmp(d->list->cmd, "unset") == 0)
		d->list->cmd_path = ft_strdup(get_pwd(d));
	else if (ft_strcmp(d->list->cmd, "export") == 0)
		d->list->cmd_path = ft_strdup(get_pwd(d));
	else if (ft_strcmp(d->list->cmd, "exit") == 0)
		d->list->cmd_path = ft_strdup(get_pwd(d));
}

void	init_paths(t_data *d, const char *envp[])
{
	int		i;
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
		else
			init_args(d);
	}
}
