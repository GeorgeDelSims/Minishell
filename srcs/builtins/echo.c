/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 07:34:44 by mathieu           #+#    #+#             */
/*   Updated: 2024/03/27 11:03:54 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_n(char *s)
{
	if (ft_strcmp(s, "-n") == 0)
		return (1);
	else
		return (0);
}

void	echo_cmd(t_data *d)
{
	int	i;
	int	ret;

	i = 1;
	ret = 0;
	while (d->list->args[i])
	{
		if (is_n(d->list->args[i]) && (!ft_strcmp(d->list->args[i - 1], "echo")
			|| is_n(d->list->args[i - 1])))
			ret = 1;
		else
		{
			ft_putstr_fd(d->list->args[i], d->list->out);
			if (d->list->args[i + 1])
				ft_putchar_fd(' ', d->list->out);
		}
		i++;
	}
	if (!ret)
		ft_putchar_fd('\n', d->list->out);
}
