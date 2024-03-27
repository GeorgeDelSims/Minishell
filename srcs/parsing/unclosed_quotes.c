/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unclosed_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:48:22 by gsims             #+#    #+#             */
/*   Updated: 2024/03/27 09:35:03 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Joins the given token to line (for use in case of unclosed quotes)
// It also adds a newline character for each newline typed into the stdin
static void	join_token_to_line(char **token, char *line)
{
	char *temp;
	char *token_with_newline;

	temp = *token;
	token_with_newline = ft_strjoin(temp, "\n");
	free(temp);
	temp = token_with_newline;
	*token = ft_strjoin(temp , line);
	free(temp);
}

// Does what it says on the box
static void	remove_chars_after_quote(t_liste *list, char **token, char *line, int *quote, char quote_type)
{
	int	j;
	
	j = 0;
	printf("line : %s\n", line);
	while (line[j] && line[j] != quote_type)
		j++;
	line[j] = '\0'; // POTENTIAL MEMORY LEAK HERE exit! 
	join_token_to_line(token, line);
	append_token_simple(list, *token, quote);
}

// MAIN FUNCTION that appends line to subline[i] until we reach the closed quote
// then we create one token with all the chars from subline[i] until end of line
void	handle_unclosed_quotes(t_liste *list, char *subline, int *i, int *quote, int *start_of_token)
{
	char	*line;
	char	*token;

	token = ft_substr(subline, *start_of_token, *i - *start_of_token);
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (!(ft_strchr(line, '\'')) && !(ft_strchr(line, '\"')))
			join_token_to_line(&token, line);
		if (*quote == SINGLE_QUOTE && ft_strchr(line, '\''))
		{
			remove_chars_after_quote(list, &token, line, quote, '\'');
			break ;
		}
		else if (*quote == DOUBLE_QUOTE && ft_strchr(line, '\"'))
		{
			remove_chars_after_quote(list, &token, line, quote, '\"');
			break ;
		}
	}
}

// End fork function for the create_tokens function, 
// if quotes are closed, it tokenises the last word
// if quotes are still open, it moves to handle_unclosed_quotes
void	handle_token_create_end(t_liste *list, char *subline, int *i, int *quote, int *start_of_token)
{
	if (((*quote == SINGLE_QUOTE && subline[*i - 1] == '\'') || 
		(*quote == DOUBLE_QUOTE && subline[*i - 1] == '\"')) 
			&& subline[*i - 2] != ' ')
		*quote = 0;
	else if (*i > *start_of_token && *quote == 0)
	{
		append_token(list, subline, *start_of_token, *i, NULL);
		return ;
	}
	else if (*quote == SINGLE_QUOTE || *quote == DOUBLE_QUOTE)
		handle_unclosed_quotes(list, subline, i, quote, start_of_token);
	else
		return ;
}