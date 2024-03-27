/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tokens_append.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:07:29 by gsims             #+#    #+#             */
/*   Updated: 2024/03/27 09:20:30 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Appends a token onto the linked list of tokens 
void	append_token(t_liste *list, char *subline, int start_of_token, int end_of_token, int *quote)
{
	char 	*token;
	int		token_size;

	token_size = end_of_token - start_of_token;
	token = malloc(sizeof(char) * (token_size + 1));
	if (!token)
		return ;
	ft_strlcpy(token, subline + start_of_token, token_size + 1);
	if (quote != NULL)
	{
		if (*quote == SINGLE_QUOTE && ft_strchr(token, '\''))
			remove_char(token, '\'');
		else if (*quote == DOUBLE_QUOTE && ft_strchr(token, '\"'))
			remove_char(token, '\"');
	}
	ft_add_back(&list->token, ft_token_new(token));
}

// Appends a token onto the linked list of tokens (for the unclosed quotes situation)
void	append_token_simple(t_liste *list, char *token, int *quote)
{
	if (quote != NULL)
	{
		if (*quote == SINGLE_QUOTE && ft_strchr(token, '\''))
			remove_char(token, '\'');
		else if (*quote == DOUBLE_QUOTE && ft_strchr(token, '\"'))
			remove_char(token, '\"');
	}
	ft_add_back(&list->token, ft_token_new(token));
}
