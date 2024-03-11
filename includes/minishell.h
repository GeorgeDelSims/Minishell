/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:36:45 by georgesims        #+#    #+#             */
/*   Updated: 2024/03/11 17:48:16 by gsims            ###   ########.fr       */
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

typedef enum
{
    UNDEFINED, // pas initialisé
    CMD, // cat 
    BUILTIN, // commande built-in
    FILE, // filename
    ARG, // -r
    INPUT_REDIRECT, // < 
    OUTPUT_REDIRECT, // > 
    APPEND, // >>
    HEREDOC, // << 
    PIPE, // |
}   type;

typedef struct s_token
{
    char            *content;
    int             in;
    int             out;
    const char      *cmd_path;
    char            **args;
    int             type;
    struct s_token  *next;
}                   t_token;

// Main data structure 
typedef struct  s_data
{
    char            **envp;
    char            **bin_paths;
    t_token         *tokens;  // liste chainee de commandes
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