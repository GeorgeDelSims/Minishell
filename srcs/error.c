/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:49:14 by gsims             #+#    #+#             */
/*   Updated: 2024/03/27 09:10:32 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_error(const char *msg)
{
	write(2, msg, ft_strlen(msg) + 1);
	write(2, "\n", 1);
	exit(1);
}

int	ft_error_syntax(char *msg, char *arg, int i)
{
	if (i == 0)
		printf("minishell: syntax error near unexpected token `%s'\n", msg);
	else if (i == 1)
		printf("minishell: %s\n", msg);
	else if (i == 2)
		printf("minishell: %s: %s\n", arg, msg);
	else if (i == 3)
		printf("minishell: cd: %s: %s\n", arg, msg);
	return (1);
}
