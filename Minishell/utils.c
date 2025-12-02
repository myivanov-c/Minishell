/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myivanov <myivanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:36:06 by causilva          #+#    #+#             */
/*   Updated: 2025/12/02 12:08:20 by myivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	memory_cleanup(t_vars vars)
{
	int	i;

	free_cmdtree(vars.cmdtree);
	i = 0;
	if (vars.envp)
		while (vars.envp[i])
			free(vars.envp[i++]);
	free(vars.envp);
	free(vars.heredocs);
	rl_clear_history();
}

void	free_cmdtree(t_cmdtree *cmdtree)
{
	if (!cmdtree)
		return ;
	free_cmdtree(cmdtree->child1);
	free_cmdtree(cmdtree->child2);
	ft_lstclear(&cmdtree->tokens, free_token);
	free(cmdtree);
}

void	io_cleanup(t_vars vars)
{
	int	i;

	i = 0;
	while (vars.heredocs[i] != -1)
	{
		close(vars.heredocs[i]);
		vars.heredocs[i] = -1;
		i++;
	}
	io_cleanup_cmdtree(vars.cmdtree);
}

void	io_cleanup_cmdtree(t_cmdtree *cmdtree)
{
	if (!cmdtree)
		return ;
	io_cleanup_cmdtree(cmdtree->child1);
	io_cleanup_cmdtree(cmdtree->child2);
	if (cmdtree->is_local_fd_input && cmdtree->fd_input != -1)
		close(cmdtree->fd_input);
	if (cmdtree->fd_pipe != -1)
		close(cmdtree->fd_pipe);
	if (cmdtree->is_local_fd_output && cmdtree->fd_output != -1)
		close(cmdtree->fd_output);
	cmdtree->fd_input = -1;
	cmdtree->fd_pipe = -1;
	cmdtree->fd_output = -1;
	cmdtree->is_local_fd_input = 0;
	cmdtree->is_local_fd_output = 0;
}

t_list	*jump_parenthesis(t_list *node)
{
	t_token	*token;
	int		count;

	if (!node || ((t_token *)node->content)->control != 1)
		return (NULL);
	token = node->content;
	count = 1;
	while (count > 0)
	{
		node = node->next;
		if (!node)
			return (NULL);
		token = node->content;
		count += (token->control == 1) - (token->control == 2);
	}
	return (node);
}
