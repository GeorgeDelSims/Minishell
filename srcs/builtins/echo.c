/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathieu <mathieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 07:34:44 by mathieu           #+#    #+#             */
/*   Updated: 2024/03/27 08:39:47 by mathieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	echo_cmd(t_data *d)
{
	int	i;
	int	is_n;

	i = 1;
	is_n = 0;
	while (d->list->args[i])
	{
		if (ft_strcmp(d->list->args[i], "-n") == 0)
			is_n = 1;
		else
		{
			ft_putstr_fd(d->list->args[i], d->list->out);
			if (d->list->args[i + 1])
				ft_putchar_fd(' ', d->list->out);
		}
		i++;
	}
	if (!is_n)
		ft_putchar_fd('\n', d->list->out);
}
