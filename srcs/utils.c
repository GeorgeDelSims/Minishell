/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:29:03 by gsims             #+#    #+#             */
/*   Updated: 2024/03/26 15:29:14 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int get_array_size(char **array)
{
    int size;
    
    if (!array)
        return (0);
    size = 0;
    while (array[size])
        size++;
    return (size);
}

int ft_exit(t_data *data, char *print_message, int success_or_failure)
{
    printf("%s\n", print_message);
    free_all(data);
    exit(success_or_failure);
}
