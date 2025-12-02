/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:21:51 by causilva          #+#    #+#             */
/*   Updated: 2025/12/01 20:38:08 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmdtree.h"
#include "../minishell.h"

int		get_cmd_return(t_cmdtree *cmdtree, t_vars *vars, char **argv, int id);
char	*get_cmd_path(char *cmd, char **envp);
char	*try_paths(char **paths, char *cmd);
char	*get_path_from_env(char **envp);

int	exec_cmd(t_cmdtree *cmdtree, t_vars *vars)
{
	char	**argv;
	int		temp;
	int		id;

	if (redirect(cmdtree, vars) == -1)
		return (1);
	argv = get_argv_tokenlst(cmdtree->tokens);
	temp = 0;
	if (is_builtin(argv[0]))
	{
		temp = builtin(argv, cmdtree->fd_output, vars);
		return (free(argv), temp);
	}
	id = fork();
	if (id == -1)
		return (127);
	return (get_cmd_return(cmdtree, vars, argv, id));
}

int	get_cmd_return(t_cmdtree *cmdtree, t_vars *vars, char **argv, int id)
{
	char	*path;
	int		temp;

	if (id == 0)
	{
		dup2(cmdtree->fd_input, STDIN_FILENO);
		dup2(cmdtree->fd_output, STDOUT_FILENO);
		io_cleanup(*vars);
		path = get_cmd_path(argv[0], vars->envp);
		if (path)
			execve(path, argv, vars->envp);
		exit((free(argv), memory_cleanup(*vars), 127));
	}
	if (waitpid(id, &temp, 0) == -1)
		return (free(argv), 127);
	if (WIFSIGNALED(temp))
	{
		if (WTERMSIG(temp) == SIGINT)
			write(1, "\n", 1);
		return (free(argv), 128 + WTERMSIG(temp));
	}
	if (WIFEXITED(temp))
		return (free(argv), WEXITSTATUS(temp));
	return (0);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	char	*path_str;
	char	**paths;
	char	*result;

	if (cmd[0] == '/' || cmd[0] == '.')
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		else
			return (NULL);
	}
	path_str = get_path_from_env(envp);
	if (!path_str)
		return (ft_dprintf(2, "%s: command not found\n", cmd), NULL);
	paths = ft_split(path_str, ':');
	if (!paths)
		return (NULL);
	result = try_paths(paths, cmd);
	return (result);
}

char	*try_paths(char **paths, char *cmd)
{
	int		i;
	char	*temp;
	char	*full;

	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		full = ft_strjoin(temp, cmd);
		free (temp);
		if (access(full, X_OK) == 0)
		{
			free_array_split(paths);
			return (full);
		}
		free(full);
		i++;
	}
	free_array_split(paths);
	ft_dprintf(2, "%s: command not found\n", cmd);
	return (NULL);
}

char	*get_path_from_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}
