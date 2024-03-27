/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:02:05 by gsims             #+#    #+#             */
/*   Updated: 2024/03/27 10:59:11 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


// safe free array function (only for char arrays)
void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

// Function to free the lists and the tokens within the lists 
void	free_lists(t_data *data)
{
	t_liste		*curr_list;
	t_liste		*next_list;
	t_token		*curr_token;
	t_token		*next_token;
		
	curr_list = data->list;
	if (!curr_list)
		return ;
	while (curr_list)
	{
		curr_token = curr_list->token;
		while (curr_token)
		{
			free(curr_token->content);
			next_token = curr_token->next;
			free(curr_token);
			curr_token = NULL;
			curr_token = next_token;
		}
		// free((void *)curr_list->cmd_path);
		// ft_free_array(curr_list->args);
		curr_list->token = NULL;
		next_list = curr_list->next;
		free(curr_list);
		curr_list = next_list;
	}
	data->list = NULL;
}


// Free all recorded data from structures
void	free_all(t_data *data)
{
	if (data->bin_paths)
		ft_free_array(data->bin_paths);
	if (data->envp_array)
		ft_free_array(data->envp_array);
	if (data->env_parse_array)
		ft_free_array(data->env_parse_array);
	if (data->list)
		free_lists(data);
	if (data->hdoc)
		free(data->hdoc);
	free(data);
}

