/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:43:00 by gsims             #+#    #+#             */
/*   Updated: 2024/03/18 14:47:08 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int		count_env(char *line)
{
	int	i;
	int	count;

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


static char	*get_env_str(char *line, int *i)
{
	char 	*newstr;
	char	*tmp;
	int		next_word_size;
	
	while (line[*i])
	{
		if (line[*i] == '$')
		{
			(*i)++;
			next_word_size = get_next_word_size(line, *i) + 1;
			tmp = malloc(sizeof(char) * next_word_size);
			if (!tmp)
				return (NULL);
			ft_strlcpy(tmp, line + *i, next_word_size);
			newstr = ft_strdup(getenv(tmp));
			free(tmp);
			tmp = NULL;
		}
		(*i)++;
	}
	return (newstr);
}

static char	**fill_env_array(char *line)
{
	char	**array;
	int		row_count;
	int		row;
	int		i;

	i = 0;
	row = 0;
	row_count = count_env(line);
	array = (char **)malloc(sizeof(char *) * row_count + 1);
	if (!array)
		return (NULL);
	while (row < row_count)
	{
		array[row] = get_env_str(line, &i);
		row++;
	}
	array[row] = NULL;
	return (array);	
}

char	*include_env_vars(t_data *data, char *line)
{
	int		env_count;
	char	*newline;
	char	*temp;
	int		i;
	int		j;
	int		row;
	// checks for how many $ signs 
	env_count = count_env(line);
	// creates array for strings that will replace env variables
	data->env_array = fill_env_array(line);
	ft_print_array(data->env_array);
	// mallocs a newline with the size of line + contents of array
	newline = malloc(sizeof(char) * (ft_strlen(line) + count_chars_in_array(data->env_array) + 3));
	if (!newline)
		return (NULL);
	// iterates through line[i] and replaces env variables with strings from array into newline 
	i = 0;
	j = 0;
	row = 0;
	while (line[i])
	{
		if (line[i] == '$')
		{
			while(line[i] && line[i] != ' ')
				i++;
			newline[j] = '\"';
			j++;
			newline[j] = '\0';
			temp = newline;
			newline = ft_strjoin(temp, data->env_array[row]);
			free(temp);
			temp = NULL;
			j += ft_strlen(data->env_array[row]);
			newline[j] = '\"';
			j++;
			row++;
		}
		else
		{
			newline[j] = line[i];
			i++;
			j++;
		}
	}
	newline[j] = '\0';
	printf("newline at end of function : %s\n", newline);
	return (newline);
	// frees array
}

