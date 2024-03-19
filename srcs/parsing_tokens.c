/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathieu <mathieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:32:11 by gsims             #+#    #+#             */
/*   Updated: 2024/03/19 07:09:19 by mathieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


void	append_token(t_liste *list, char *subline, int start_of_token, int end_of_token)
{
	char 	*token;
	int		token_size;

	token_size = end_of_token - start_of_token;
	token = malloc(sizeof(char) * (token_size + 1));
	if (!token)
		return ;
	ft_strlcpy(token, subline + start_of_token, token_size + 1);
	//printf("token = %s\n", token);
	ft_add_back(&list->token, ft_token_new(token));
}


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
		if (subline[i] == '\'' && quote == 0) // begin single quotes (START OF TOKEN)
		{
			quote = SINGLE_QUOTE;
			i++;
			start_of_token = i;
		}
		else if (subline[i] == '\"' && quote == 0) // begin double quotes " "
		{
			quote = DOUBLE_QUOTE;
			i++;
			start_of_token = i;
		}
		else if ((subline[i] == '\"' && quote == DOUBLE_QUOTE) || (subline[i] == '\'' && quote == SINGLE_QUOTE))
		{
			append_token(list, subline, start_of_token, i);
			quote = 0;
			i++;
			start_of_token = i;
		}
        else if ((subline[i] == '>' || subline[i] == '<') && quote == 0)
        {
            if ((subline[i] == '>' && subline[i + 1] == '>') || (subline[i] == '<' && subline[i + 1] == '<'))
			{
				if (start_of_token != i)
					append_token(list, subline, start_of_token, i);
				start_of_token = i;
				i += 2;
				append_token(list, subline, start_of_token, i);
				start_of_token = i;			
			}
			else
			{
				if (start_of_token != i)
					append_token(list, subline, start_of_token, i);
				start_of_token = i;
				i++;
				append_token(list, subline, start_of_token, i);
				start_of_token = i;
			}
		}
		else if (subline[i] == ' ' && quote == 0) 
		{
			if (start_of_token != i)
				append_token(list, subline, start_of_token, i);
			while (subline[i] == ' ')
				i++;
			start_of_token = i;
		}
		else
			i++;
	}
    if (i > start_of_token && quote == 0)
        append_token(list, subline, start_of_token, i);
}



/*
static int	next_word_size(char *subline, int i)
{
	int		len;
	int		quote;

	quote = 0;
	len = 0;
	while (subline[i])
	{
		if (subline[i] == '\"' && quote == 0)
		{
			quote = 2;
			i++;
		}	
		else if (subline[i] == '\'' && quote == 0)
		{
			quote = 1;
			i++;
		}
		if (subline[i] == ' ' && quote == 0)
			break ;	
		else if (subline[i] == '\"' && quote == 2)
		{
			quote = 0;
			i++;
			break ;
		}
		else if (subline[i] == '\'' && quote == 1)
		{
			quote = 0;
			i++;
			break ;
		}
		len++;
		i++;
	}
	return (len);
}

// Create tokens from sublines 
void	create_tokens(t_liste *list, char *subline)
{
	int		i;
	int		word_len;
	char	*word;

	i = 0;
	while (subline[i])
	{
		while (subline[i] == ' ')
			i++;
		word_len = next_word_size(subline, i);
		printf("word_len : %d\n", word_len);
		word = (char *)malloc(sizeof(char) * word_len + 1);
		if (!word)
			ft_error("malloc error in create_tokens function\n");
		if (subline[i] == ' ' || subline[i] == '\'' || subline[i] == '\"')
			i++;
		ft_strlcpy(word, subline + i, word_len + 1);
		word[word_len] = '\0';	
		if (word)
			ft_add_back(&list->token, ft_token_new(word));
		free(word);
		i += word_len + 1;
		while (subline[i] == ' ')
			i++;
	}
}

*/