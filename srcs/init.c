/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:10:58 by georgesims        #+#    #+#             */
/*   Updated: 2024/03/28 09:30:30 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Fonction pour initier les paths binaires 
// (necessaire pour l'execution des commandes)
// static void	init_binpaths(t_data *data)
// {
	// data->bin_paths = ft_split((const char *)getenv("PATH"), ':');
	// if (!data->bin_paths)
		// ft_error("PATH env variables not found.");
// }


// init environment function
void	init_env(t_data *data, const char *envp[])
{
	data->envp_array = (char **)envp;
}


// FONCTION MAIN POUR INITIER STRUCTURES ET DONNEES
t_data	*init_minishell(int ac, char *av[], const char *envp[])
{
	t_data	*data;

    if (ac < 1 || !av || !envp)  // Juste pour utiliser les variables dans un premier temps. 
        ft_error("no input.");
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		ft_error("malloc error on data structure");
	init_env(data, envp);
	// init_binpaths(data);
	return (data);
}

char	*find_cmd(t_data *d)
{
	t_liste	*tmp;
	t_token	*tmp_t;
	char	*ret;

	tmp = d->list;
	ret = ft_strdup("");
	while (tmp)
	{
		tmp_t = tmp->token;
		while (tmp_t)
		{
			if (tmp_t->type == CMD || tmp_t->type == BUILTIN)
				ret = ft_strjoin(ret, tmp_t->content);
			tmp_t = tmp_t->next;
		}
		tmp = tmp->next;
	}
	return (ret);
}

void	init_args(t_data *d)
{
	t_liste	*tmp;
	t_token	*tmp_t;
	char	*ret;

	ret = find_cmd(d);
	tmp = d->list;
	d->list->args = ft_split(ret, ' ');
	while (tmp)
	{
		tmp_t = tmp->token;
		while (tmp_t)
		{
			if (tmp_t->type != MET && tmp_t->type != CMD
				&& tmp_t->type != BUILTIN && tmp_t->type != FILENAME)
				ret = ft_strjoin(ret, ft_strjoin(" ", tmp_t->content));
			tmp_t = tmp_t->next; 
		}
		tmp = tmp->next;
	}
	d->list->args = ft_split(ret, ' ');
	free(ret);
}
