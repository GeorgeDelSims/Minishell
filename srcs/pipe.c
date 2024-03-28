/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:57:20 by gsims             #+#    #+#             */
/*   Updated: 2024/03/28 12:14:01 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Initialises the correct amount of fd[2]s 
// creates a pipe out of each of them
// Fills their values with the in / out values of each command 
void	create_pipes(t_data *data)
{
	int			i;
	t_liste		curr_list;

	curr_list = data->list;
	i = 0;
	data->fd = (int *)malloc(sizeof(int *) * (number_of_pipes + 1));
	while (i < data->number_of_pipes && curr_list)
	{	
		data->fd[i][0] = curr_list->in;
		data->fd[i][1] = curr_list->out;
		p = pipe(data->fd[i]);
		if (p == -1)
			ft_error("Error with pipe function\n");
		i++;
		curr_list->next = curr_list;
	}	
}

void	close_pipes(t_data	*data)
{
	int	i;

	i = 0;
	while (i < data->number_of_pipes)
	{
		close(data->fd[i][0]);
		close(data->fd[i][1]);
		i++;
	}
}

void	child_process(t_data *data, int *i, char **envp)
{
	if (*i > 0)
		dup2(data->fd[i - 1][0], STDIN_FILENO);
	if (*i < data->number_of_pipes)
		dup2(data->fd[i][1], STDOUT_FILENO);
}


// Function to execute the minishell with pipes
void	run_minishell(t_data *data, char *line, const char **envp)
{
	pid_t	pid;
	int		p;
	int		i;
	
	if (!data || !line || !envp)
		return (NULL);
	create_pipes(data);
	i = 0;
	while (i <= data->number_of_pipes)
	{
		pid = fork();
		if (pid == -1)
			ft_error("Error with fork function\n");
		if (pid == 0) // Child process
		{
			child_process(data, &i, envp);
			close_pipes(data);
		}
	}
	close_pipes(data);	
	i = 0;
	while(i < data->number_of_pipes)
	{
		waitpid(-1, NULL, 0);
		i++;
	}
	parent_process(data, envp):
}























    // Close all pipe fds in the parent process
    for (int i = 0; i < data->number_of_pipes; ++i) {
        close(data->fd[i][0]);
        close(data->fd[i][1]);
    }

    for (int i = 0; i <= data->number_of_pipes; ++i) { // Wait for all child processes
        wait(NULL);
    }

    // The parent_process function seems to be intended for after all children have completed
    parent_process(data, envp);
}
