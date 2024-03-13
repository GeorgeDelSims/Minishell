/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:26:30 by gsims             #+#    #+#             */
/*   Updated: 2024/03/13 13:44:31 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// int	ft_access(t_data *data)
// {
	// int		i;
	// char 	*path;
	// 
	// i = 0;
	// while (data->bin_paths[i])
	// {
		// path = ft_strjoin(data->bin_paths[i], data->list->token->content);		
		// if (access(path, X_OK) == 0)
		// {
			// data->list->token->cmd_path = (const char *)path;
			// return (1);
		// }	
		// free(path);
		// i++;
	// }
	// return (0);
// }
// 
// 
// int	ft_execute(t_data *data, char *const *envp)
// {
	// if (ft_access(data) == 0)
		// return (0);
	// else
		// return (execve(data->list->token->cmd_path, data->list->token->args, envp));
// }