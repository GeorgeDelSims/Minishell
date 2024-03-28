/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:27:47 by gsims             #+#    #+#             */
/*   Updated: 2024/03/28 11:07:40 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// returns a 0 if the arg is not valid for the export command, 1 if it is 
static int		is_valid_export_arg(char *arg)
{
	//int	len;
	int	i;

	if (!arg)
		return (0);
	//len = ft_strlen(arg);
	if (arg[0] == '=')
		return (0);
	i = 1;
	while(arg[i])
	{
		if (arg[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

// replicates the export command -> add environment variable into the envp 
void	export_cmd(t_data *data)
{
	char	**new_array;
	int		array_size;
	int		i;
	
	if (!data->list->args || !data->list->args[1])
		return ;
	if (!data || !is_valid_export_arg(data->list->args[1]) || get_array_size(data->list->args) < 2)
		return ;
	array_size = get_array_size(data->envp_array);
	new_array = malloc(sizeof(char *) * (array_size + 2));
	if (!new_array)
		ft_exit(data, "malloc error in export_cmd\n", EXIT_FAILURE);
	i = 0;
	while (i < array_size)
	{
		new_array[i] = ft_strdup(data->envp_array[i]);
		i++;
	}
	new_array[i] = ft_strdup(data->list->args[1]);
	new_array[i + 1] = NULL;
	//ft_free_array(data->envp_array);
	data->envp_array = new_array; // should we free envp_array before this line ?? 
	// ft_print_array(data->envp_array);
}
