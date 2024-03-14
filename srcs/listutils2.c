/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listutils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:19:11 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/03/14 11:20:19 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	token_size(t_token *token)
{
	t_token	*current;
	int		counter;

	counter = 0;
	current = token;
	while (current != NULL)
	{
		current = current->next;
		counter++;
	}
	return (counter);
}
