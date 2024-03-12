/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:10:58 by georgesims        #+#    #+#             */
/*   Updated: 2024/03/12 10:01:24 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Fonction pour initier les paths binaires 
// (necessaire pour l'execution des commandes)
static void	init_binpaths(t_data *data)
{
	data->bin_paths = ft_split((const char *)getenv("PATH"), ':');
	if (!data->bin_paths)
		ft_error("PATH env variables not found.");
}

// FONCTION MAIN POUR INITIER STRUCTURES ET DONNEES
t_data	*init_minishell(int ac, char *av[], const char *envp[])
{
	t_data	*data;

    if (ac < 1 || !av || !envp)  // Juste pour utiliser les variables dans un premier temps. 
        ft_error("no input.");
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (ft_error("malloc error on data structure"));
	init_binpaths(data);
	// Il faudra initialiser les listes chainees de tokens ici
	return (data);
}
