/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathieu <mathieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:30:26 by mathieu           #+#    #+#             */
/*   Updated: 2024/03/20 23:09:27 by mathieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include <limits.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	pwd_cmd(void)
{
	char	s[2000];

	getcwd(s, 2000);
	ft_putstr_fd(s, 1);
	ft_putstr_fd("\n", 1);
}

int	main(void)
{
	pwd_cmd();
	return (0);
}