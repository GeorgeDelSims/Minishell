/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathieu <mathieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:26:30 by gsims             #+#    #+#             */
/*   Updated: 2024/03/27 07:48:10 by mathieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_execute(t_data *data, char *const *envp)
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

	init_args(data);
	tmp = data->list;
	while (tmp)
	{
		if (tmp->cmd)
		{
			if (is_builtin(tmp->cmd) == BUILTIN)
				init_builtin(data);
			else
				init_paths(data, (const char **)envp);
			if (data->list->cmd_path && is_builtin(tmp->cmd) == CMD)
				ft_execute(data, envp);
		}
		tmp = tmp->next;
	}
}
