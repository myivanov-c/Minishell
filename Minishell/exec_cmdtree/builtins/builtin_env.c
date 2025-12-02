/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myivanov <myivanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:13:27 by causilva          #+#    #+#             */
/*   Updated: 2025/11/30 12:21:06 by myivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec_cmdtree.h"
#include "../../minishell.h"

int	builtin_env(char **envp, int fd_output)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		write(fd_output, envp[i], ft_strlen(envp[i]));
		write(fd_output, "\n", 1);
		i++;
	}
	return (0);
}

int	special_env(char **envp, int fd_output)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		write(fd_output, "declare -x ", 11);
		write(fd_output, envp[i], ft_strlen(envp[i]));
		write(fd_output, "\n", 1);
		i++;
	}
	return (0);
}
