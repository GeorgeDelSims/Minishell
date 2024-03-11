/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:26:30 by gsims             #+#    #+#             */
/*   Updated: 2024/03/11 15:16:31 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_access(t_data *data)
{
	int		i;
	char 	*path;
	
	i = 0;
	while (data->bin_paths[i])
	{
		path = ft_strjoin(data->bin_paths[i], data->cmds->cmd);		
		if (access(path, X_OK) == 0)
		{
			data->cmds->cmd_path = (const char *)path;
			return (1);
		}	
		free(path);
		i++;
	}
	return (0);
}


int	ft_execute(t_data *data, char *const *envp)
{
	if (ft_access(data) == 0)
		return (0);
	else
		return (execve(data->cmds->cmd_path, data->cmds->args, envp));
}