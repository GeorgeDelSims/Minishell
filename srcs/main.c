/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:41:01 by georgesims        #+#    #+#             */
/*   Updated: 2024/03/19 08:43:57 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int    ft_quit(char *line)
{
    ft_free(line);
    return (1);
}

int main(int ac, char *av[], const char *envp[])
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
        if (line && *line) 
        {
            add_history(line);
            tmp = line;
            line = include_env_vars(data, tmp);
            ft_free(tmp);
            parse(line, data);
            if (ft_strncmp(line, "exit", ft_strlen("exit")) == 0 && ft_quit(line))
                break ;
            ft_free(line);
            free_lists(data);
        }
        
        // data->cmds->cmd = line; // Juste pour tester la fonction Exec
        // ft_execute(data, (char* const*)envp);
    }
    rl_clear_history();
    return (EXIT_SUCCESS);
}