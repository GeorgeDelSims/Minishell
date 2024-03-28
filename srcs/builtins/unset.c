/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:35:31 by gsims             #+#    #+#             */
/*   Updated: 2024/03/28 09:32:50 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	len_until_equal(char *s)
{
	int	i;

	i = 0;
	while (s[i] != 61)
		i++;
	return (i);
}

// replicates the unset command -> remove environment variable into the envp 
void	unset_cmd(t_data *data)
{
	char		**new_array;
	int			array_size;
	int			len;
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
	while (i < array_size)
	{
		len = len_until_equal(data->envp_array[i]);
		if (ft_strncmp(data->envp_array[i], data->list->args[1], len) != 0)
			new_array[j++] = ft_strdup(data->envp_array[i]);
		i++;
	}
	new_array[j] == NULL;
	ft_free_array(data->envp_array);
	data->envp_array = new_array;
	ft_print_array(data->envp_array);
}
