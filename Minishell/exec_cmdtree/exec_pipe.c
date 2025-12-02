/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myivanov <myivanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:45:57 by causilva          #+#    #+#             */
/*   Updated: 2025/11/30 14:27:33 by myivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmdtree.h"
#include "../minishell.h"

static int	create_child(t_cmdtree *cmdtree, t_vars *vars, int pipes[2], int n);
static void	kill_childs(int childs_ids[2]);
void		memory_cleanup(t_vars vars);

int	exec_pipe(t_cmdtree *cmdtree, t_vars *vars)
{
	int	pipes[2];
	int	childs_ids[2];

	if (pipe(pipes) == -1)
		return (127);
	childs_ids[0] = create_child(cmdtree, vars, pipes, 1);
	childs_ids[1] = create_child(cmdtree, vars, pipes, 2);
	close(pipes[0]);
	close(pipes[1]);
	if (childs_ids[0] == -1 || childs_ids[1] == -1)
		return (kill_childs(childs_ids), 127);
	if (waitpid(childs_ids[0], &cmdtree->child1->exit_status, 0) == -1)
		return (kill_childs(childs_ids), 127);
	childs_ids[0] = 0;
	if (waitpid(childs_ids[1], &cmdtree->child2->exit_status, 0) == -1)
		return (kill_childs(childs_ids), 127);
	childs_ids[1] = 0;
	return (cmdtree->child2->exit_status);
}

static int	create_child(t_cmdtree *cmdtree, t_vars *vars, int pipes[2], int n)
{
	int	id;
	int	temp;

	id = fork();
	if (id == 0)
	{
		temp = 0;
		if (n == 1)
		{
			close(pipes[0]);
			cmdtree->fd_pipe = pipes[1];
			temp = exec_cmdtree(cmdtree->child1, vars);
		}
		if (n == 2)
		{
			close(pipes[1]);
			cmdtree->fd_pipe = pipes[0];
			temp = exec_cmdtree(cmdtree->child2, vars);
		}
		io_cleanup(*vars);
		memory_cleanup(*vars);
		exit(temp);
	}
	return (id);
}

static void	kill_childs(int childs_ids[2])
{
	if (childs_ids[0] > 0)
		kill(childs_ids[0], SIGINT);
	if (childs_ids[1] > 0)
		kill(childs_ids[1], SIGINT);
}
