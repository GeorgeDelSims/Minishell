/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 08:26:05 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/03/18 09:05:48 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// char	*char_tolower(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		str[i] = ft_tolower(str[i]);
// 		i++;
// 	}
// 	return (str);
// }

// int	c_s(char *cl, char *s)
// {
// 	if (ft_strncmp(char_tolower(cl), s, ft_strlen(s)) == 0)
// 		return (1);
// 	return (0);
// }
int	ft_error_syntax(char *msg, int i)
{
	if (i == 0)
		printf("minishell: syntax error near unexpected token `%s'\n", msg);
	else if (i == 1)
		printf("minishell: %s\n", msg);
	return (1);
}

// int	check_pipe(char **cl, int i)
// {
// 	if (i == 0 && c_s(cl[i], "|"))
// 		return (ft_error_syntax("`|'", 0));
// 	else if (i == 0 && c_s(cl[i], "||"))
// 		return (ft_error_syntax("`||'", 0));
// 	else if (i != 0)
// 	{
// 		if (c_s(cl[i], "|") && c_s(cl[i + 1], "|"))
// 			return (ft_error_syntax("`|'", 0));
// 		else if (c_s(cl[i], "|") && c_s(cl[i + 1], "||"))
// 			return (ft_error_syntax("`||'", 0));
// 		else if (c_s(cl[i], "|||"))
// 			return (ft_error_syntax("`|'", 0));
// 		else if (c_s(cl[i], "||||"))
// 			return (ft_error_syntax("`||'", 0));
// 	}
// 	return (0);
// }

// void	check_syntax(char *line)
// {
// 	char	**cl;
// 	int		i;

// 	i = 0;
// 	cl = ft_split((const char *)line, ' ');
// 	while (cl[i])
// 	{
// 		if (ft_strncmp(char_tolower(cl[i]), "pwd", 3) == 0 && cl[i + 1])
// 		{
// 			ft_error_syntax("too many arguments", 1);
// 			break ;
// 		}
// 		if (!cl[i + 1] && (cl[i][0] == '>' || cl[i][0] == '<'))
// 		{
// 			ft_error_syntax("`newline'", 0);
// 			break;
// 		}
// 		else if (cl[i][0] == '>' || cl[i][0] == '<')
// 		{
// 			if (cl[i + 1][0] == '>')
// 				ft_error_syntax("`>'", 0);
// 			else if (cl[i + 1][0] == '<')
// 				ft_error_syntax("`<'", 0);
// 			break ;
// 		}
// 		if (check_pipe(cl, i) == 1)
// 			break ;
// 		i++;
// 	}
// 	ft_free_array(cl);
// }

void	check_syntax(t_data *d)
{
	t_liste	*tmp;
	t_token	*tmp_t;

	tmp = d->list;
	while (tmp)
	{
		tmp_t = tmp->token;
		while (tmp_t)
		{
			if (tmp_t->type == MET && tmp_t->next->type
				&& tmp_t->next->type == MET && tmp->next)
				ft_error_syntax(tmp_t->next->content, 0);
			tmp_t = tmp_t->next;
		}
		tmp = tmp->next;
	}
}