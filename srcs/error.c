/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:49:14 by gsims             #+#    #+#             */
/*   Updated: 2024/03/18 14:21:54 by mlepesqu         ###   ########.fr       */
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

void	read_error(const char *msg)
{
	write(2, msg, ft_strlen(msg) + 1);
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}
