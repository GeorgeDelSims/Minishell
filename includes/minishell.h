/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:36:45 by georgesims        #+#    #+#             */
/*   Updated: 2024/03/27 14:41:51 by gsims            ###   ########.fr       */
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

# define RED		"\033[91;1m"
# define GREEN		"\033[92;1m"
# define YELLOW		"\033[93;1m"
# define BLUE		"\033[94;1m"
# define VIOLET		"\033[95;1m"
# define ORANGE		"\033[38;2;255;165;0;1m"
# define TURQ		"\033[96;1m"
# define CLEAR		"\033[0m"
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
# define HEREDOC    8

// cat > hello 
typedef struct s_token
{
	char			*content; // "cat"
	int				type; // CMD
	int				size;
	struct s_token	*next; // -> ">"
	struct s_token	*prev;
}					t_token;

typedef struct s_liste
{
	t_token			*token;
	char			*subline;
	char			*cmd;
	int				in; // " STDIN = 0"
	int				out; // "STOUT = 1"
	const char		*cmd_path; // "usr/bin/cat"
	char			**args; // options, file, args... (premier elmt commande)
	int				*delimiter_array;
	struct s_data	*data;
	struct s_liste	*next;
}					t_liste;

typedef struct s_env
{
	char			*content;
	struct s_env	*next;
	struct s_env	*prev;
}					t_env;


// Main data structure 
typedef struct s_data
{
	//char			**envp;
	char			**bin_paths;
	t_liste			*list; // listes chainees de tokens
	t_list			*hdoc; // liste chainee (content + next) -> pour garder le contenu de heredoc 
	char			**envp_array; // array  qui comprend toutes les var d'environnement pour exec
	char      		**env_parse_array; // array qui ne comprend que les variables d'environnement relatives a la commande appelee
	int				quote;
	int				fd[2];
}					t_data;

/*- SRCS -*/
/*----main.c----*/

/*----init.c----*/
t_data		*init_minishell(int ac, char *av[], const char *envp[]);
void		init_types(t_data *d);
void		update_list(t_data *d);
void		init_args(t_data *d);

/*----listutils.c----*/
t_liste		*ft_list_new(char *subline);
t_token		*ft_token_new(char *content);
void		ft_add_back_list(t_liste **list, t_liste *new);
void		ft_add_back(t_token **token, t_token *new);
void		ft_add_front(t_token **token, t_token *new);
int			token_size(t_token *token);

/*----utils.c----*/
int 		get_array_size(char **array);
int 		ft_exit(t_data *data, char *print_message, int success_or_failure);


/*----check.c----*/
void		check_syntax(t_data *data);
int			check_cmd(const char *is_cmd);

/*----print_utils.c----*/
void		ft_print_array(char **array);
void		ft_print_lists(t_data *data);
char		*ft_strdup_lower(const char *s);
int			ft_strcmp(const char *s1, const char *s2);

/*----utils.c----*/
int			get_next_word_size(char *line, int i);
int			count_chars_in_array(char	**array);
int			is_builtin(char *content);
void 		remove_char(char *str, char char_to_remove);
int			skip_spaces(char *line, int index);
int			add_quote(char *line, int j);

/*----exec.c----*/
void		ft_execute(t_data *data, char *const *envp);
void		ft_exec(t_data *data, char *const *envp);
int			ft_access(t_data *data);
void	    here_doc(t_data *d);

/*----builtin.c----*/
void		pwd_cmd(void);
void		cd_cmd(t_data *d);
void		export_cmd(t_data *data);
void		echo_cmd(t_data *data);
void		unset_cmd(t_data *data);
void		exit_cmd(t_data *d);

/*--PARSING--*/
/*----parsing.c----*/
void		parse(char *line, t_data *data);

/*----parsing_tokens.c----*/
void		create_tokens(t_liste *list, char *subline);


/*----parsing_tokens_append.c----*/
void	    append_token(t_liste *list, char *subline, int start_of_token, int end_of_token, int *quote);
void		append_token_simple(t_liste *list, char *token, int *quote);

/*----parsing_tokens.c----*/
void		handle_unclosed_quotes(t_liste *list, char *subline, int *i, int *quote, int *start_of_token);
void		handle_token_create_end(t_liste *list, char *subline, int *i, int *quote, int *start_of_token);

/*--ENV--*/
/*----env.c----*/
char 		*get_env(t_data *data, char *var);
int      	count_env(char *line);
int			is_in_env(t_data *data, char *var);

/*----env_parsing.c----*/
char		*include_env_vars(t_data *data, char *line);
void		init_paths(t_data *d, const char *envp[]);
void		init_builtin(t_data *d);

/*----error.c----*/
void		ft_error(const char *msg);
int			ft_error_syntax(char *msg, char *arg, int i);

/*----free.c----*/
void		free_lists(t_data *data);
void		ft_free_array(char **array);
void		read_error(const char *msg);
void		free_all(t_data *data);

#endif