/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:04:27 by gsims             #+#    #+#             */
/*   Updated: 2024/03/20 09:47:50 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	is_in_env(t_data *data, char *var)
{
	int		i;
	
	i = 0;
	while (data->envp_array[i])
	{
		if (ft_strncmp(var, data->envp_array[i], ft_strlen(var)) == 0)
			return (i);
		i++;
	}
	return (0);
}

char *get_env(t_data *data, char *var)
{
	int		i;
	int		len;
	int		var_len;
	char	*res;
	
	i = is_in_env(data, var);
	if (i == 0)
		return (NULL);
	len = ft_strlen(data->envp_array[i]);
	var_len = ft_strlen(var);
	res = ft_substr(data->envp_array[i], var_len + 1, len - (var_len + 1));
	return (res);
}

int      count_env(char *line)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (line[i])
    {
        if (line[i] == '$')
            count++;
        i++;
    }
    return (count);
}
