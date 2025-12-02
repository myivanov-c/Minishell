/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmdtree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myivanov <myivanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:44:51 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/12/02 10:56:38 by myivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../parse_line.h"

t_cmdtree	*cmdtree_new_node(t_list *tokens);
int			cmdtree_expand(t_cmdtree *cmdtree);
int			is_redirection_token(char *str);

t_cmdtree	*create_cmdtree(t_list *tokens)
{
	t_list		*duptokens;
	t_cmdtree	*cmdtree;
	int			return_check;

	duptokens = ft_lstmap(tokens, (void *(*)(void *))dup_token, free_token);
	if (!duptokens)
		return (NULL);
	cmdtree = cmdtree_new_node(duptokens);
	if (!cmdtree)
		return (ft_lstclear(&duptokens, free_token), NULL);
	return_check = cmdtree_expand(cmdtree);
	if (return_check == -1)
		return (free_cmdtree(cmdtree), NULL);
	return (cmdtree);
}

int	init_children(t_cmdtree *cmd, t_split_result split)
{
	cmd->child1 = cmdtree_new_node(split.left);
	if (!cmd->child1)
	{
		ft_lstclear(&split.left, free_token);
		ft_lstclear(&split.right, free_token);
		return (-1);
	}
	cmd->child2 = cmdtree_new_node(split.right);
	if (!cmd->child2)
	{
		free_cmdtree(cmd->child1);
		cmd->child1 = NULL;
		ft_lstclear(&split.right, free_token);
		return (-1);
	}
	return (0);
}

int	expand_children(t_cmdtree *cmd)
{
	cmd->child1->parent = cmd;
	cmd->child2->parent = cmd;
	if (cmdtree_expand(cmd->child1) == -1)
		return (-1);
	if (cmdtree_expand(cmd->child2) == -1)
		return (-1);
	return (0);
}

int	process_operator_node(t_cmdtree *cmd)
{
	t_split_result	split;

	split = split_tokens(cmd->tokens, cmd->type);
	if (!split.left || !split.right)
		return (-1);
	if (init_children(cmd, split) == -1)
		return (-1);
	return (expand_children(cmd));
}

int	cmdtree_expand(t_cmdtree *cmd)
{
	t_list	*inner;

	cmd->type = cmdtree_calc_type(cmd);
	if (cmd->type >= 1 && cmd->type <= 3)
	{
		if (process_operator_node(cmd) == -1)
			return (-1);
	}
	else if (cmd->type == 0)
	{
		if (has_double_outer_parens(cmd->tokens))
			return (ft_dprintf(2,
					"arithmetic expressions are not supported\n"), 1);
		inner = dup_inner_tokens(cmd->tokens);
		if (!inner)
			return (-1);
		cmd->child1 = cmdtree_new_node(inner);
		if (!cmd->child1)
			return (ft_lstclear(&inner, free_token), -1);
		cmd->child1->parent = cmd;
		if (cmdtree_expand(cmd->child1) == -1)
			return (-1);
	}
	return (0);
}
