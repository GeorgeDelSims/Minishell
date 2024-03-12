/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:36:45 by georgesims        #+#    #+#             */
/*   Updated: 2024/03/12 09:36:06 by gsims            ###   ########.fr       */
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

// cat > hello 
typedef struct s_token
{
    char            *content; // "cat"
    int             in; // " STDIN = 0"
    int             out; // "fd in de "hello" "
    const char      *cmd_path; // "usr/bin/cat"
    char            **args; // pas d'args
    int             type; // CMD 
    struct s_token  *next; // -> ">"
}                   t_token;


typedef struct s_list
{
    t_token         *token;
    struct s_list   *next;
}                   t_list;

// Main data structure 
typedef struct  s_data
{
    char            **envp;
    char            **bin_paths;
    t_list          *list;  // listes chainees de tokens 
    int             fd[2];
    // t_statement     *statements;
}                   t_data;


/*- SRCS -*/
/*----main.c----*/

/*----init.c----*/
t_data	*init_minishell(int ac, char *av[], const char *envp[]);

/*----listutils.c----*/


/*----utils.c----*/
void	ft_print_array(char **array);

/*----exec.c----*/
int     ft_execute(t_data *data, char *const *envp);

/*----parsing.c----*/
int     ft_access(t_data *data);

/*----error.c----*/
void	*ft_error(const char *msg);



#endif