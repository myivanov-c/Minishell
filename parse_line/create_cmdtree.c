/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmdtree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:44:51 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/11/26 19:16:54 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parse_line.h"

t_cmdtree	*cmdtree_new_node(t_list *tokens);
int     cmdtree_expand(t_cmdtree *cmdtree);
void    cmdtree_clear(t_cmdtree *tree);
int     is_redirection_token(char *str);

t_cmdtree	*create_cmdtree(t_list *tokens)
{
	t_list		*duptokens;
	t_cmdtree	*cmdtree;
	int     return_check;

	duptokens = ft_lstmap(tokens, (void *(*)(void *))dup_token, free_token);
	if (!duptokens)
		return (NULL);
	cmdtree = cmdtree_new_node(duptokens);
	if (!cmdtree)
		return (ft_lstclear(&duptokens, free_token), NULL);
	return_check = cmdtree_expand(cmdtree);
	if (return_check == -1)
		return (cmdtree_clear(cmdtree), NULL);
	return (cmdtree);
}

t_cmdtree	*cmdtree_new_node(t_list *tokens)
{
	t_cmdtree	*node;

	if (!tokens)
		return (NULL);
	node = malloc(sizeof(t_cmdtree));
	if (!node)
		return (NULL);
	node->tokens = tokens;
	node->type = -1;
	node->fd_input = -1;
	node->fd_output = -1;
	node->exit_status = 0;
	node->exec_status = 0;
	node->parent = NULL;
	node->child1 = NULL;
	node->child2 = NULL;
	node->cmd = NULL;
	return (node);
}

static void	update_paren_level(char *str, int *level)
{
	if (ft_strcmp(str, "(") == 0)
		(*level)++;
	else if (ft_strcmp(str, ")") == 0)
		(*level)--;
}

int	cmdtree_calc_type(t_cmdtree *cmdtree)
{
	t_token	*tok;
	t_list	*node;
	int		paren_level;
	int		type;

	node = cmdtree->tokens;
	paren_level = 0;
	type = 4;
	while (node)
	{
		tok = (t_token *)node->content;
		update_paren_level(tok->str, &paren_level);
		if (paren_level == 0)
		{
			if (ft_strcmp(tok->str, "&&") == 0)
				type = 2;
			else if (ft_strcmp(tok->str, "||") == 0)
				type = 3;
			else if (type == 4 && ft_strcmp(tok->str, "|") == 0)
				type = 1;
		}
		node = node->next;
	}
	return (type);
}


t_list	*get_split_point(t_list *tokens, int type)
{
	t_list	*node;
	t_list	*split;
	t_token	*tok;
	int		paren_level;

	paren_level = 0;
	node = tokens;
	split = NULL;
	while (node)
	{
		tok = (t_token *)node->content;
        update_paren_level(tok->str, &paren_level);
		if (paren_level == 0)
		{
			if (type == 1 && ft_strcmp(tok->str, "|") == 0)
				return (node);
			if (type == 2 && ft_strcmp(tok->str, "&&") == 0)
				split = node;
			else if (type == 3 && ft_strcmp(tok->str, "||") == 0)
				split = node;
		}
		node = node->next;
	}
	return (split);
}


t_list	*get_tokens_right(t_list *split_point)
{
	t_list	*right;
	t_list	*node;
	t_token	*dup;
	t_list	*new;

	right = NULL;
	node = split_point->next;
	while (node)
	{
		dup = dup_token((t_token *)node->content);
		if (!dup)
			return (ft_lstclear(&right, free_token), NULL);
		new = ft_lstnew(dup);
		if (!new)
		{
			free_token(dup);
			return (ft_lstclear(&right, free_token), NULL);
		}
		ft_lstadd_back(&right, new);
		node = node->next;
	}
	return (right);
}


t_list	*get_tokens_left(t_list *tokens, t_list *split_point)
{
	t_list	*left;
	t_list	*node;
	t_token	*dup;
	t_list	*new;

	left = NULL;
	node = tokens;
	while (node && node != split_point)
	{
		dup = dup_token((t_token *)node->content);
		if (!dup)
			return (ft_lstclear(&left, free_token), NULL);

		new = ft_lstnew(dup);
		if (!new)
		{
			free_token(dup);
			return (ft_lstclear(&left, free_token), NULL);
		}
		ft_lstadd_back(&left, new);
		node = node->next;
	}
	return (left);
}


t_split_result	split_tokens(t_list *tokens, int type)
{
	t_split_result	result;
	t_list			*split_point;

	result.left = NULL;
	result.right = NULL;
	split_point = get_split_point(tokens, type);
	if (!split_point)
	{
		result.left = tokens;
		return (result);
	}
	result.left = get_tokens_left(tokens, split_point);
	if (!result.left)
		return (result);
	result.right = get_tokens_right(split_point);
	if (!result.right)
	{
		ft_lstclear(&result.left, free_token);
		result.left = NULL;
	}
	return (result);
}


static int	has_outer_parens(t_list *tokens)
{
	t_list	*node;
	t_token	*tok;
	int		depth;

	node = tokens;
	tok = (t_token *)node->content;
	if (!tok || ft_strcmp(tok->str, "(") != 0)
		return (0);
	depth = 0;
	while (node)
	{
		tok = (t_token *)node->content;
		if (ft_strcmp(tok->str, "(") == 0)
			depth++;
		else if (ft_strcmp(tok->str, ")") == 0)
			depth--;
		if (depth == 0 && node->next)
			return (0);
		node = node->next;
	}
	return (depth == 0);
}


static t_list	*dup_inner_tokens(t_list *tokens)
{
	t_list	*new;
	t_list	*node;
	t_token	*dup;
	t_list	*node_new;

	new = NULL;
	node = tokens->next;
	while (node && node->next)
	{
		dup = dup_token((t_token *)node->content);
		if (!dup)
			return (ft_lstclear(&new, free_token), NULL);
		node_new = ft_lstnew(dup);
		if (!node_new)
		{
			free_token(dup);
			ft_lstclear(&new, free_token);
			return (NULL);
		}
		ft_lstadd_back(&new, node_new);
		node = node->next;
	}
	return (new);
}


static int	has_double_outer_parens(t_list *tokens)
{
	t_token	*tok1;
	t_token	*tok2;
	t_list	*node;
	t_list	*before_last;

	if (!tokens || !tokens->next || !tokens->next->next)
		return (0);
	tok1 = (t_token *)tokens->content;
	tok2 = (t_token *)tokens->next->content; 
	if (!tok1 || !tok2 || ft_strcmp(tok1->str, "(") != 0 
        || ft_strcmp(tok2->str, "(") != 0)
		return (0);
	node = tokens;
	while (node && node->next && node->next->next)
		node = node->next;
	before_last = node;
	if (!before_last || !before_last->next)
		return (0);
	tok1 = (t_token *)before_last->content;
	tok2 = (t_token *)before_last->next->content;
	if (!tok1 || !tok2 || ft_strcmp(tok1->str, ")") != 0 
        || ft_strcmp(tok2->str, ")") != 0)
		return (0);
	return (1);
}



t_list	*ft_lstremove_outer_parens(t_list *tokens)
{
	t_list	*new;

	if (!tokens || !tokens->next)
		return (tokens);
	if (!has_outer_parens(tokens) || has_double_outer_parens(tokens))
		return (tokens);
	new = dup_inner_tokens(tokens);
	ft_lstclear(&tokens, free_token);
	return (new);
}

void	cmdtree_clear(t_cmdtree *tree)
{
	if (!tree)
		return ;
	if (tree->tokens)
		ft_lstclear(&tree->tokens, free_token);
	if (tree->cmd)
		free_one_cmd(tree->cmd);
	if (tree->child1)
		cmdtree_clear(tree->child1);
	if (tree->child2)
		cmdtree_clear(tree->child2);
	free(tree);
}

static int	process_leaf_node(t_cmdtree *cmd)
{
    printf("[LEAF] parsing simple cmd...\n");
	cmd->cmd = parse_simple_cmd(cmd->tokens);
	if (!cmd->cmd)
		return (-1);
	return (0);
}

static int	init_children(t_cmdtree *cmd, t_split_result split)
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
		cmdtree_clear(cmd->child1);
		cmd->child1 = NULL;
		ft_lstclear(&split.right, free_token);
		return (-1);
	}
	return (0);
}

static int	expand_children(t_cmdtree *cmd)
{
	cmd->child1->parent = cmd;
	cmd->child2->parent = cmd;
	if (cmdtree_expand(cmd->child1) == -1)
		return (-1);
	if (cmdtree_expand(cmd->child2) == -1)
		return (-1);
	return (0);
}

static int	process_operator_node(t_cmdtree *cmd)
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
	cmd->tokens = ft_lstremove_outer_parens(cmd->tokens);
	if (!cmd->tokens)
		return (-1);
	cmd->type = cmdtree_calc_type(cmd);
	if (cmd->type >= 1 && cmd->type <= 3)
    {
		if (process_operator_node(cmd) == -1)
			return (-1);
    }
	else
		if (process_leaf_node(cmd) == -1)
			return (-1);
	return (0);
}
