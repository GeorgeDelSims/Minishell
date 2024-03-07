/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:41:01 by georgesims        #+#    #+#             */
/*   Updated: 2024/03/07 09:58:27 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main(int ac, char *av[], char *envp[])
{
    char *line;
    
    if (ac < 1 || av || !envp)
        line = NULL;
    while (1)
    {
        line = readline("minishell>");
        
        if (ft_strncmp(line, "exit", ft_strlen("exit")) == 0)
            break ;
    }
    return (EXIT_SUCCESS);
}