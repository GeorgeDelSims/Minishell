/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:57:15 by georgesims        #+#    #+#             */
/*   Updated: 2024/03/18 22:13:07 by mathieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Count the number of pipes in a line
static  int		pipe_count(char *line)
{
	int	i;
	int	pipe_count;
	
	i = 0;
	pipe_count = 0;
	while (line[i])
	{
		if (line[i] == '|')
			pipe_count++;
		i++;
	}
	return (pipe_count);
}

// Count the number of chars to next pipe (or to End of line)
static int		count_to_next_pipe(char *line, int i)
{
	int 	start;
	
	start = i;
	while (line[i])
	{
		if (line[i] == '|')
			return (i - start);
		i++;
	}
	return (i - start);
	
}

// Separe la ligne en sub-lignes et mets chacune d'elles dans une node de la liste chainée
static void	create_sublines(char *line, t_data *data)
{
	int			i;
	int			j;
	int			number_of_sublines;
	char 		*subline_temp;
	
	number_of_sublines = pipe_count(line) + 1;
	i = 0;
	while (number_of_sublines > 0)
	{
		subline_temp = (char *)malloc(sizeof(char) * count_to_next_pipe(line, i) + 1);
		if (!subline_temp)
			ft_error("Malloc error in create_sublines (parsing.c)");
		j = 0;
		while (line[i] && line[i] != '|')
			subline_temp[j++] = line[i++];
		subline_temp[j] = '\0';
		while (line[i] == '|' || line[i] == ' ')
			i++;
		ft_add_back_list(&data->list, ft_list_new(subline_temp));
		ft_free(subline_temp);
		number_of_sublines--;
	}
}

void	parse(char *line, t_data *data)
{
	t_liste		*curr;

	create_sublines(line, data);
	curr = data->list;
	while (curr->next)
	{
		create_tokens(curr, curr->subline);
		curr = curr->next;
	}
	create_tokens(curr, curr->subline);
	init_types(data);
	check_syntax(data);
	update_list(data);
	ft_print_lists(data);
}
