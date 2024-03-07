/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:36:45 by georgesims        #+#    #+#             */
/*   Updated: 2024/03/07 11:13:51 by gsims            ###   ########.fr       */
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
typedef struct s_statement
{
    int                 ac;
    char                **av;
    struct s_statement  *next;
}                       t_statement;

typedef struct s_cmd
{
    int             in;
    int             out;
    char            *cmd;
    char            **args;
    int             append;
    struct s_cmd    *next;
}

// Main data structure 
typedef struct  s_data
{
    char            **envp;
    char            **bin_paths;
    int             fd[2];
    t_statement     *statements;
}                   t_data;


/*- SRCS -*/
/*----main.c----*/

/*----init.c----*/

/*----listutils.c----*/

/*----parsing.c----*/

#endif