/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:27:09 by causilva          #+#    #+#             */
/*   Updated: 2025/12/01 19:58:55 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec_cmdtree.h"
#include "../../minishell.h"

int	builtin(char **argv, int fd_output, t_vars *vars)
{
	if (ft_strcmp(argv[0], "echo") == 0)
		return (builtin_echo(argv, fd_output));
	if (ft_strcmp(argv[0], "cd") == 0)
		return (builtin_cd(argv));
	if (ft_strcmp(argv[0], "pwd") == 0)
		return (builtin_pwd(fd_output));
	if (ft_strcmp(argv[0], "export") == 0)
		return (builtin_export(&argv[1], fd_output, vars));
	if (ft_strcmp(argv[0], "unset") == 0)
		return (builtin_unset(argv, vars->envp));
	if (ft_strcmp(argv[0], "env") == 0)
		return (builtin_env(vars->envp, fd_output));
	if (ft_strcmp(argv[0], "exit") == 0)
		return (builtin_exit(argv, vars));
	return (127);
}

int	is_builtin(char *name)
{
	return ((ft_strcmp(name, "echo") == 0)
		|| (ft_strcmp(name, "cd") == 0)
		|| (ft_strcmp(name, "pwd") == 0)
		|| (ft_strcmp(name, "export") == 0)
		|| (ft_strcmp(name, "unset") == 0)
		|| (ft_strcmp(name, "env") == 0)
		|| (ft_strcmp(name, "exit") == 0));
}
