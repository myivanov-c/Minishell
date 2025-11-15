/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmdtree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:44:51 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/11/15 11:44:06 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"
#include "parse_line.h"

t_cmdtree	*cmdtree_new_node(t_list *tokens);
int     cmdtree_expand(t_cmdtree *cmdtree);
void    cmdtree_clear(t_cmdtree *tree);

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

int	cmdtree_calc_type(t_cmdtree *cmdtree)
{
	t_token	*tok;
	t_list	*node;
	int		lowest_so_far;
	int		paren_level;

	lowest_so_far = 4;
	node = cmdtree->tokens;
	paren_level = 0;
	while (node)
	{
		tok = (t_token *)node->content;
		if (ft_strcmp(tok->str, "(") == 0)
			paren_level++;
		else if (ft_strcmp(tok->str, ")") == 0)
			paren_level--;
		else if (paren_level == 0)
		{
            if (ft_strcmp(tok->str, "|") == 0 && 1 < lowest_so_far)
				lowest_so_far = 1;
			else if (ft_strcmp(tok->str, "&&") == 0 && 2 < lowest_so_far)
				lowest_so_far = 2;
			else if (ft_strcmp(tok->str, "||") == 0 && 3 < lowest_so_far)
				lowest_so_far = 3;
		}
		node = node->next;
	}
	return (lowest_so_far);
}

t_list	*get_split_point(t_list *tokens, int type)
{
	t_list	*node;
	t_token	*tok;
	int		parens;

	parens = 0;
	node = tokens;
	while (node)
	{
		tok = (t_token *)node->content;
		if (ft_strcmp(tok->str, "(") == 0)
			parens++;
		else if (ft_strcmp(tok->str, ")") == 0)
			parens--;
		else if (parens == 0)
		{
			if ((type == 1 && ft_strcmp(tok->str, "|") == 0)
				|| (type == 2 && ft_strcmp(tok->str, "&&") == 0)
				|| (type == 3 && ft_strcmp(tok->str, "||") == 0))
				return (node);
		}
		node = node->next;
	}
	return (NULL);
}

t_list	*get_tokens_right(t_list *split_point)
{
	t_list	*node;
	t_list	*right;
	t_token	*tok;

	right = NULL;
	node = split_point->next;
	while (node)
	{
		tok = (t_token *)node->content;
		ft_lstadd_back(&right, ft_lstnew(dup_token(tok)));
		node = node->next;
	}
	return (right);
}

t_list	*get_tokens_left(t_list *tokens, t_list *split_point)
{
	t_list	*node;
	t_list	*left;
	t_token	*tok;

	node = tokens;
	left = NULL;
	while (node && node != split_point)
	{
		tok = (t_token *)node->content;
		ft_lstadd_back(&left, ft_lstnew(dup_token(tok)));
		node = node->next;
	}
	return (left);
}

t_split_result	split_tokens(t_list *tokens, int type)
{
	t_split_result	result;
	t_list			*split_point;

	split_point = get_split_point(tokens, type);
	if (!split_point)
	{
		result.left = tokens;
		result.right = NULL;
		return (result);
	}
	result.left = get_tokens_left(tokens, split_point);
	result.right = get_tokens_right(split_point);
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
		else if (ft_strcmp(tok->str, ")") == 0)  // (echo a ) && echo b
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

	new = NULL;
	node = tokens->next;
	while (node->next)
	{
		dup = dup_token(node->content);
		if (!dup)
		{
			ft_lstclear(&new, free_token);
			return (NULL);
		}
		ft_lstadd_back(&new, ft_lstnew(dup));
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
	if (!tok1 || !tok2 || ft_strcmp(tok1->str, "(") != 0 || ft_strcmp(tok2->str, "(") != 0)   // ((eho c))
		return (0);
	node = tokens;
	while (node && node->next && node->next->next)
		node = node->next;
	before_last = node;
	if (!before_last || !before_last->next)
		return (0);
	tok1 = (t_token *)before_last->content;
	tok2 = (t_token *)before_last->next->content;
	if (!tok1 || !tok2 || ft_strcmp(tok1->str, ")") != 0 || ft_strcmp(tok2->str, ")") != 0)
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
		free_cmd_array(tree->cmd);
	if (tree->child1)
		cmdtree_clear(tree->child1);
	if (tree->child2)
		cmdtree_clear(tree->child2);
	free(tree);
}


int	cmdtree_expand(t_cmdtree *cmdtree)
{
	t_split_result	split;

	cmdtree->tokens = ft_lstremove_outer_parens(cmdtree->tokens);
	cmdtree->type = cmdtree_calc_type(cmdtree);
	if (cmdtree->type >= 1 && cmdtree->type <= 3)
	{
		split = split_tokens(cmdtree->tokens, cmdtree->type);
		cmdtree->child1 = cmdtree_new_node(split.left);
		cmdtree->child2 = cmdtree_new_node(split.right);
		if (!cmdtree->child1 || !cmdtree->child2)
			return (-1);
		cmdtree->child1->parent = cmdtree;
		cmdtree->child2->parent = cmdtree;
		if (cmdtree_expand(cmdtree->child1) == -1)
			return (-1);
		if (cmdtree_expand(cmdtree->child2) == -1)
			return (-1);
	}
	// type == 4
	return (0);
}