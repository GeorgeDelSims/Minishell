/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 08:26:05 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/03/13 09:27:20 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*char_tolower(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

int	c_s(char *cl, char *s)
{
	if (ft_strncmp(char_tolower(cl), s, ft_strlen(s)) == 0)
		return (1);
	return (0);
}
void	ft_error_syntax(char *msg, int i)
{
	if (i == 0)
		printf("minishell: syntax error near unexpected token %s\n", msg);
	else if (i == 1)
		printf("minishell: %s\n", msg);
}

void	check_pipe(char **cl, int i)
{
	if (i == 0 && c_s(cl[i], "|"))
		ft_error_syntax("`|'", 0);
	else if (i == 0 && c_s(cl[i], "||"))
		ft_error_syntax("`||'", 0);
	else if (i != 0)
	{
		if (c_s(cl[i], "|") && c_s(cl[i + 1], "|"))
			ft_error_syntax("`|'", 0);
		else if (c_s(cl[i], "|") && c_s(cl[i + 1], "||"))
			ft_error_syntax("`||'", 0);
		else if (c_s(cl[i], "|||"))
			ft_error_syntax("`|'", 0);
		else if (c_s(cl[i], "||||"))
			ft_error_syntax("`||'", 0);
	}
}

void	check_synthax(char *line)
{
	char	**cl;
	int		i;

	i = 0;
	cl = ft_split((const char *)line, ' ');
	while (cl[i])
	{
		if (ft_strncmp(char_tolower(cl[i]), "pwd", 3) == 0 && cl[i + 1])
			ft_error_syntax("too many arguments", 1);
		if (!cl[i + 1] && (cl[i][0] == '>' || cl[i][0] == '<'))
			ft_error_syntax("`newline'", 0);
		else if (cl[i][0] == '>' || cl[i][0] == '<')
		{
			if (cl[i + 1][0] == '>')
				ft_error_syntax("`>'", 0);
			else if (cl[i + 1][0] == '<')
				ft_error_syntax("`<'", 0);
		}
		check_pipe(cl, i);
		i++;
	}
	ft_free_array(cl);
}
