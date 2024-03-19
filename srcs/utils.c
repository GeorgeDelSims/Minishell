/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:53:27 by gsims             #+#    #+#             */
/*   Updated: 2024/03/19 14:12:02 by gsims            ###   ########.fr       */
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

void remove_char(char *str, char char_to_remove) 
{
    char *src; 
    char *dst; 
	
	src = str;
	dst = str;
    while (*src) 
	{
        *dst = *src;
        if (*dst != char_to_remove)
			dst++;
		src++;
	}
    *dst = '\0';
}
