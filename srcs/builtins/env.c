/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:31:27 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/03/27 11:35:28 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	env_cmd(t_data *d)
{
	int	i;
	
	i = 0;
	if (!d)
		return ;
	else
	{
		while (d->envp_array[i])
		{
			if (d->envp_array[i])
				printf("%s\n", d->envp_array[i]);
			i++;
		}
	}
}
