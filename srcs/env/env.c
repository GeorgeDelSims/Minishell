/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:04:27 by gsims             #+#    #+#             */
/*   Updated: 2024/03/27 15:15:52 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_in_env(t_data *data, char *var)
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

// get the next variable in the line (=any number of chars that come after a $)
// The dollar sign is included in the variable in this case if line[i] == $
char *get_env_var(char *line, int i)
{
    char    *var;
    int     next_word_size; 
    
	next_word_size = get_next_word_size(line, i) + 1;
	var = malloc(sizeof(char) * next_word_size);
	if (!var)
		return (NULL);
	ft_strlcpy(var, line + i, next_word_size);
    return (var);
}

// check if the variables are valid and replace them by the corresponding string
// replace them by null if they are invalid variables (i.e not in the envp[])
char *get_env_str(t_data *data, char *line, int *i)
{
    char    *newstr;
    char    *tmp;
    
	newstr = NULL;
	(*i)++;
    tmp = get_env_var(line, *i);
    if (get_env(data, tmp))
        newstr = get_env(data, tmp);
    else
        newstr = NULL;
	*i += ft_strlen(tmp) - 1;
	free(tmp);
	tmp = NULL;
    return (newstr);
}
