/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:02:05 by gsims             #+#    #+#             */
/*   Updated: 2024/03/18 17:10:25 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Safe freee pointer function (for all pointer types)
void	ft_free(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

// safe free array function (only for char arrays)
void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		ft_free(array[i]);
		i++;
	}
	ft_free(array);
}

// Function to free the lists and the tokens within the lists 
void	free_lists(t_data *data)
{
	t_liste		*curr_list;
	t_liste		*next_list;
	t_token		*curr_token;
	t_token		*next_token;
		
	curr_list = data->list;
	while (curr_list)
	{
		curr_token = curr_list->token;
		while (curr_token)
		{
			ft_free(curr_token->content);
			next_token = curr_token->next;
			ft_free(curr_token);
			curr_token = NULL;
			curr_token = next_token;
		}
		// ft_free((void *)curr_list->cmd_path);
		// ft_free_array(curr_list->args);
		curr_list->token = NULL;
		next_list = curr_list->next;
		ft_free(curr_list);
		curr_list = next_list;
	}
	data->list = NULL;
}
