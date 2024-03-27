/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:35:31 by gsims             #+#    #+#             */
/*   Updated: 2024/03/27 11:41:12 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


// replicates the unset command -> remove environment variable into the envp 
void	unset_cmd(t_data *data)
{
	char		**new_array;
	int			array_size;
	int			i;
	int			j;

	if (!data->list->args || !data->list->args[1])
		return ;
	array_size = get_array_size(data->envp_array);
	new_array = malloc(sizeof(char *) * (array_size));
	if (!new_array)
		ft_exit(data, "malloc error in export_cmd\n", EXIT_FAILURE);
	i = 0;
	j = 0;
	while (j < array_size)
	{
		if (data->envp_array[i] == data->list->args[1])
			i++;
		new_array[j++] = ft_strdup(data->envp_array[i++]);
	}
	new_array[j] = NULL;
	data->envp_array = new_array;
	ft_print_array(data->envp_array);
}
