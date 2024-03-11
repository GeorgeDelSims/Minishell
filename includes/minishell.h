/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:36:45 by georgesims        #+#    #+#             */
/*   Updated: 2024/03/11 15:16:34 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*- INCLUDES -*/
# include "../libft/libft.h"
# include <errno.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>


/*- STRUCTURES -*/

// Statement linked list (for history)
// typedef struct s_statement
// {
    // int                 ac;
    // char                **av;
    // struct s_statement  *next;
// }                       t_statement;
// 
typedef struct s_cmd
{
    int             in;
    int             out;
    char            *cmd;
    const char      *cmd_path;
    char            **args;
    int             append;
    struct s_cmd    *next;
}                   t_cmd;

// Main data structure 
typedef struct  s_data
{
    char            **envp;
    char            **bin_paths;
    t_cmd           *cmds;  // liste chainee de commandes
    int             fd[2];
    // t_statement     *statements;
}                   t_data;


/*- SRCS -*/
/*----main.c----*/

/*----init.c----*/
t_data	*init_minishell(int ac, char *av[], const char *envp[]);

/*----utils.c----*/
void	ft_print_array(char **array);

/*----parsing.c----*/

/*----exec.c----*/
int     ft_execute(t_data *data, char *const *envp);

/*----parsing.c----*/
int     ft_access(t_data *data);

/*----error.c----*/
void	*ft_error(const char *msg);


#endif