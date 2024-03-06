/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:36:45 by georgesims        #+#    #+#             */
/*   Updated: 2024/03/06 17:10:49 by georgesims       ###   ########.fr       */
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

// Main data structure 
typedef struct  s_data
{
    char            **envp;
    int             fd[2];
    t_statement     *statements;
}                   t_data;


/*- SRCS -*/
/*----main.c----*/

/*----init.c----*/

/*----listutils.c----*/

/*----parsing.c----*/

#endif