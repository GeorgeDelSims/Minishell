/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathieu <mathieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:26:30 by gsims             #+#    #+#             */
/*   Updated: 2024/03/28 09:24:50 by mathieu          ###   ########.fr       */
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
	int		i;
	char	*tmp;

	i = 0;
	d->bin_paths = ft_split(find_path(envp), ':');
	if (access(d->list->cmd, X_OK) == 0)
		d->list->cmd_path = ft_strdup(d->list->cmd);
	else if (d->list->cmd)
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

void	exec_builtin(t_data *d)
{
	if (ft_strcmp(d->list->cmd, "pwd") == 0)
		pwd_cmd();
	else if (ft_strcmp(d->list->cmd, "echo") == 0)
		echo_cmd(d);
	else if (ft_strcmp(d->list->cmd, "env") == 0)
		env_cmd(d);
	else if (ft_strcmp(d->list->cmd, "cd") == 0)
		cd_cmd(d);
	else if (ft_strcmp(d->list->cmd, "unset") == 0)
		unset_cmd(d);
	else if (ft_strcmp(d->list->cmd, "export") == 0)
		export_cmd(d);
	else if (ft_strcmp(d->list->cmd, "exit") == 0)
		ft_exit(d, "exit", EXIT_SUCCESS);
}

void	exec_cmd(t_data *data, char *const *envp)
{
	int		status;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execve(data->list->cmd_path, data->list->args, envp);
	else if (pid > 0)
		waitpid(pid, &status, 0);
}

void	ft_exec(t_data *data, char *const *envp)
{
	t_liste	*tmp;

	tmp = data->list;
	while (tmp)
	{
		if (tmp->cmd)
		{
			if (is_builtin(tmp->cmd) == BUILTIN)
				exec_builtin(data);
			else
				init_paths(data, (const char **)envp);
			if (data->list->cmd_path && is_builtin(tmp->cmd) == CMD)
				exec_cmd(data, envp);
		}
		tmp = tmp->next;
	}
}
