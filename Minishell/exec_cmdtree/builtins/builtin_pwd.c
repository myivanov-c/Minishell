/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myivanov <myivanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:52:42 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/11/30 12:21:16 by myivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec_cmdtree.h"
#include "../../minishell.h"

int	builtin_pwd(int fd_output)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (perror("pwd"), 1);
	write(fd_output, cwd, ft_strlen(cwd));
	write(fd_output, "\n", 1);
	free(cwd);
	return (0);
}
