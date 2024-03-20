
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


// Description needed
static char *get_env_str(t_data *data, char *line, int *i)
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
    if (get_env(data, tmp))
        newstr = ft_strdup(get_env(data, tmp));
    else
        newstr = NULL;
	free(tmp);
	tmp = NULL;
	*i += next_word_size - 1;
    return (newstr);
}

// For each dollar sign in the original line, 
// this function creates an element in the env_parse_array 
// in which it copies the string relative to the environment variable called by the dollar sign 
// if the dollar sign is not in front of a valid env variable, 
// the function returns a null pointer to its corresponding place in the array
static char **fill_env_parse_array(t_data *data, char *line)
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
			array[row] = get_env_str(data, line, &i);
            row++;
		}
		else
			i++;
    }
    array[row] = NULL;
    return (array); 
}

// checks the correct size and allocates memory for newline (to replace line) in order to accommodate env variable values
static char *get_newline(t_data *data, char *line)
{
    int     env_count;
    char    *newline;

	env_count = count_env(line);
	data->env_parse_array = fill_env_parse_array(data, line);
	newline = malloc(sizeof(char) * (ft_strlen(line) + count_chars_in_array(data->env_parse_array) + 1 + 2 * env_count));
	if (!newline)
		return (NULL);
	return (newline);
}


// adds quotes around env variables in newline in order to tokenise them correctlzy
static int	add_quote(char *newline, int j)
{
	newline[j] = '\"';
	j++;
	return (j);
}

/*
// Helper Function for include_env_vars into the newline 
static void add_env_var_to_newline(t_data *data, char *newline, int row)
{
    char    *temp;

    temp = newline;
    printf("temp : %s\n", temp);
    // if (data->env_parse_array && data->env_parse_array[0] != NULL)
    newline = ft_strjoin(temp, data->env_parse_array[row]);
    // else
        // This is where you recreate the line by deleting the word that follows the $ sign
    free(temp);
    temp = NULL;
}
*/
/*
static int  replace_env_vars(t_data *data, int *row, int j, char **newline)
{
    char    *temp;

    j = add_quote(*newline, j);
    *newline[j] = '\0';
    temp = *newline;
    *newline = ft_strjoin(temp, data->env_parse_array[*row]);
    free(temp);
    temp = NULL;
    j += ft_strlen(data->env_parse_array[*row]);
    j = add_quote(*newline, j);
    free(data->env_parse_array[*row]);
    row++;
    return (j);
}
*/

// Main function that includes the environment variables in the newline 
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
            if (data->env_parse_array[row] != NULL)
            {
                // j = replace_env_vars(data, &row, j, &newline);
                j = add_quote(newline, j);
                newline[j] = '\0';
                temp = newline;
                newline = ft_strjoin(temp, data->env_parse_array[row]);
                free(temp);
                temp = NULL;
                j += ft_strlen(data->env_parse_array[row]);
                j = add_quote(newline, j);
                free(data->env_parse_array[row]);
                row++;
            }
            else
            {
                row++;
                while (line[i] && line[i] != ' ')
                    i++;
            }
        }
        else
            newline[j++] = line[i++];
    }
    newline[j] = '\0';
	free(data->env_parse_array);
    return (newline);
}
