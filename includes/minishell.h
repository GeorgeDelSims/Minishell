/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathieu <mathieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:36:45 by georgesims        #+#    #+#             */
/*   Updated: 2024/03/14 14:39:46 by mathieu          ###   ########.fr       */
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

# define RED        "\033[91;1m"
# define GREEN        "\033[92;1m"
# define YELLOW        "\033[93;1m"
# define BLUE        "\033[94;1m"
# define VIOLET        "\033[95;1m"
# define ORANGE        "\033[38;2;255;165;0;1m"
# define TURQ        "\033[96;1m"
# define CLEAR        "\033[0m"
# define SINGLE_QUOTE 1
# define DOUBLE_QUOTE 2
# define UNDEFINED	0
# define TXT		1
# define CMD		2
# define BUILTIN	3
# define OPTION		4
# define ARG		5
# define MET		6
# define FILENAME	7

// cat > hello 
typedef struct s_token
{
    char            *content; // "cat"
    int             type; // CMD 
    struct s_token  *next; // -> ">"
}                   t_token;


typedef struct s_liste
{
    t_token         *token;
    char            *subline;
    int             in; // " STDIN = 0"
    int             out; // "STOUT = 1"
    const char      *cmd_path; // "usr/bin/cat"
    char            **args; // pas d'args
    int             *delimiter_array; 
    struct s_liste  *next;
}                   t_liste;

// Main data structure 
typedef struct  s_data
{
    char            **envp;
    char            **bin_paths;
    t_liste         *list;  // listes chainees de tokens 
    int             fd[2];
}                   t_data;

/*- SRCS -*/
/*----main.c----*/
void    ft_free_array(char **array);

/*----init.c----*/
t_data	*init_minishell(int ac, char *av[], const char *envp[]);
void	init_types(t_data *d);

/*----listutils.c----*/
t_liste	    *ft_list_new(char *subline);
t_token	    *ft_token_new(char *content);
void	    ft_add_back_list(t_liste **list, t_liste *new);
void	    ft_add_back(t_token **token, t_token *new);
void	    ft_add_front(t_token **token, t_token *new);
int	        token_size(t_token *token);

/*----check.c----*/
void	    check_syntax(char *line);

/*----utils.c----*/
void	ft_print_array(char **array);
void	ft_print_lists(t_data *data);

/*----exec.c----*/
int     ft_execute(t_data *data, char *const *envp);
int     ft_access(t_data *data);

/*----parsing.c----*/
void	parse(char *line, t_data *data);

/*----parsing_tokens.c----*/
void	create_tokens(t_liste *list, char *subline);

/*----error.c----*/
void	*ft_error(const char *msg);

/*----error.c----*/
void	free_lists(t_data *data);
void	ft_free(void *ptr);
void	ft_free_array(char **array);


#endif