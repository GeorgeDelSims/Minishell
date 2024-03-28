/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:57:20 by gsims             #+#    #+#             */
/*   Updated: 2024/03/28 13:35:45 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Initialises the correct amount of fd[2]s 
// creates a pipe out of each of them
// Fills their values with the in / out values of each command 
static void	create_pipes(t_data *data)
{
	int			i;
	int			p;

	// curr_list = data->list;
	i = 0;
	data->fd = malloc(sizeof(int[2]) * (data->number_of_pipes + 1));
	while (i < data->number_of_pipes)
	{	
		// data->fd[i][0] = curr_list->in;
		// data->fd[i][1] = curr_list->out;
		p = pipe(data->fd[i]);
		if (p == -1)
			ft_error("Error with pipe function\n");
		i++;
		// curr_list = curr_list->next;
	}	
}

// Closes all pipes in order to avoid deadlocks
static void	close_pipes(t_data	*data)
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

// Child process function that will be called at every new pipe
static void	child_process(t_data *data, int *i, const char **envp)
{
	if (*i > 0)
		dup2(data->fd[*i - 1][0], STDIN_FILENO);
	if (*i < data->number_of_pipes)
		dup2(data->fd[*i][1], STDOUT_FILENO);
	ft_exec(data, (char *const*)envp);
}

// parent process function which manages the main process (also the last one )
static void	parent_process(t_data *data, const char **envp)
{
	int	i;
	
	close_pipes(data);	
	i = 0;
	while(i < data->number_of_pipes)
	{
		waitpid(-1, NULL, 0);
		i++;
	}
	dup2(data->fd[data->number_of_pipes - 1][0], STDIN_FILENO);
	ft_exec(data, (char *const*)envp);
}

// Function to execute the minishell with pipes
int	run_minishell(t_data *data, const char **envp)
{
	pid_t	pid;
	int		i;
	
	if (data->number_of_pipes == 0)
	{
		ft_exec(data, (char *const*)envp);
		return (EXIT_SUCCESS);
	}
	create_pipes(data);
	i = 0;
	while (i <= data->number_of_pipes)
	{
		pid = fork();
		if (pid == -1)
		{
			ft_error("Error with fork function\n");
			break ; 
		}
		if (pid == 0) // Child process
		{
			child_process(data, &i, envp);
			close_pipes(data);
			exit(EXIT_SUCCESS);
		}
		i++;
	}
	parent_process(data, envp);
	return (EXIT_SUCCESS);
}
