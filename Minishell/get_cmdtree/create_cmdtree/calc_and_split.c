/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_and_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myivanov <myivanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:31:25 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/12/02 10:55:14 by myivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../parse_line.h"

int	cmdtree_calc_type(t_cmdtree *cmdtree)
{
	t_token	*tok;
	t_list	*node;
	int		paren_level;
	int		type;

	paren_level = 0;
	type = 4;
	node = cmdtree->tokens;
	while (node)
	{
		tok = (t_token *)node->content;
		update_paren_level(tok->str, &paren_level);
		if (paren_level == 0)
			type = update_operator_type(tok->str, type);
		node = node->next;
	}
	if (type == 4 && ((t_token *)cmdtree->tokens->content)->control == 1)
	{
		if (has_outer_parens(cmdtree->tokens))
			return (0);
		if (has_level0_redir_outside_parens(cmdtree->tokens))
			return (0);
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
			if (type == 3 && ft_strcmp(tok->str, "|") == 0)
				return (node);
			if (type == 1 && ft_strcmp(tok->str, "&&") == 0)
				split = node;
			else if (type == 2 && ft_strcmp(tok->str, "||") == 0)
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
