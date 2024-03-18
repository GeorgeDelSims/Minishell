/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathieu <mathieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:41:01 by georgesims        #+#    #+#             */
/*   Updated: 2024/03/18 22:11:25 by mathieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_quit(char *line)
{
	free(line);
	return (1);
}

int	main(int ac, char *av[], const char *envp[])
{
	char	*line;
	t_data	*data;
		
	if (ac < 1 || av || !envp)
		line = NULL;
	data = init_minishell(ac, av, envp);
	while (1)
	{
		line = readline("minishell> ");
		if (line && *line) 
			add_history(line);
		if (ft_strcmp(line, "exit") == 0 && ft_quit(line))
			break ;
		// replace dollar signs by env values
		parse(line, data);
		free(line); // Il y a un malloc dans readline()
		free_lists(data);
		// data->cmds->cmd = line; // Juste pour tester la fonction Exec
		// ft_execute(data, (char* const*)envp);
	}
	rl_clear_history();
	return (EXIT_SUCCESS);
}
