/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathieu <mathieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:14:32 by mathieu           #+#    #+#             */
/*   Updated: 2024/03/12 15:04:09 by mathieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	c_s(char *cl, char *s)
{
	if (ft_strncmp(ft_tolower(cl), s, ft_strlen(s)) == 0)
		return (1);
	return (0);
}

int	check_pipe(char **cl, int i)
{
	if (i == 0 && c_s(cl[i], "|"))
		return (ft_error("syntax error near unexpected token `|'"));
	else if (i == 0 && c_s(cl[i], "||"))
		return (ft_error("syntax error near unexpected token `||'"));
	else if (i != 0)
	{
		if (c_s(cl[i], "|") && c_s(cl[i + 1], "|"))
			return (ft_error("syntax error near unexpected token `|'"));
		else if (c_s(cl[i], "|") && c_s(cl[i + 1], "||"))
			return (ft_error("syntax error near unexpected token `||'"));
		else if (c_s(cl[i], "|||"))
			return (ft_error("syntax error near unexpected token `|'"));
		else if (c_s(cl[i], "||||"))
			return (ft_error("syntax error near unexpected token `||'"));
	}
	return (1);
}

int	check_synthax(char *line)
{
	char	**cl;
	int		i;

	i = 0;
	cl = ft_split((const char *)line, ' ');
	while (cl[i])
	{
		if (ft_strncmp(ft_tolower(cl), "pwd", 3) == 0 && i != 0)
			ft_error("too many arguments");
		if (!cl[i + 1] && (cl[i][0] == '>' || cl[i][0] == '<'))
			ft_error("syntax error near unexpected token `newline'");
		else if (cl[i][0] == '>' || cl[i][0] == '<')
		{
			if (cl[i + 1][0] == '>')
				ft_error("syntax error near unexpected token `>'");
			else if (cl[i + 1][0] == '<')
				ft_error("syntax error near unexpected token `<'");
		}
		if (!check_pipe(cl, i))
			return (1);
		i++;
	}
	return (0);
}