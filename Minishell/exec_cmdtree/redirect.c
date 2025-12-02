/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myivanov <myivanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:56:12 by causilva          #+#    #+#             */
/*   Updated: 2025/12/02 11:58:30 by myivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmdtree.h"
#include "../minishell.h"

static int	redirect_input(t_cmdtree *cmdtree, t_list *token_node, int *hdocs);
static int	redirect_output(t_cmdtree *cmdtree, t_list *token_node);
static void	remove_heredoc(int *hdoc, int heredoc);

int	redirect(t_cmdtree *cmdtree, t_vars *vars)
{
	t_list	*token_node;
	t_token	*token;
	int		temp;

	token_node = cmdtree->tokens;
	temp = 0;
	while (token_node)
	{
		if (((t_token *)token_node->content)->control == 1)
			token_node = jump_parenthesis(token_node);
		token = token_node->content;
		if (token->control == 6 || token->control == 7)
			temp = redirect_input(cmdtree, token_node, vars->heredocs);
		if (token->control == 8 || token->control == 9)
			temp = redirect_output(cmdtree, token_node);
		if (temp == -1)
			return (-1);
		token_node = token_node->next;
		if (token->control == 6 || token->control == 7
			|| token->control == 8 || token->control == 9)
			token_node = token_node->next;
	}
	return (0);
}

static int	redirect_input(t_cmdtree *cmdtree, t_list *token_node, int *hdocs)
{
	t_token	*token;
	t_token	*next;
	int		temp;

	token = token_node->content;
	next = token_node->next->content;
	temp = 0;
	if (cmdtree->is_local_fd_input && cmdtree->fd_input != -1)
		close(cmdtree->fd_input);
	if (token->control == 7)
	{
		temp = open(next->str, O_RDONLY);
		if (temp == -1)
			ft_dprintf(2, "minishel: %s: %s\n", next->str, strerror(errno));
		else
		{
			cmdtree->fd_input = temp;
			cmdtree->is_local_fd_input = 1;
		}
		return (temp);
	}
	cmdtree->fd_input = next->fd_heredoc;
	cmdtree->is_local_fd_input = 1;
	remove_heredoc(hdocs, next->fd_heredoc);
	return (temp);
}

static int	redirect_output(t_cmdtree *cmdtree, t_list *token_node)
{
	t_token	*token;
	t_token	*token_next;
	int		temp;
	int		o_flag;

	token = token_node->content;
	token_next = token_node->next->content;
	temp = 0;
	if (cmdtree->is_local_fd_output && cmdtree->fd_output != -1)
		close(cmdtree->fd_output);
	o_flag = O_WRONLY | O_TRUNC | O_CREAT;
	if (token->control == 8)
		o_flag = O_WRONLY | O_APPEND | O_CREAT;
	temp = open(token_next->str, o_flag, 0666);
	if (temp == -1)
		ft_dprintf(2, "minishel: %s: %s\n", token_next->str, strerror(errno));
	else
	{
		cmdtree->fd_output = temp;
		cmdtree->is_local_fd_output = 1;
	}
	return (temp);
}

static void	remove_heredoc(int *hdocs, int heredoc)
{
	int	i;

	i = 0;
	while (hdocs[i] != -1 && hdocs[i] != heredoc)
		i++;
	while (hdocs[i] != -1)
	{
		hdocs[i] = hdocs[i + 1];
		i++;
	}
}
