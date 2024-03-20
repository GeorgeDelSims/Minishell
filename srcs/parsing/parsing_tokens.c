/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:32:11 by gsims             #+#    #+#             */
/*   Updated: 2024/03/20 14:06:47 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Opens the quotes when it encounters a second quote of a certain type
static void	open_quotes(char *subline, int *i, int *quote, int *start_of_token, int quote_type)
{
	if (subline[*(i) - 1] && subline[*(i) - 1] == ' ')
		*start_of_token = *i + 1;
	*quote = quote_type;
	*i = *i + 1;
}

// Closes the quotes when it encounters a second quote of a certain type
static void	close_quotes(t_liste *list, char *subline, int *i, int *quote, int *start_of_token)
{
	if (!subline[*(i) + 1])
		append_token(list, subline, *start_of_token, *i, quote);
	else if (subline[*(i) + 1] == ' ')
	{
		append_token(list, subline, *start_of_token, *i, quote);
		(*i)++;
		*start_of_token = *i;
	}
	else
	{
		while (subline[*i] && subline[*i] != ' ')
			(*i)++;
		append_token(list, subline, *start_of_token, *i, quote);
		*start_of_token = *i;
	}
	*quote = 0;
}

// Handles metacharacters(double and single)
static void	handle_meta(t_liste *list, char *subline, int *i, int *start_of_token)
{
	if ((subline[*i] == '>' && subline[*i + 1] == '>') || (subline[*i] == '<' && subline[*i + 1] == '<'))
	{
		if (*start_of_token != *i)
			append_token(list, subline, *start_of_token, *i, NULL);
		*start_of_token = *i;
		(*i) += 2;
		append_token(list, subline, *start_of_token, *i, NULL);
		*start_of_token = *i;			
	}
	else
	{
		if (*start_of_token != *i)
			append_token(list, subline, *start_of_token, *i, NULL);
		*start_of_token = *i;
		(*i)++;
		append_token(list, subline, *start_of_token, *i, NULL);
		*start_of_token = *i;
	}
}

// Handles the spaces in the case where quotes are not open
static void	handle_spaces(t_liste *list, char *subline, int *i, int *start_of_token)
{
	if (*start_of_token != *i)
		append_token(list, subline, *start_of_token, *i, NULL);
	while (subline[*i] == ' ')
		(*i)++;
	*start_of_token = *i;	
}

// Here we should append line to subline[i] until we reach the closed quote
// then we create one token with all the chars from subline[i] until end of line
static void	handle_unclosed_quotes(t_liste *list, char *subline, int *i, int *quote, int *start_of_token)
{
	char	*line;
	char	*token;
	char	*temp;
	int		j;
	
	j = 0;
	if (*i > *start_of_token && *quote == 0)
	{
		append_token(list, subline, *start_of_token, *i, NULL);
		return ;
	}
	else
	{
		token = ft_substr(subline, *start_of_token, *i - *start_of_token);
		while (1)
		{
			line = readline("> ");
			if (!line)
				break ;
			if (!(ft_strchr(line, '\'')) && !(ft_strchr(line, '\"')))
			{
				temp = token;
				token = ft_strjoin(temp, line);
				free(temp);
				temp = NULL;
			}
			if (*quote == SINGLE_QUOTE && ft_strchr(line, '\''))
			{
				j = 0;
				while (line[j] != '\'')
					j++;
				line[j + 1] = '\0'; // POTENTIAL MEMORY LEAK HERE exit! 
				temp = token;
				token = ft_strjoin(temp, line);
				free(temp);
				temp = NULL;
				append_token_simple(list, token, quote);
				break ;
			}
			else if (*quote == DOUBLE_QUOTE && ft_strchr(line, '\"'))
			{
				j = 0;
				while (line[j] != '\"')
					j++;
				line[j + 1] = '\0'; // POTENTIAL MEMORY LEAK HERE ! 
				temp = token;
				token = ft_strjoin(temp, line);
				free(temp);
				temp = NULL;
				append_token_simple(list, token, quote);
				break ;
			}
		}
	}
}

// Function iterates over the "Subline" linked lists and seperates into tokens
void	create_tokens(t_liste *list, char *subline)
{	
	int		i;
	int		quote;
	int		start_of_token;

	i = 0;
	start_of_token = 0;
	quote = 0;
	while (subline[i])
	{
		if (subline[i] == '\'' && quote == 0)
			open_quotes(subline, &i, &quote, &start_of_token, SINGLE_QUOTE);
		else if (subline[i] == '\"' && quote == 0) 
			open_quotes(subline, &i, &quote, &start_of_token, DOUBLE_QUOTE);
		else if ((subline[i] == '\"' && quote == DOUBLE_QUOTE) || (subline[i] == '\'' && quote == SINGLE_QUOTE))
			close_quotes(list, subline, &i, &quote, &start_of_token);
        else if ((subline[i] == '>' || subline[i] == '<') && quote == 0)
			handle_meta(list, subline, &i, &start_of_token);
		else if (subline[i] == ' ' && quote == 0) 
			handle_spaces(list, subline, &i, &start_of_token);
		else
			i++;
	}
	handle_unclosed_quotes(list, subline, &i, &quote, &start_of_token);
    // if (i > start_of_token && quote == 0)
        // append_token(list, subline, start_of_token, i, NULL);
}
