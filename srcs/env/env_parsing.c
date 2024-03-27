
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

#include "../../includes/minishell.h"


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


// Substract the size of the env variable or anything that comes after the $ sign 
// and add the size of the env variable value (+ quotes)
int get_new_string_size(t_data *data, char *line) 
{
    int     total_size;
    int     i;
    int     env_var_length;
    char    *var;
    int     row;

    i = 0;
    total_size = ft_strlen(line) + 1;
    row = 0;
    while (line[i]) 
    {
        if (line[i] == '$') 
        {
            var = get_env_var(line, i);
            if (is_in_env(data, var) != 0)
                row++;
            env_var_length = ft_strlen(data->env_parse_array[row]) + 2;
            total_size += env_var_length - ft_strlen(var);
            i += ft_strlen(var);
            free(var);
        } 
        else
            i++;
    }
    return (total_size);
}

// checks the correct size and allocates memory for newline (to replace line) in order to accommodate env variable values
static char *get_newline(t_data *data, char *line)
{
    int     env_count;
    char    *newline;

	env_count = count_env(line);
	data->env_parse_array = fill_env_parse_array(data, line);
    // ft_print_array(data->env_parse_array);
	newline = malloc(sizeof(char) * (get_new_string_size(data, line))); // PROBLEM IS HERE
	if (!newline)
		return (NULL);
	return (newline);
}

// replaces $USER by "gsims" or "mlepesqu" (quotation marks included) in order to tokenize
static int replace_env_vars(t_data *data, int *row, int j, char **newline) 
{
    char *temp;

    j = add_quote(*newline, j);
    (*newline)[j] = '\0';
    temp = *newline;
    if (temp && data->env_parse_array[*row])
    {
        *newline = ft_strjoin(temp, data->env_parse_array[*row]); 
        j += ft_strlen(data->env_parse_array[*row]);
        j = add_quote(*newline, j);
        free(temp);
        // free(data->env_parse_array[*row]);
        // data->env_parse_array[*row] = NULL;
    }
    (*row)++; 
    data->quote = 0;
    return (j);
}

// Main function that includes the environment variables in the newline 
char    *include_env_vars(t_data *data, char *line)
{
    char    *newline;
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
            i = skip_spaces(line, i);
            if (data->env_parse_array && data->env_parse_array[row] && newline)
                j = replace_env_vars(data, &row, j, &newline);
            else
            {
                row++;
                i = skip_spaces(line, i);
            }
        }
        else
            newline[j++] = line[i++];
    }
    newline[j] = '\0';
    return (newline);
}
