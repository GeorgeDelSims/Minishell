
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
        newstr = get_env(data, tmp);
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
    ft_print_array(data->env_parse_array);
	newline = malloc(sizeof(char) * (ft_strlen(line) + count_chars_in_array(data->env_parse_array) + 1 + 200 * env_count)); // PROBLEM IS HERE
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
        *newline = ft_strjoin(temp, data->env_parse_array[*row]); // ABORT TRAP HERE FOR SOME REASON --> Sorted
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
    // printf("newline : %s\n", newline);
	// free(data->env_parse_array);
    return (newline);
}
