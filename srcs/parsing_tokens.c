/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:32:11 by gsims             #+#    #+#             */
/*   Updated: 2024/03/13 09:52:16 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	next_word_size(char *subline, int i)
{
	int	start;
	
	start = i;
	while (subline[i])
	{
		if (subline[i] == ' ')
			return (i - start);
		i++;
	}
	return (i - start);
}

static int	ft_count_words(char *subline)
{
	int	count;

	if (!*subline)
		return (0);
	count = 0;
	while (*subline)
	{
		while (*subline == ' ')
			subline++;
		if (*subline)
			count++;
		while (*subline != ' ' && *subline)
			subline++;
	}
	return (count);
}

// Create tokens from sublines 
void	create_tokens(t_liste *list, char *subline)
{
	int		i;
	int		j;
	int		number_of_words;
	char	*word;

	i = 0;
	number_of_words = ft_count_words(subline);
	while (number_of_words > 0)
	{
		word = (char *)malloc(sizeof(char) * next_word_size(subline, i) + 1);
		if (!word)
			ft_error("malloc error in create_tokens function\n");
		j = 0;
		while (subline[i] && subline[i] != ' ')
			word[j++] = subline[i++];
		word[j] = '\0';
		while (subline[i] == ' ')
			i++;
		ft_add_back(&list->token, ft_token_new(word));
		free(word);
		number_of_words--;
	}
}
