/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:32:11 by gsims             #+#    #+#             */
/*   Updated: 2024/03/13 18:13:28 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


/*

static int	next_word_size(char *subline, int i)
{
	int		len;
	char	quote;
	
	len = 0;
	quote = 0;
	while (subline[i])
	{
		if ((subline[i] == '\"' || subline[i] == '\'') && quote == 0)
		{
			if (i == 0)
			{
				i++;
				quote = subline[i];
				break ;
			}
			else
			{
				quote = subline[i];
				i++;
			}
		}
		else if (subline[i] == quote)
		{
			quote = 0;
			i++;
			break ;
		}
		else if (subline[i] == ' ' && quote == 0)
			break ;
		else
		{
			i++;
			len++;
		}
	}
	printf("quote : %c\n", quote);
	printf("i : %d\n", i);
	return (len);
}*/

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



/*
static int	ft_count_words(char *subline)
{
	int		count;
	char	quote;

	if (!*subline)
		return (0);
	count = 0;
	quote = 0;
	while (*subline)
	{
		while (*subline == ' ' && quote == 0)
			subline++;
		if (*subline == ' ' && quote == 0)
			break ;
		if ((*subline == '\"' || *subline == '\'') && quote == 0)
			quote = *subline;
		else if (*subline == quote)
			quote = 0;
		count++;
        while (*subline && (quote != 0 || *subline != ' ')) 
		{
            if (*subline == quote) 
				quote = 0;
			subline++;
        }
	}
	return (count);
}
*/