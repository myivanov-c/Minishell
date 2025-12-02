/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myivanov <myivanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:31:25 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/12/02 10:56:52 by myivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../parse_line.h"

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
	node->fd_pipe = -1;
	node->exit_status = 0;
	node->parent = NULL;
	node->child1 = NULL;
	node->child2 = NULL;
	return (node);
}

int	has_level0_redir_outside_parens(t_list *tokens)
{
	t_list	*node;
	t_token	*tok;
	int		paren_level;

	paren_level = 0;
	node = tokens;
	while (node)
	{
		tok = node->content;
		update_paren_level(tok->str, &paren_level);
		if (paren_level == 0 && is_redirection_token(tok->str))
			return (1);
		node = node->next;
	}
	return (0);
}

int	update_operator_type(char *str, int type)
{
	if (ft_strcmp(str, "&&") == 0)
		return (1);
	if (ft_strcmp(str, "||") == 0)
		return (2);
	if (type == 4 && ft_strcmp(str, "|") == 0)
		return (3);
	return (type);
}
