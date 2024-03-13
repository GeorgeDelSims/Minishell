/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:41:01 by georgesims        #+#    #+#             */
/*   Updated: 2024/03/13 13:06:24 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main(int ac, char *av[], const char *envp[])
{
    char        *line;
    t_data      *data;
    
    if (ac < 1 || av || !envp)
        line = NULL;
    data = init_minishell(ac, av, envp);
    while (1)
    {
        line = readline("minishell> ");
        if (line && *line) 
            add_history(line);
        check_synthax(line);
        // replace dollar signs by env values
        parse(line, data);
        free(line); // Il y a un malloc dans readline()
        if (ft_strncmp(line, "exit", ft_strlen("exit")) == 0)
            break ;
        free_lists(data);
        // data->cmds->cmd = line; // Juste pour tester la fonction Exec
        // ft_execute(data, (char* const*)envp);
    }
    rl_clear_history();
    return (EXIT_SUCCESS);
}