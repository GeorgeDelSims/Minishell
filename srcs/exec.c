/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:26:30 by gsims             #+#    #+#             */
/*   Updated: 2024/03/26 11:01:32 by gsims            ###   ########.fr       */
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

	tmp = data->list;
	while (tmp)
	{
		if (tmp->cmd)
		{
			if (is_builtin(tmp->cmd) == BUILTIN)
				init_paths_builtin(data);
			else
				init_paths(data, (const char **)envp);
			if (data->list->cmd_path)
				ft_execute(data, envp);
		}
		tmp = tmp->next;
	}
}
