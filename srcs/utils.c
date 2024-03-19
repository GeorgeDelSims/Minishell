/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:53:27 by gsims             #+#    #+#             */
/*   Updated: 2024/03/19 11:59:53 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		get_next_word_size(char *line, int i)
{
	int		count;
	
	count = 0;
	while (line[i] && line[i] != ' ')
	{
		count++;
		i++;
	}
	return (count);
}

int		count_chars_in_array(char	**array)
{
	int		i;
	int		j;
	int		count;
	
	count = 0;
	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			count++;
			j++;
		}
		i++;
	}
	return (count);	
}
