/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myivanov <myivanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:12:53 by causilva          #+#    #+#             */
/*   Updated: 2025/11/30 12:21:19 by myivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec_cmdtree.h"
#include "../../minishell.h"

static int	get_posic(char **envp, char *name);

int	builtin_unset(char **argv, char **envp)
{
	int		i;
	int		posic;

	i = 0;
	while (argv[++i])
	{
		posic = get_posic(envp, argv[i]);
		if (posic == -1)
			continue ;
		free(envp[posic]);
		while (envp[posic])
		{
			envp[posic] = envp[posic + 1];
			posic++;
		}
	}
	return (0);
}

static int	get_posic(char **envp, char *name)
{
	int	i;
	int	j;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && name[j]
			&& envp[i][j] == name[j]
			&& envp[i][j] != '=')
			j++;
		if (envp[i][j] == '=' && name[j] == '\0')
			return (i);
		i++;
	}
	return (-1);
}
