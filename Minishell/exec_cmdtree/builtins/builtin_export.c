/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:12:42 by causilva          #+#    #+#             */
/*   Updated: 2025/12/01 20:40:04 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec_cmdtree.h"
#include "../../minishell.h"

static int	check_name(char *str);
static int	get_posic(char **envp, char *name);
static void	replace_env(char **envp, int posic, char *str);
int			add_envp(char ***envp, char *str);

int	builtin_export(char **av, int fd_output, t_vars *vars)
{
	int		i;
	int		check;
	char	*str_dup;
	int		posic;

	if (!av[0])
		return (special_env(vars->envp, fd_output), 0);
	i = -1;
	while (av[++i])
	{
		check = check_name(av[i]);
		if (check == -1)
			ft_dprintf(2, "bash: export: %s: not a valid identifier\n", av[i]);
		if (check == -1 || check == 0)
			continue ;
		str_dup = ft_strdup(av[i]);
		if (!str_dup)
			return (1);
		posic = get_posic(vars->envp, str_dup);
		if (posic >= 0)
			replace_env(vars->envp, posic, str_dup);
		else if (add_envp(&vars->envp, str_dup) == -1)
			return (free(str_dup), 1);
	}
	return (0);
}

static int	check_name(char *str)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[i]) && str[i] != '_')
		return (-1);
	i++;
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (-1);
		i++;
	}
	if (str[i] != '=')
		return (0);
	return (1);
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
			&& envp[i][j] != '=' && name[j] != '=')
			j++;
		if (envp[i][j] == '=' && name[j] == '=')
			return (i);
		i++;
	}
	return (-1);
}

static void	replace_env(char **envp, int posic, char *str)
{
	free(envp[posic]);
	envp[posic] = str;
}

int	add_envp(char ***envp, char *str)
{
	char	**new_envp;
	int		len;
	int		i;

	if (!*envp)
		return (-1);
	len = 0;
	while ((*envp)[len])
		len++;
	new_envp = malloc((len + 2) * sizeof(char *));
	if (!new_envp)
		return (-1);
	i = -1;
	while (++i < len)
		new_envp[i] = (*envp)[i];
	new_envp[i] = str;
	new_envp[i + 1] = NULL;
	free(*envp);
	*envp = new_envp;
	return (0);
}
