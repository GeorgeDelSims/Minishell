/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:49:14 by gsims             #+#    #+#             */
/*   Updated: 2024/03/11 11:01:02 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	*ft_error(const char *msg)
{
	write(2, msg, ft_strlen(msg) + 1);
	write(2, "\n", 1);
	return (NULL);
}

