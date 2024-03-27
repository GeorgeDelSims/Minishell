/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:26:25 by gsims             #+#    #+#             */
/*   Updated: 2024/03/27 09:19:13 by gsims            ###   ########.fr       */
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
    char        *line;
    char        *tmp;
    t_data      *data;
    
    if (ac < 1 || av || !envp)
        line = NULL;
    data = init_minishell(ac, av, envp);
    while (1)
    {
        line = readline("minishell> ");
		if (line == NULL)
			break;
        if (line && *line) 
        {
            if (ft_strncmp(line, "exit", ft_strlen("exit")) == 0 && ft_quit(line)) // temporaire
                break ;
            add_history(line);
            tmp = line;
            line = include_env_vars(data, tmp);
            free(tmp);
            parse(line, data);
            ft_exec(data, (char *const*)envp);
            free(line);
            free_lists(data);
        }
    }
    rl_clear_history();
    return (EXIT_SUCCESS);
}
