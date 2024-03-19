
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

static int      count_env(char *line)
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


static char *get_env_str(char *line, int *i)
{
    char    *newstr;
    char    *tmp;
    int     next_word_size;
    
	newstr = NULL;
	(*i)++;
	next_word_size = get_next_word_size(line, *i) + 1;
	tmp = malloc(sizeof(char) * next_word_size);
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, line + *i, next_word_size);
	newstr = ft_strdup(getenv(tmp));
	ft_free(tmp);
	tmp = NULL;
	*i += next_word_size - 1;
    return (newstr);
}

static char **fill_env_parse_array(char *line)
{
    char    **array;
    int     row_count;
    int     row;
    int     i;

    i = 0;
    row = 0;
    row_count = count_env(line);
    array = (char **)malloc(sizeof(char *) * (row_count + 1));
    if (!array)
        return (NULL);
    while (line[i] && row < row_count)
    {
		if (line[i] == '$' && line[i])
		{
			array[row] = get_env_str(line, &i);
			row++;
		}
		else
			i++;
    }
    array[row] = NULL;
	ft_print_array(array);
    return (array); 
}

// checks the correct size and allocates memory for line to accommodate env variable values
static char *get_newline(t_data *data, char *line)
{
    int     env_count;
    char    *newline;

	env_count = count_env(line);
	data->env_parse_array = fill_env_parse_array(line);
	printf("count chars in array : %d\n", count_chars_in_array(data->env_parse_array));
	newline = malloc(sizeof(char) * (ft_strlen(line) + count_chars_in_array(data->env_parse_array) + 1 + 2 * env_count));
	if (!newline)
		return (NULL);
	return (newline);
}

static int	add_quote(char *newline, int j)
{
	newline[j] = '\"';
	j++;
	return (j);
}

// is_env_var function to check if the word following the $ sign is actually an env variable 
// static int  is_env_var(char *line, int i)
// {
    // 
// }

char    *include_env_vars(t_data *data, char *line)
{
    char    *newline;
    char    *temp;
    int     i;
    int     j;
    int     row;
    
	newline = get_newline(data, line);
    i = 0;
    j = 0;
    row = 0;
    while (line[i])
    {
        if (line[i] == '$')
        {
            while(line[i] && line[i] != ' ')
                i++;
			j = add_quote(newline, j);
            newline[j] = '\0';
            temp = newline;
            newline = ft_strjoin(temp, data->env_parse_array[row]);
            ft_free(temp);
            temp = NULL;
            j += ft_strlen(data->env_parse_array[row]);
            j = add_quote(newline, j);
            row++;
        }
        else
            newline[j++] = line[i++];
    }
    newline[j] = '\0';
	ft_free_array(data->env_parse_array);
    return (newline);
}
