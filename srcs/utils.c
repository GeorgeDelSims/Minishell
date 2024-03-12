/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:20:58 by gsims             #+#    #+#             */
/*   Updated: 2024/03/12 14:31:34 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Print array pour tester / debugger
void	ft_print_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		ft_printf("array[%d] : %s\n", i, array[i]);
		i++;
	}
}

// Void print_list()
void	ft_print_lists(t_data *data)
{
	t_liste		*curr_list;
	t_token		*curr_token;
	
	curr_list = data->list;
	while (curr_list)
	{
		curr_token = curr_list->token;
		if (curr_list->subline)
			printf("subline : %s\n", curr_list->subline);
		while (curr_token)
		{
			if (curr_token->content)
				printf("%20s\n", curr_token->content);
			curr_token = curr_token->next;
		}
		curr_list = curr_list->next;
	}
}	