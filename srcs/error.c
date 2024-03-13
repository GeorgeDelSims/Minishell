/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathieu <mathieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:49:14 by gsims             #+#    #+#             */
/*   Updated: 2024/03/13 07:47:13 by mathieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	*ft_error(const char *msg)
{
	printf("minishell: %s\n", msg);
	// write(2, msg, ft_strlen(msg) + 1);
	// write(2, "\n", 1);
	exit(1);
}

